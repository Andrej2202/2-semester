#pragma once
#include <cstddef>
#include <Sequence.hpp>
#include <BitWithProxy.hpp>
#include <DynamcArray.hpp>
#include <LinkedList.hpp>
#include <Exceptions.hpp>
#include <concepts>

template <std::integral T_word = unsigned char>
class BitSequence : public Sequence<Bit<T_word>> {
protected:
    DynamicArray<Bit<T_word>>* bits;

    BitSequence() : bits(new DynamicArray<Bit<T_word>>(0)) {}
    BitSequence(Bit<T_word>* items, size_t count) 
        : bits(new DynamicArray<Bit<T_word>>(items, count)) {}
    BitSequence(const BitSequence& other) 
        : bits(new DynamicArray<Bit<T_word>>(*other.bits)) {}
    BitSequence(const LinkedList<Bit<T_word>>& list) 
        : bits(new DynamicArray<Bit<T_word>>(list.GetLength())) {
        for (size_t i = 0; i < list.GetLength(); i++) {
            bits->Set(i, list.Get(i));
        }
    }

    ~BitSequence() { delete bits; }

    virtual BitSequence<T_word>* Clone() const = 0;
    virtual BitSequence<T_word>* Instance() = 0;
    virtual BitSequence<T_word>* CreateEmpty() const = 0;

public:
    Bit<T_word> GetFirst() const override;
    Bit<T_word> GetLast() const override;
    Bit<T_word> Get(size_t index) const override;
    size_t GetLength() const override;
    Sequence<Bit<T_word>>* GetSubsequence(size_t startIndex, size_t endIndex) const;


    Sequence<Bit<T_word>>* Append(Bit<T_word> item);
    Sequence<Bit<T_word>>* Prepend(Bit<T_word> item);
    Sequence<Bit<T_word>>* InsertAt(Bit<T_word> item, size_t index);
    Sequence<Bit<T_word>>* Concat(Sequence<Bit<T_word>>* otherSequence);



    Bit<T_word>& operator[](size_t index);
    const Bit<T_word>& operator[](size_t index) const;
    Sequence<Bit<T_word>>* operator&(const BitSequence& other) const;
    Sequence<Bit<T_word>>* operator|(const BitSequence& other) const;
    Sequence<Bit<T_word>>* operator^(const BitSequence& other) const; // хорош
    Sequence<Bit<T_word>>* operator~() const;
};


#include "BitSequence.tpp"