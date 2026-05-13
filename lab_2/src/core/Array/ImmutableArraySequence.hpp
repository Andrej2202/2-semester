#pragma once
#include "ArraySequence.hpp"
#include <SuperUniquePointer.hpp>

template<class T>
class ImmutableArraySequence : public ArraySequence<T> {
public:
    using ArraySequence<T>::ArraySequence;

    SuperUniquePointer<Sequence<T>> Clone() const override {
        return makeUnique<ImmutableArraySequence<T>>(this);
    }
    
    Sequence<T>* Instance() override { 
        return this->Clone();
    }

    Sequence<T>* CreateEmpty() const override { 
        return new ImmutableArraySequence<T>(); 
    }
};