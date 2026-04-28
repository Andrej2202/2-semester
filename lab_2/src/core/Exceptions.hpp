#pragma once
#include <exception>
#include <string>

class IndexOutOfRangeException : public std::exception {
private:
    std::string message_;
public:
    IndexOutOfRangeException() : message_("Index out of range") {}
    IndexOutOfRangeException(const std::string& msg) : message_(msg) {}
    IndexOutOfRangeException(const std::string& container, const std::string& method, const std::string& issue) 
        : message_(std::format("Index out of range in {} in method {} \nissue: {}", container, method, issue)) {
            
        } //stringstream
    IndexOutOfRangeException(const char* msg) : message_(msg ? msg : "Unknown index error") {}

    const char* what() const noexcept override {return message_.c_str();}
};

class InvalidArgumentException : public std::exception {
private:
    std::string message_;
public:
    InvalidArgumentException() : message_("Invalid argument") {}
    InvalidArgumentException(const std::string& msg) : message_(msg) {}
    InvalidArgumentException(const std::string& container, const std::string& method, const std::string& issue) 
        : message_(std::format("Invalid argument in {} in method {} \nissue: {}", container, method, issue)) {}
    InvalidArgumentException(const char* msg) : message_(msg ? msg : "Unknown invalid argument") {}

    const char* what() const noexcept override {return message_.c_str();}
};