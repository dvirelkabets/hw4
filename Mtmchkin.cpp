#include "Mtmchkin.h"

void Mtmchkin::readFileToDeck (const std::string &fileName){
    std::ifstream file (fileName);
    if (!file){
        throw DeckFileNotFound();
    }
    std::string read;
    int fileLine = 1;
    while (std::getline(file,read)){
        if (m_cardMap.count(read)){
            m_cards.push_back(m_cardMap[read]());
        }
        else{
            throw DeckFileFormatError(fileLine);
        }
        fileLine++;
    }
    if (fileLine<=4){
        throw DeckFileInvalidSize();
    }
}

bool isDigit(std::string& word){
    for (char letter : word){
        if (!(std::isdigit(letter))){
            return false;
        }
    }
    return true;
}


int Mtmchkin::readPlayerNumber() const{
    std::string numberInput;
    int playersNum;
    printStartGameMessage();
    while(true){
        printEnterTeamSizeMessage();
        std::cin >> numberInput;
        if (isDigit(numberInput)){
            playersNum = std::stoi(numberInput);
            if (playersNum>=2 && playersNum<=6){
                break;
            }
        }
        printInvalidTeamSize();
    }
    return playersNum;
}

bool Mtmchkin::isValidPlayerName (std::string player){
    try{
        Ninja tmpPlayer(player);
        return true;
    }
    catch(...){
        printInvalidName();
        return false;
    }
}

bool Mtmchkin::assignJob (std::shared_ptr<Player>& player, std::string jobName, std::string playerName){
    if (!(isValidPlayerName(playerName))){
        return false;
    }
    if (m_playerMap.count(jobName)){
        player = m_playerMap[jobName](playerName);
    }
    else{
        printInvalidClass();
        return false;
    }
    return true;
}

int spacePosition(std::string& word){
    int count = 0;
    for (char letter : word){
        if (letter == ' '){
            return count;
        }
        count++;
    }
    return -1;
}

void Mtmchkin::readPlayer(std::shared_ptr<Player>& player){
    std::string input;
    std::string playerName;
    std::string jobName;
    bool flag = true;
    int position;
    while (flag){
        std::getline(std::cin, input);
        position = spacePosition(input);
        if (position<=0){
            std::cout << "maybe here " << position << input << std::endl;
            printInvalidName();
            continue;
        }
        playerName = input.substr(0,position);
        jobName = input.substr(position+1);
        if(assignJob(player, jobName, playerName)){
            flag = false;
        }
    }
}

void Mtmchkin::playNextCard(std::shared_ptr<Player>& player){
    m_index = (m_index+1)%(m_cards.size());
    std::shared_ptr<Card> currentCard = m_cards[m_index];
    currentCard->applyEncounter(*player);
}

/*
Mtmchkin c'tor - 
read the cards from the file and if there is a problem with one of the cards it throws exception.
after that read the players number
for every player read the name and class and making sure everything is legal.
set index to the size of the vector of cards - using it as cyclic group.
*/
Mtmchkin::Mtmchkin (const std::string &fileName){
    // ---------------reading from file -------------------------
    readFileToDeck(fileName);
    //-----------------reading players num-----------------------
    int playersNum = readPlayerNumber();
    std::cin.ignore(20, '\n');
    //----------------reading players----------------------------
    for (int i=0; i<playersNum;++i){
        printInsertPlayerMessage();
        std::shared_ptr<Player> player;
        readPlayer(player);
        m_players.push_back(player);
    }
    m_index=m_cards.size();
}

void Mtmchkin::playRound(){
    printRoundStartMessage(m_roundCounter);
    std::vector<std::vector<std::shared_ptr<Player>>::iterator> needtoRemove;
    std::vector<std::shared_ptr<Player>>::iterator index=m_players.begin();
    for (std::shared_ptr<Player> player : m_players) {
        printTurnStartMessage(player->getName());
        playNextCard(player);
        if (player->getLevel() == 10){
            m_winnerVector.push_back(player);
            needtoRemove.push_back(index);
        }
        if (player->isKnockedOut()){
            m_loserVector.push_back(player);
            needtoRemove.push_back(index);
        }
        index++;
    }
    for(std::vector<std::shared_ptr<Player>>::iterator position: needtoRemove){
        m_players.erase(position);
    }
    m_roundCounter++;
    if (isGameOver()){
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const{
    printLeaderBoardStartMessage();
    int i = 1;
    for (std::shared_ptr<Player> player : m_winnerVector){
        printPlayerLeaderBoard(i, *player);
        i++;
    }

    for (std::shared_ptr<Player> player : m_players){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    
    for (std::vector<std::shared_ptr<Player>>::const_reverse_iterator it = m_loserVector.crbegin(); it != m_loserVector.crend(); ++it){
        printPlayerLeaderBoard(i, *(*it));
        i++;
    }
}

bool Mtmchkin::isGameOver() const{
    if (m_players.empty()){
        return true;
    }
    return false;
}

 int Mtmchkin::getNumberOfRounds() const{
    return m_roundCounter;
 }