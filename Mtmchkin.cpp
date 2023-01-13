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
        std::cout << "maybe here" << std::endl;
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

void Mtmchkin::readPlayer(std::shared_ptr<Player>& player){
    std::string input;
    std::string playerName;
    std::string jobName;
    bool flag = true;
    int position;
    std::cin >>input;
    while (flag){
        std::getline(std::cin,input);
        position = input.find(" ");
        if (position<=0){
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
    for (std::shared_ptr<Player> player : m_players) {
        if (player->isKnockedOut() || player->getLevel() == 10) {
            continue;
        }
        printTurnStartMessage(player->getName());
        playNextCard(player);
        if (player->getLevel() == 10){
            m_winnerVector.push_back(player);
        }
        if (player->isKnockedOut()){
            m_loserVector.push_back(player);
        }
    }
    m_roundCounter++;
    if (isGameOver()){
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const{
    if (m_winnerVector.empty() && m_loserVector.empty()){
        return;
    }
    std::vector<std::shared_ptr<Player>> leaderBoard;
    printLeaderBoardStartMessage();
    for (std::shared_ptr<Player> player : m_winnerVector){
        leaderBoard.push_back(player);
    }
    for (std::vector<std::shared_ptr<Player>>::const_reverse_iterator it = m_loserVector.crbegin(); it != m_loserVector.crend(); ++it){
        leaderBoard.push_back(*it);
    }
    int i = 1;
    for (std::shared_ptr<Player> player : leaderBoard){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
}

bool Mtmchkin::isGameOver() const{
    if (m_players.size() == m_loserVector.size() + m_winnerVector.size()){
        return true;
    }
    return false;
}

 int Mtmchkin::getNumberOfRounds() const{
    return m_roundCounter;
 }