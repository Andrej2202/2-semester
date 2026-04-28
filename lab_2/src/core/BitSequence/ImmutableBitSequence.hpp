#pragma once
#include <concepts>

template <std::integral T_word = unsigned char>
class ImmutableBitSequence : public BitSequence<T_word> {
public:
    ImmutableBitSequence() : BitSequence<T_word>() {}
    ImmutableBitSequence(Bit<T_word>* items, size_t count) : BitSequence<T_word>(items, count) {}
    ImmutableBitSequence(const BitSequence<T_word>& other) : BitSequence<T_word>(other) {}
    ImmutableBitSequence(const LinkedList<Bit<T_word>>& list) : BitSequence<T_word>(list) {}

    BitSequence<T_word>* Instance() override {
        return this->Clone();
    }

    BitSequence<T_word>* Clone() const override {
        return new ImmutableBitSequence<T_word>(*this);
    }

    BitSequence<T_word>* CreateEmpty() const override {
        return new ImmutableBitSequence<T_word>();
    }
};