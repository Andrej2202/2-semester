#pragma once
#include "Sequence.hpp"
#include "DynamicArray.hpp"
#include <Exceptions.hpp>

template<typename T> class LinkedList; 


template <class T> 
class ArraySequence : public Sequence<T> { 
private:
    void AppendInternal(T item);
    void PrependInternal(T item);
    void InsertAtInternal(T item, int index);
    void ConcatInternal(Sequence<T>* smth);

protected:
    DynamicArray<T>* data_;

    virtual ArraySequence<T>* Clone() const = 0;
    virtual Sequence<T>* Instance() = 0;

public:
    ArraySequence() : data_(new DynamicArray<T>(0)) {}
    explicit ArraySequence(T* items, int count);
    explicit ArraySequence(const LinkedList <T> & list);
    explicit ArraySequence(const ArraySequence<T> & array);
    virtual ~ArraySequence(){delete data_;}

    T GetFirst() const override { return data_->Get(0); }
    T GetLast() const override { return data_->Get(data_->GetSize() - 1); }
    T Get(int index) const override { return data_->Get(index); }
    int GetLength() const override { return data_->GetSize(); }
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override;


    //нуно Mutable/imutable
    Sequence<T>* Append(T item) override;
    Sequence<T>* Prepend(T item) override;
    Sequence<T>* InsertAt(T item, int index) override;
    Sequence<T>* Concat(Sequence<T>* list) override;
};


#include "ArraySequenceConstructors.tpp"
#include "ArraySequenceGetMethodes.tpp"
#include "ArraySequenceInsertMethodes.tpp"

