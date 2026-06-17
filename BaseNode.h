#pragma once


template <typename T>
class BaseNode {
protected:
    T data;

public:
    BaseNode(T value);
    virtual ~BaseNode();

    virtual void printInfo() const = 0;

    T getData() const;
    void setData(T value);
};

#include "BaseNode.tpp"
