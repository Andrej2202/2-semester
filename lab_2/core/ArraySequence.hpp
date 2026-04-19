#pragma once

template <class T> 
class ArraySequence : public Sequence<T> { 
private:
    DynamicArray<T>* item_;
    size_t head_;
    size_t tail_;
    size_t buffer_length_;
    size_t phys_index(size_t logic_index){
        return (logic_index + head_) % buffer_length_;
    }
public:
    T GetFirst() const override{
        return item_[index_first_]
    }
    T GetLast(){return item_[index_last_]}
    T Get(int index) = 0;
    int GetSize() = 0;
    T SetSize() = 0;
    int GetLength() = 0;
};

#include "ArraySequence.tpp"