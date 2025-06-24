#pragma once
#include "Deque.h"

template <class T>
class Queue {
private:
    Deque<T> deque;

public:
    using value_type = T;

    Queue() : deque() {}

    Queue(T* items, int size) : deque(items, size) {}

    Queue(const Queue<T>& another) : deque(another.deque) {}

    ~Queue() {}

    void Push(const T& data) {
        deque.PushBack(data);
    }

    T Pop() {
        if (deque.Size() == 0) throw ErrorCode::EMPTY_CONTAINER;
        return deque.PopFront();
    }

    T Peek() {
        if (deque.Size() == 0) throw ErrorCode::EMPTY_CONTAINER;
        return deque.Front();
    }

    Queue<T>* Concat(const Queue<T>* other) const {
        Queue<T>* newQueue = new Queue<T>();
        Deque<T>* temp = deque.Concat(&other->deque);
        newQueue->deque = *temp;
        return newQueue;
    }

    Queue<T>* GetSubsequence(int startIndex, int endIndex) const {
        Queue<T>* newQueue = new Queue<T>();
        Deque<T>* temp = deque.GetSubsequence(startIndex, endIndex);
        newQueue->deque = *temp;
        return newQueue;
    }

    int Size() {
        return deque.Size();
    }

    bool Empty() {
        return deque.Empty();
    }

    bool operator==(const Queue<T>& other) const {
        return deque == other.deque;
    }

    bool operator!=(const Queue<T>& other) const {
        return !(*this == other);
    }

    T& operator[](int index) {
        return deque[index];
    }

    const T& operator[](int index) const {
        return deque[index];
    }
};