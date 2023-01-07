#ifndef EX4_Exception
#define EX4_Exception
#include <iostream>
#include <exception>
#include <string>

class DeckFileNotFound : public std::exception{
    public:
    explicit DeckFileNotFound() = default;
       const char * what() const noexcept override {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception{
    int m_line;
    std::string m_card;
    public:
    explicit DeckFileFormatError(const int line, const std::string card): m_line(line), m_card(card){};
       const char * what() const noexcept override {
        std::string error = "Deck File Error: File format error in line " + std::to_string(m_line) + m_card;
        const char * toSend = error.c_str();
        return toSend;
    }
};

class DeckFileInvalidSize : public std::exception{
    public:
    explicit DeckFileInvalidSize() = default;
    const char * what() const noexcept override {
        return "Deck File Error: Deck size is invalid";
    }
};

#endif // EX4_Exception