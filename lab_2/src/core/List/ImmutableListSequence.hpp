#pragma once
#include "ListSequence.hpp"

template<class T>
class ImmutableListSequence : public ListSequence<T> {
public:
    using ListSequence<T>::ListSequence;

    ListSequence<T>* Clone() const override {
        return new ImmutableListSequence<T>(*this);
    }
    
    Sequence<T>* Instance() override { 
        return this->Clone();
    }

    Sequence<T>* CreateEmpty() const override { 
        return new ImmutableListSequence<T>(); 
    }
};