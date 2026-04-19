#pragma once
#include "Exceptions.hpp"

template <class T>
class DynamicArray{
private:
    T* data_;
    int size_;
public:
    DynamicArray(int size);
    DynamicArray(T* items, int count);
    DynamicArray(DynamicArray<T> & dynamicArray const);
    ~DynamicArray(){delete data_};

    T Get(int index){return data_[i];}
    int GetSize(){return size_;}

    void Set(int index, T value); 
    void Resize(int newSize);
}



#include "DynamicArray.tpp"
