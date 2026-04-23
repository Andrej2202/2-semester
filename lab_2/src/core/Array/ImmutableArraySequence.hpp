#pragma once
#include "ArraySequence.hpp"

template<class T>
class ImmutableArraySequence : public ArraySequence<T> {
public:
    using ArraySequence<T>::ArraySequence;

    ArraySequence<T>* Clone() const override {
        return new ImmutableArraySequence<T>(*this);
    }
    
    Sequence<T>* Instance() override { 
        return this->Clone();
    }
};