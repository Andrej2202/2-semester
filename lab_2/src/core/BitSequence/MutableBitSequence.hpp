#pragma once

template <std::integral T_word = unsigned char>
class MutableBitSequence : public BitSequence<T_word> {
public:
    MutableBitSequence() : BitSequence<T_word>() {}
    MutableBitSequence(Bit<T_word>* items, int count) : BitSequence<T_word>(items, count) {}
    MutableBitSequence(const BitSequence<T_word>& other) : BitSequence<T_word>(other) {}
    MutableBitSequence(const LinkedList<Bit<T_word>>& list) : BitSequence<T_word>(list) {}

    BitSequence<T_word>* Instance() override {
        return this;
    }

    BitSequence<T_word>* Clone() const override {
        return new MutableBitSequence<T_word>(*this);
    }

    BitSequence<T_word>* CreateEmpty() const override {
        return new MutableBitSequence<T_word>();
    }
};