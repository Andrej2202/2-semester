#pragma region "GetMethodes"
template <std::integral T_word>
Bit<T_word> BitSequence<T_word>::GetFirst() const{
    if (bits->GetSize() == 0){
        throw IndexOutOfRangeException("BitSequence", "GetFirst", "size = 0.");
    }
    return bits->Get(0);
}

template <std::integral T_word>
Bit<T_word> BitSequence<T_word>::GetLast() const{
    if (bits->GetSize() == 0){
        throw IndexOutOfRangeException("BitSequence", "GetLast", "size = 0.");
    }
    return bits->Get(bits->GetSize() - 1);
}

template <std::integral T_word>
Bit<T_word> BitSequence<T_word>::Get(size_t index) const{
    if (index >= bits->GetSize()){
        throw IndexOutOfRangeException("BitSequence", "Get", "size out of range.");
    }
    return bits->Get(index);
}

template <std::integral T_word>
size_t BitSequence<T_word>::GetLength() const{
    return bits->GetSize();
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::GetSubsequence(size_t startIndex, size_t endIndex) const{
    if (endIndex >= bits->GetSize() || startIndex > endIndex) {
        throw InvalidArgumentException("BitSequence", "GetSubsequence", "wrong indexes.");
    }
    
    BitSequence<T_word>* result = CreateEmpty();
    size_t subSize = endIndex - startIndex + 1;
    result->bits->Resize(subSize);
    for (size_t i = 0; i < subSize; i++) {
        result->bits->Set(i, bits->Get(startIndex + i));
    }
    return result;
}
#pragma endregion

#pragma region "InsertMethodes"
template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::Append(Bit<T_word> item)  {
    BitSequence<T_word>* target = this->Instance();
    target->bits->Resize(target->bits->GetSize() + 1);
    target->bits->Set(target->bits->GetSize() - 1, item);
    return target;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::Prepend(Bit<T_word> item)  {
    BitSequence<T_word>* target = this->Instance();
    size_t oldSize = target->bits->GetSize();
    target->bits->Resize(oldSize + 1);
    for (size_t i = oldSize; i > 0; i--) {
        target->bits->Set(i, target->bits->Get(i - 1));
    }
    target->bits->Set(0, item);
    return target;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::InsertAt(Bit<T_word> item, size_t index) {
    if (index > bits->GetSize()){ 
        throw IndexOutOfRangeException("BitSequence", "InsertAt", "index out of range.");
    }
    
    BitSequence<T_word>* target = this->Instance();
    size_t oldSize = target->bits->GetSize();
    target->bits->Resize(oldSize + 1);
    for (size_t i = oldSize; i > index; i--) {
        target->bits->Set(i, target->bits->Get(i - 1));
    }
    target->bits->Set(index, item);
    return target;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::Concat(Sequence<Bit<T_word>>* otherSequence)  {
    if (otherSequence == nullptr){
        throw IndexOutOfRangeException("BitSequence", "Concat", "otherSequence is nullptr");
    }
    
    BitSequence<T_word>* target = this->Instance();
    size_t oldSize = target->bits->GetSize();
    size_t otherSize = otherSequence->GetLength();
    target->bits->Resize(oldSize + otherSize);
    for (size_t i = 0; i < otherSize; i++) {
        target->bits->Set(oldSize + i, otherSequence->Get(i));
    }
    return target;
}
#pragma endregion

#pragma region "operators"
template <std::integral T_word>
Bit<T_word>& BitSequence<T_word>::operator[](size_t index) {
    if (index >= bits->GetSize()){
        throw IndexOutOfRangeException("BitSequence", "operator[]", "size out of range.");
    }
    return (*bits)[index];
}

template <std::integral T_word>
const Bit<T_word>& BitSequence<T_word>::operator[](size_t index) const {
    if (index >= bits->GetSize()){
        throw IndexOutOfRangeException("BitSequence", "operator[]", "index out of range.");
    }
    return (*bits)[index];
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::operator&(const BitSequence& other) const {
    if (bits->GetSize() != other.bits->GetSize()){
        throw IndexOutOfRangeException("BitSequence", "operator&", "size missmatch.");
    }
    
    BitSequence<T_word>* res = CreateEmpty();
    res->bits->Resize(bits->GetSize());
    for (size_t i = 0; i < bits->GetSize(); i++) {
        res->bits->Set(i, bits->Get(i) & other.bits->Get(i));
    }
    return res;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::operator|(const BitSequence& other) const {
    if (bits->GetSize() != other.bits->GetSize()){
        throw IndexOutOfRangeException("BitSequence", "operator|", "size missmatch.");
    }
    
    BitSequence<T_word>* res = CreateEmpty();
    res->bits->Resize(bits->GetSize());
    for (size_t i = 0; i < bits->GetSize(); i++) {
        res->bits->Set(i, bits->Get(i) | other.bits->Get(i));
    }
    return res;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::operator^(const BitSequence& other) const {
    if (bits->GetSize() != other.bits->GetSize()){
        throw IndexOutOfRangeException("BitSequence", "operator^", "size missmatch.");
    }
    
    BitSequence<T_word>* res = CreateEmpty();
    res->bits->Resize(bits->GetSize());
    for (size_t i = 0; i < bits->GetSize(); i++) {
        res->bits->Set(i, bits->Get(i) ^ other.bits->Get(i));
    }
    return res;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::operator~() const {
    BitSequence<T_word>* res = CreateEmpty();
    res->bits->Resize(bits->GetSize());
    for (size_t i = 0; i < bits->GetSize(); i++) {
        res->bits->Set(i, ~bits->Get(i));
    }
    return res;
}

#pragma endregion
