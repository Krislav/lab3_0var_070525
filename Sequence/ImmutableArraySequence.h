#pragma once
#include "Errors.h"
#include "ArraySequence.h"

template <class T>
class ImmutableArraySequence : public ArraySequence<T> {
public:
    ImmutableArraySequence() : ArraySequence<T>() {}

    ImmutableArraySequence(T* items, int count) : ArraySequence<T>(items, count) {}

    ImmutableArraySequence(const ImmutableArraySequence<T>& other) : ArraySequence<T>(other) {}

    virtual ~ImmutableArraySequence() {}

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || endIndex >= this->GetLength() || startIndex > endIndex) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        ImmutableArraySequence<T>* result = new ImmutableArraySequence<T>();
        for (int i = startIndex; i <= endIndex; i++) {
            result->ArraySequence<T>::Append(this->Get(i));
        }
        return result;
    }

    virtual Sequence<T>* Append(const T& item) override {
        ImmutableArraySequence<T>* new_seq = new ImmutableArraySequence<T>(*this);
        new_seq->ArraySequence<T>::Append(item);
        return new_seq;
    }

    virtual Sequence<T>* Prepend(const T& item) override {
        ImmutableArraySequence<T>* new_seq = new ImmutableArraySequence<T>(*this);
        new_seq->ArraySequence<T>::Prepend(item);
        return new_seq;
    }

    virtual Sequence<T>* InsertAt(const T& item, int index) override {
        ImmutableArraySequence<T>* new_seq = new ImmutableArraySequence<T>(*this);
        new_seq->ArraySequence<T>::InsertAt(item, index);
        return new_seq;
    }

    virtual Sequence<T>* Delete(int index) override {
        ImmutableArraySequence<T>* new_list = new ImmutableArraySequence<T>(*this);
        new_list->ArraySequence<T>::Delete(index);
        return new_list;
    }

    virtual Sequence<T>* Concat(const Sequence<T>* other) const override {
        ImmutableArraySequence<T>* new_list = new ImmutableArraySequence<T>(*this);
        for (int i = 0; i < other->GetLength(); i++) {
            new_list->ArraySequence<T>::Append(other->Get(i));
        }
        return new_list;
    }
};