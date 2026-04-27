#pragma once
#include <cstddef>
#include <Sequence.hpp>
#include <BitWithProxy.hpp>
#include <DynamcArray.hpp>
#include <LinkedList.hpp>
#include <Exceptions.hpp>

template <std::integral T_word = unsigned char>
class BitSequence : public Sequence<Bit<T_word>> {
protected:
    DynamicArray<Bit<T_word>>* bits;

    BitSequence() : bits(new DynamicArray<Bit<T_word>>(0)) {}
    BitSequence(Bit<T_word>* items, int count) 
        : bits(new DynamicArray<Bit<T_word>>(items, count)) {}
    BitSequence(const BitSequence& other) 
        : bits(new DynamicArray<Bit<T_word>>(*other.bits)) {}
    BitSequence(const LinkedList<Bit<T_word>>& list) 
        : bits(new DynamicArray<Bit<T_word>>(list.GetLength())) {
        for (int i = 0; i < list.GetLength(); i++) {
            bits->Set(i, list.Get(i));
        }
    }

    virtual ~BitSequence() { delete bits; }

    virtual BitSequence<T_word>* Clone() const = 0;
    virtual BitSequence<T_word>* Instance() = 0;
    virtual BitSequence<T_word>* CreateEmpty() const = 0;

public:
    Bit<T_word> GetFirst() const override;
    Bit<T_word> GetLast() const override;
    Bit<T_word> Get(int index) const override;
    int GetLength() const override;
    Sequence<Bit<T_word>>* GetSubsequence(int startIndex, int endIndex) const;


    Sequence<Bit<T_word>>* Append(Bit<T_word> item);
    Sequence<Bit<T_word>>* Prepend(Bit<T_word> item);
    Sequence<Bit<T_word>>* InsertAt(Bit<T_word> item, int index);
    Sequence<Bit<T_word>>* Concat(Sequence<Bit<T_word>>* otherSequence);



    Bit<T_word>& operator[](int index);
    const Bit<T_word>& operator[](int index) const;
    Sequence<Bit<T_word>>* operator&(const BitSequence& other) const;
    Sequence<Bit<T_word>>* operator|(const BitSequence& other) const;
    Sequence<Bit<T_word>>* operator^(const BitSequence& other) const;
    Sequence<Bit<T_word>>* operator~() const;
};


#include "BitSequenceGetMethodes.tpp"
#include "BitSequenceInsertMethode.tpp"
#include "BitSequenceOperators.tpp"