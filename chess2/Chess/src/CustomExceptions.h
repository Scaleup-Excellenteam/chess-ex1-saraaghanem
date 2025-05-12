
#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidMoveException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid move attempted";
    }
};

class PromotionChoiceException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid promotion choice";
    }
};

#endif // CUSTOM_EXCEPTIONS_H
