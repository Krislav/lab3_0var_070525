#pragma once
#include "Errors.h"
#include "DynamicArray.h"
#include "Sequence.h"
#include <iostream>

template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* items;
    int size;
    int capacity;
public:
    ArraySequence(const T* items, int count) {
        if (count < 0) throw(ErrorCode::NEGATIVE_QUANTITY);
        capacity = (count > 0) ? (2 * count) : 0;
        this->items = new DynamicArray<T>(capacity);
        size = count;
        for (int i = 0; i < size; i++) {
            this->items->Set(i, items[i]);
        }
    }

    ArraySequence() {
        capacity = 0;
        size = 0;
        items = new DynamicArray<T>(capacity);
    }

    ArraySequence (const ArraySequence<T>& other) {
        items = new DynamicArray<T>(other.capacity);
        size = other.size;
        capacity = other.capacity;
        for (int i = 0; i < size; i++) {
            items->Set(i, other[i]);
        }
    }

    virtual ~ArraySequence() {
        delete items;
    }

    virtual T GetFirst() const override {
        return items->Get(0);
    }

    virtual T GetLast() const override {
        return items->Get(size - 1);
    }

    virtual T Get(int index) const override {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        return items->Get(index);
    }

    virtual int GetLength() const override {
        return size;
    }

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || endIndex >= size || startIndex > endIndex) throw(ErrorCode::INDEX_OUT_OF_RANGE);
    
        int count = endIndex - startIndex + 1;
        T* sub_items = new T[count];
        for (int i = 0; i < count; ++i) {
            sub_items[i] = items->Get(startIndex + i);
        }
    
        ArraySequence<T>* res =  new ArraySequence<T>(sub_items, count);
        delete[] sub_items;
        return res;
    }

    virtual Sequence<T>* Append(const T& item) override {
        if (capacity == size) {
            capacity = capacity > 0 ? (2 * capacity) : 1;
            items->Resize(capacity);
        }
        items->Set(size, item);
        size++;
        return this;
    }

    virtual Sequence<T>* Prepend(const T& item) override {
        if (capacity == size) {
            capacity = capacity > 0 ? (2 * capacity) : 1;
            items->Resize(capacity);
        }
        size++;
        for (int i = size - 1; i > 0; i--) {
            items->Set(i, items->Get(i - 1));
        }
        items->Set(0, item);
        return this;
    }

    virtual Sequence<T>* InsertAt(const T& item, int index) override {
        if (index < 0 || index > size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        if (capacity == size) {
            capacity = capacity > 0 ? (2 * capacity) : 1;
            items->Resize(capacity);
        }
        size++;
        for (int i = size - 1; i > index; i--) {
            items->Set(i, items->Get(i - 1));
        }
        items->Set(index, item);
        return this;
    }

    virtual Sequence<T>* Delete(int index) override {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        items->Delete(index);
        size--;
        return this;
    }

    virtual Sequence<T>* Concat(const Sequence<T>* list) const override {
        ArraySequence<T>* new_items = new ArraySequence<T>(*this);
        if (!list || list->GetLength() == 0) return new_items;
        for (int i = 0; i < list->GetLength(); i++) {
            new_items->Append(list->Get(i));
        }
        return new_items;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        return (*items)[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        return (*items)[index];
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
        for (int i = 0; i < size; i++) {
            os << items->Get(i);
            if (i != size - 1) os << ", ";
        }
        os << "]";
    }
};