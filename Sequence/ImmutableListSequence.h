#pragma once
#include "Errors.h"
#include "ListSequence.h"

template <class T>
class ImmutableListSequence : public ListSequence<T> {
public:
    ImmutableListSequence() : ListSequence<T>() {}

    ImmutableListSequence(T* items, int count) : ListSequence<T>(items, count) {}

    ImmutableListSequence(const ImmutableListSequence<T>& other) : ListSequence<T>(other) {}

    virtual ~ImmutableListSequence() {}

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || endIndex >= this->GetLength() || startIndex > endIndex) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        ImmutableListSequence<T>* result = new ImmutableListSequence<T>();
        for (int i = startIndex; i <= endIndex; i++) {
            result->ListSequence<T>::Append(this->Get(i));
        }
        return result;
    }

    virtual Sequence<T>* Append(const T& item) override {
        ImmutableListSequence<T>* new_list = new ImmutableListSequence<T>(*this);
        new_list->ListSequence<T>::Append(item);
        return new_list;
    }

    virtual Sequence<T>* Prepend(const T& item) override {
        ImmutableListSequence<T>* new_list = new ImmutableListSequence<T>(*this);
        new_list->ListSequence<T>::Prepend(item);
        return new_list;
    }

    virtual Sequence<T>* InsertAt(const T& item, int index) {
        ImmutableListSequence<T>* new_list = new ImmutableListSequence<T>(*this);
        new_list->ListSequence<T>::InsertAt(item, index);
        return new_list;
    }

    virtual Sequence<T>* Delete(int index) override {
        ImmutableListSequence<T>* new_list = new ImmutableListSequence<T>(*this);
        new_list->ListSequence<T>::Delete(index);
        return new_list;
    }

    virtual Sequence<T>* Concat(const Sequence<T>* other) const override {
        ImmutableListSequence<T>* new_list = new ImmutableListSequence<T>(*this);
        for (int i = 0; i < other->GetLength(); i++) {
            new_list->ListSequence<T>::Append(other->Get(i));
        }
        return new_list;
    }
};