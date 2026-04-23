#pragma once
#include <exception>
#include <string>

class IndexOutOfRangeException : public std::exception {
private:
    std::string message;
public:
    IndexOutOfRangeException() : message("Index out of range") {}
    IndexOutOfRangeException(const std::string& msg) : message(msg) {}
    IndexOutOfRangeException(const char* msg) : message(msg ? msg : "Unknown index error") {}

    const char* what() const noexcept override {return message.c_str();}
};

class InvalidArgumentException : public std::exception {
private:
    std::string message;
public:
    InvalidArgumentException() : message("Invalid argument") {}
    InvalidArgumentException(const std::string& msg) : message(msg) {}
    InvalidArgumentException(const char* msg) : message(msg ? msg : "Unknown invalid argument") {}

    const char* what() const noexcept override {return message.c_str();}
};