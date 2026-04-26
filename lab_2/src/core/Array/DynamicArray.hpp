#pragma once
#include <Exceptions.hpp>
#include <Config.hpp>

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
