template <std::integral T_word>
Bit<T_word>& BitSequence<T_word>::operator[](int index) {
    if (index < 0 || index >= bits->GetSize()) throw IndexOutOfRangeException("BitSequence", "operator[]", "size out of range.");
    return (*bits)[index];
}

template <std::integral T_word>
const Bit<T_word>& BitSequence<T_word>::operator[](int index) const {
    if (index < 0 || index >= bits->GetSize()) throw IndexOutOfRangeException("BitSequence", "operator[]", "index out of range.");
    return (*bits)[index];
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::operator&(const BitSequence& other) const {
    if (bits->GetSize() != other.bits->GetSize()) throw IndexOutOfRangeException("BitSequence", "operator&", "size missmatch.");
    
    BitSequence<T_word>* res = CreateEmpty();
    res->bits->Resize(bits->GetSize());
    for (int i = 0; i < bits->GetSize(); i++) {
        res->bits->Set(i, bits->Get(i) & other.bits->Get(i));
    }
    return res;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::operator|(const BitSequence& other) const {
    if (bits->GetSize() != other.bits->GetSize()) throw IndexOutOfRangeException("BitSequence", "operator|", "size missmatch.");
    
    BitSequence<T_word>* res = CreateEmpty();
    res->bits->Resize(bits->GetSize());
    for (int i = 0; i < bits->GetSize(); i++) {
        res->bits->Set(i, bits->Get(i) | other.bits->Get(i));
    }
    return res;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::operator^(const BitSequence& other) const {
    if (bits->GetSize() != other.bits->GetSize()) throw IndexOutOfRangeException("BitSequence", "operator^", "size missmatch.");
    
    BitSequence<T_word>* res = CreateEmpty();
    res->bits->Resize(bits->GetSize());
    for (int i = 0; i < bits->GetSize(); i++) {
        res->bits->Set(i, bits->Get(i) ^ other.bits->Get(i));
    }
    return res;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::operator~() const {
    BitSequence<T_word>* res = CreateEmpty();
    res->bits->Resize(bits->GetSize());
    for (int i = 0; i < bits->GetSize(); i++) {
        res->bits->Set(i, ~bits->Get(i));
    }
    return res;
}


