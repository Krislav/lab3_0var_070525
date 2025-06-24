#pragma once
#include "Sequence\ListSequence.h"

template <class T>
class Deque {
private:
    ListSequence<T>* list;

public:
    using value_type = T;

    Deque() {
        list = new ListSequence<T>();
    }

    Deque(T* items, int size) {
        list = new ListSequence<T>(items, size);
    }

    Deque(const Deque<T>& another) {
        list = new ListSequence<T>(*another.list);
    }

    ~Deque() {
        delete list;
    }

    void PushFront(const T& data) {
        list->Prepend(data);
    }

    void PushBack(const T& data) {
        list->Append(data);
    }

    T PopFront() {
        if (list->GetLength() == 0) throw ErrorCode::EMPTY_CONTAINER;
        T front = list->GetFirst();
        list->Delete(0);
        return front;
    }

    T PopBack() {
        if (list->GetLength() == 0) throw ErrorCode::EMPTY_CONTAINER;
        T back = list->GetLast();
        list->Delete(list->GetLength() - 1);
        return back;
    }

    T Front() {
        if (list->GetLength() == 0) throw ErrorCode::EMPTY_CONTAINER;
        return list->GetFirst();
    }

    T Back() {
        if (list->GetLength() == 0) throw ErrorCode::EMPTY_CONTAINER;
        return list->GetLast();
    }

    Deque<T>* Concat(const Deque<T>* other) const {
        ListSequence<T>* newList = dynamic_cast<ListSequence<T>*>(list->Concat(other->list));
        Deque<T>* result = new Deque<T>();
        result->list = newList;
        return result;
    }

    Deque<T>* GetSubsequence(int startIndex, int endIndex) const {
        ListSequence<T>* subList = dynamic_cast<ListSequence<T>*>(list->GetSubsequence(startIndex, endIndex));
        Deque<T>* result = new Deque<T>();
        result->list = subList;
        return result;
    }

    int Size() {
        return list->GetLength();
    }

    bool Empty() {
        return list->GetLength() == 0;
    }

    T& operator[](int index) {
        return (*list)[index];
    }

    const T& operator[](int index) const {
        return (*list)[index];
    }

    bool operator==(const Deque<T>& other) const {
        return *list == *other.list;
    }

    bool operator!=(const Deque<T>& other) const {
        return !(*this == other);
    }
};