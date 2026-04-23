#pragma once
#include <Exceptions.hpp>
constexpr int MAX_ARR_SIZE = 100000;

template <class T>
class DynamicArray{
private:
    T* data_;
    int size_;
public:
    DynamicArray(int size);
    DynamicArray(T* items, int count);
    DynamicArray(const DynamicArray<T>& other);
    ~DynamicArray(){delete[] data_;}
    
    T Get(int index);
    int GetSize(){return size_;}

    void Set(int index, T value); 
    void Resize(int newSize);
};

#include "DynamicArray.tpp"
