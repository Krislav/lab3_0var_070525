#pragma once
#include "Errors.h"
#include <iostream>

template <class T>
class Sequence{
public:
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual int GetLength() const = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;

    virtual Sequence<T>* Append(const T&item) = 0;
    virtual Sequence<T>* Prepend(const T& item) = 0;
    virtual Sequence<T>* InsertAt(const T& item, int index) = 0;
    virtual Sequence<T>* Delete(int index) = 0;
    virtual Sequence<T>* Concat(const Sequence<T>* list) const = 0;

    virtual bool operator==(const Sequence<T>& other) const = 0;
    virtual bool operator!=(const Sequence<T>& other) const = 0;
    virtual void Print(std::ostream& os) const = 0;

    virtual ~Sequence() {}
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Sequence<T>& seq) {
    seq.Print(os);
    return os;
}