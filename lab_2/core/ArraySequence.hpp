#pragma once

template <class T> 
class ArraySequence : public Sequence<T> { 
private:
    void AppendInternal(T item);
    void PrependInternal(T item);
    void InsertAtInternal(T item);

protected:
    DynamicArray<T>* data_;

    virtual ArraySequence<T>* Clone() const = 0;
    virtual Sequence<T>* Instance() = 0;

public:
    ArraySequence() : data_(new DynamicArray<T>(0)) {}
    explicit ArraySequence(T* items, int count);
    explicit ArraySequence(const LinkedList <T> & list);
    explicit ArraySequence(const ArraySequence<T> & list);
    virtual ~ArraySequence(){delete data;}

    T GetFirst(){return data_.Get(0);}
    T GetLast(){return data_.Get(data_.GetLength() - 1);}
    T Get(int index){return data_.Get(index)}
    int GetLength(){return data_.GetSize()}
    ArraySequence<T>* GetSubList(int startIndex, int endIndex);


    //нуно Mutable/imutable
    Sequence<T>* Append(T item);
    Sequence<T>* Prepend(T item);
    Sequence<T>* InsertAt(T item, int index);



    LinkedList<T>* Concat(LinkedList<T> *list);
    
    
};

#include "ArraySequenceConstructors.tpp"
#include "ArraySequenceGetMethodes.tpp"
#include "ArraySequenceInsertMethodes.tpp"