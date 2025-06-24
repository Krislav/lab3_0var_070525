#pragma once
#include "Errors.h"
#include "LinkedList.h"
#include "Sequence.h"

template <class T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T>* list;

public:
    ListSequence() {
        list = new LinkedList<T>();
    }

    ListSequence(const T* items, int count) {
        list = new LinkedList<T>(items, count);
    }

    ListSequence (const ListSequence<T>& other) {
        list = new LinkedList<T>(*other.list);
    }

    virtual ~ListSequence() {
        delete list;
    }

    virtual T GetFirst() const override {
        return list->GetFirst();
    }

    virtual T GetLast() const override {
        return list->GetLast();
    }

    virtual T Get(int index) const override {
        return list->Get(index);
    }

    virtual int GetLength() const override {
        return list->GetLength();
    }

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
        LinkedList<T>* new_list = list->GetSubList(startIndex, endIndex);
        ListSequence<T>* res = new ListSequence<T>();
        res->list = new_list;
        return res;
    }

    virtual Sequence<T>* Append(const T& item) override {
        list->Append(item);
        return this;
    }

    virtual Sequence<T>* Prepend(const T& item) override {
        list->Prepend(item);
        return this;
    }

    virtual Sequence<T>* InsertAt(const T& item, int index) {
        list->InsertAt(item, index);
        return this;
    }

    virtual Sequence<T>* Delete(int index) override {
        list->Delete(index);
        return this;
    }
    
    virtual Sequence<T>* Concat(const Sequence<T>* list) const override {
        ListSequence<T>* res = new ListSequence<T>(*this);
        for (int i = 0; i < list->GetLength(); i++) {
            res->Append(list->Get(i));
        }
        return res;
    }

    T& operator[](int index) {
        return (*list)[index];
    }

    const T& operator[](int index) const {
        return (*list)[index];
    }

    bool operator==(const Sequence<T>& other) const override {
        if (this == &other) return true;
        if (GetLength() != other.GetLength()) return false;
    
        for (int i = 0; i < GetLength(); ++i) {
            if (Get(i) != other.Get(i)) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Sequence<T>& other) const override {
        return !(*this == other);
    }

    virtual void Print(std::ostream& os) const override {
        os << "[";
        for (int i = 0; i < list->GetLength(); ++i) {
            os << list->Get(i);
            if (i != list->GetLength() - 1) os << ", ";
        }
        os << "]";
    }
};