template <std::integral T_word>
Bit<T_word> BitSequence<T_word>::GetFirst() const{
    if (bits->GetSize() == 0) throw IndexOutOfRangeException("BitSequence", "GetFirst", "size = 0.");
    return bits->Get(0);
}

template <std::integral T_word>
Bit<T_word> BitSequence<T_word>::GetLast() const{
    if (bits->GetSize() == 0) throw IndexOutOfRangeException("BitSequence", "GetLast", "size = 0.");
    return bits->Get(bits->GetSize() - 1);
}

template <std::integral T_word>
Bit<T_word> BitSequence<T_word>::Get(int index) const{
    if (index < 0 || index >= bits->GetSize()) throw IndexOutOfRangeException("BitSequence", "Get", "size out of range.");
    return bits->Get(index);
}

template <std::integral T_word>
int BitSequence<T_word>::GetLength() const{
    return bits->GetSize();
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::GetSubsequence(int startIndex, int endIndex) const{
    if (startIndex < 0 || endIndex >= bits->GetSize() || startIndex > endIndex) {
        throw InvalidArgumentException("BitSequence", "GetSubsequence", "wrong indexes.");
    }
    
    BitSequence<T_word>* result = CreateEmpty();
    int subSize = endIndex - startIndex + 1;
    result->bits->Resize(subSize);
    for (int i = 0; i < subSize; i++) {
        result->bits->Set(i, bits->Get(startIndex + i));
    }
    return result;
}