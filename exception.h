#pragma once
#include <exception>
#include "my_string.h"
#include "my_vector.h"

#ifndef EXCEPTION_H
#define EXCEPTION_H
using namespace std;
using namespace my_string;
using namespace my_vector;

namespace my_string {

struct my_base_exception : std::exception {

    string errorMessage;

    my_base_exception()
    {
        errorMessage = "exception: ";
    }
    my_base_exception(const char* message) : errorMessage("my_base_exception")
    {
        errorMessage += message;
    }

    const char* what() const noexcept
    {
        return errorMessage.c_str();
    }
};

struct NullPointerException : std::exception {
    const char* what() const noexcept {return "NullPointerException\n";}
};

struct NegativeArgumentException : std::exception {
    const char* what() const noexcept {return "NegativeArgumentException\n";}
};

struct InvalidArgumentException : std::exception {
    const char* what() const noexcept {return "InvalidArgumentException\n";}
};

struct NotCorrectLenthSubStringException : std::exception {
    const char* what() const noexcept {return "NotCorrectLenthSubStringException\n";}
};

struct NotPositionInStringException : std::exception {
    const char* what() const noexcept {return "NotPositionInStringException\n";}
};

struct WrongArgumentException : std::exception {
    const char* what() const noexcept {return "WrongArgumentException\n";}
};

}

namespace my_vector
{
    struct my_base_exception : std::exception {

    string errorMessage;

    my_base_exception()
    {
        errorMessage = "exception: ";
    }
    my_base_exception(const char* message) : errorMessage("my_base_exception")
    {
        errorMessage += message;
    }

    const char* what() const noexcept
    {
        return errorMessage.c_str();
    }
};
struct ListIsEmpty : std::exception {
    const char* what() const noexcept {return "ListIsEmpty\n";}
};
struct ListDoesntExist : std::exception {
    const char* what() const noexcept {return "ListDoesntExist\n";}
};
struct InvalidArgumentException : std::exception {
    const char* what() const noexcept {return "InvalidArgumentException\n";}
};
}

namespace my_array
{
    struct my_base_exception : std::exception {

    string errorMessage;

    my_base_exception()
    {
        errorMessage = "exception: ";
    }
    my_base_exception(const char* message) : errorMessage("my_base_exception")
    {
        errorMessage += message;
    }

    const char* what() const noexcept
    {
        return errorMessage.c_str();
    }
};
struct ArrayIsEmptyException : std::exception {
    const char* what() const noexcept {return "ArrayIsEmptyException\n";}
};
struct ArrayDoesntExist : std::exception {
    const char* what() const noexcept {return "ArrayDoesntExist\n";}
};
struct InvalidArgumentException : std::exception {
    const char* what() const noexcept {return "InvalidArgumentException\n";}
};
}
#endif // EXCEPTION_H