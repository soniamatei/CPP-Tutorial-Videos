#ifndef A8_9_914_MATEI_SONIA_EXCEPTIONS_H
#define A8_9_914_MATEI_SONIA_EXCEPTIONS_H

#include <exception>
#include <iostream>

class RemoveError : public std::exception {

private:
    std::string message;

public:
    RemoveError(const std::string& message) : message(message) {}

    std::string& getMessage() { return message;}
};

class UpdateError : public std::exception {

private:
    std::string message;

public:
    UpdateError(const std::string& message) : message(message) {}

    std::string& getMessage() { return message;}
};

class AddError : public std::exception {

private:
    std::string message;

public:
    AddError(const std::string& message) : message(message) {}

    std::string& getMessage() { return message;}
};

class SearchError : public std::exception {

private:
    std::string message;

public:
    SearchError(const std::string& message) : message(message) {}

    std::string& getMessage() { return message;}
};

class ValidatorError : public std::exception {

private:
    std::string message;

public:
    ValidatorError(const std::string& message) : message(message) {}

    std::string& getMessage() { return message;}
};

class RepoError : public std::exception {

private:
    std::string message;

public:
    RepoError(const std::string& message) : message(message) {}

    std::string& getMessage() { return message;}
};

class MsgError : public std::exception {

private:
    std::string message;

public:
    MsgError(const std::string& message) : message(message) {}

    std::string& getMessage() { return message;}
};
#endif //A8_9_914_MATEI_SONIA_EXCEPTIONS_H
