

#pragma once
#include "ArraySequence.hpp"
#include <SuperUniquePointer.hpp>

template<class T>
class MutableArraySequence : public ArraySequence<T> {
public:
    using ArraySequence<T>::ArraySequence;

    SuperUniquePointer<Sequence<T>> Clone() const override {
        return makeUnique<MutableArraySequence<T>>(this);
    }
    
    Sequence<T>* Instance() override { 
        return this;
    }

    Sequence<T>* CreateEmpty() const override { 
        return new MutableArraySequence<T>(); 
    }
};