#pragma once
#include "Deque.h"

template <class T>
class Stack {
private:
    Deque<T> deque;

public:
    using value_type = T;

    Stack() : deque() {}

    Stack(T* items, int size) : deque(items, size) {}

    Stack(const Stack<T>& another) : deque(another.deque) {}

    ~Stack() {}

    void Push(const T& data) {
        deque.PushBack(data);
    }

    T Pop() {
        if (deque.Size() == 0) throw ErrorCode::EMPTY_CONTAINER;
        return deque.PopBack();
    }

    T Peek() {
        if (deque.Size() == 0) throw ErrorCode::EMPTY_CONTAINER;
        return deque.Back();
    }

    Stack<T>* Concat(const Stack<T>* other) const {
        Stack<T>* newStack = new Stack<T>();
        Deque<T>* temp = deque.Concat(&other->deque);
        newStack->deque = *temp;
        return newStack;
    }

    Stack<T>* GetSubsequence(int startIndex, int endIndex) const {
        Stack<T>* newStack = new Stack<T>();
        Deque<T>* temp = deque.GetSubsequence(startIndex, endIndex);
        newStack->deque = *temp;
        return newStack;
    }

    int Size() {
        return deque.Size();
    }

    bool Empty() {
        return deque.Empty();
    }

    bool operator==(const Stack<T>& other) const {
        return deque == other.deque;
    }

    bool operator!=(const Stack<T>& other) const {
        return !(*this == other);
    }

    T& operator[](int index) {
        return deque[index];
    }

    const T& operator[](int index) const {
        return deque[index];
    }
};