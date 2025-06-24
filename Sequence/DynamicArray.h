#pragma once
#include "Errors.h"

template <class T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    DynamicArray(){
        this->size = 0;
        data = new T[0];
        if (data == nullptr) throw(ErrorCode::MEMORY_ALLOCATION_FAILED);
    }

    DynamicArray(const T* items, int count){
        if (count < 0) throw(ErrorCode::NEGATIVE_QUANTITY);
        size = count;
        data = new T[count];
        if (data == nullptr) throw(ErrorCode::MEMORY_ALLOCATION_FAILED);
        for (int i = 0; i < count; i++){
            data[i] = items[i];
        }
    }

    DynamicArray(int size){
        if (size < 0) throw(ErrorCode::NEGATIVE_QUANTITY);
        this->size = size;
        data = new T[size];
        if (data == nullptr) throw(ErrorCode::MEMORY_ALLOCATION_FAILED);
        for (int i = 0; i < size; i++) {
            data[i] = T();
        }
    }

    DynamicArray(const DynamicArray<T>& another) {
        this->size = another.size;
        data = new T[size];
        if (data == nullptr) throw(ErrorCode::MEMORY_ALLOCATION_FAILED);
        for (int i = 0; i < size; i++) {
            this->data[i] = another.data[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    T Get(int index) {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        return data[index];
    }

    int GetSize() {
        return size;
    }

    void Set(int index, const T& value) {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        data[index] = value;
    }

    void Resize(int new_size) {
        if (new_size < 0) throw(ErrorCode::NEGATIVE_QUANTITY);
        T* new_data = new T[new_size];
        if (new_data == nullptr) throw(ErrorCode::MEMORY_ALLOCATION_FAILED);
        int min_size = (new_size < size) ? new_size : size;
        for (int i = 0; i < min_size; i++) {
            new_data[i] = data[i];
        }
        for (int i = min_size; i < new_size; i++) {
            new_data[i] = T();
        }

        delete[] data;
        data = new_data;
        size = new_size;
    }

    void Delete(int index) {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        T* new_data = new T[size - 1];
        for (int i = 0; i < index; i++) {
            new_data[i] = data[i];
        }
        for (int i = index + 1; i < size; i++){
            new_data[i - 1] = data[i];
        }
        delete[] data;
        data = new_data;
        size--;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        return data[index];
    }

    bool operator==(const DynamicArray<T>& other) const {
        if (size != other.size) return false;
        
        for (int i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        
        return true;
    }

    bool operator!=(const DynamicArray<T>& other) const {
        return !(*this == other);
    }
};