#include "TreeException.h"

TreeException::TreeException(const string &message) : message(message)
{
}

const char *TreeException::what() const noexcept
{
    return message.c_str();
}