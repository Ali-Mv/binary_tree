#pragma once
#include <exception>
#include <string>

using namespace std;

class TreeException : public exception
{
protected:
    string message;

public:
    TreeException(const string& message = "");
    const char *what() const noexcept override;
};