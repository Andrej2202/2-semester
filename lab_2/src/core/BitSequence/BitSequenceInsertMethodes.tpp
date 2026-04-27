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
    int oldSize = target->bits->GetSize();
    target->bits->Resize(oldSize + 1);
    for (int i = oldSize; i > 0; i--) {
        target->bits->Set(i, target->bits->Get(i - 1));
    }
    target->bits->Set(0, item);
    return target;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::InsertAt(Bit<T_word> item, int index) {
    if (index < 0 || index > bits->GetSize()) throw IndexOutOfRangeException("BitSequence", "InsertAt", "index out of range.");
    
    BitSequence<T_word>* target = this->Instance();
    int oldSize = target->bits->GetSize();
    target->bits->Resize(oldSize + 1);
    for (int i = oldSize; i > index; i--) {
        target->bits->Set(i, target->bits->Get(i - 1));
    }
    target->bits->Set(index, item);
    return target;
}

template <std::integral T_word>
Sequence<Bit<T_word>>* BitSequence<T_word>::Concat(Sequence<Bit<T_word>>* otherSequence)  {
    if (otherSequence == nullptr) throw IndexOutOfRangeException("BitSequence", "Concat", "otherSequence is nullptr");
    
    BitSequence<T_word>* target = this->Instance();
    int oldSize = target->bits->GetSize();
    int otherSize = otherSequence->GetLength();
    target->bits->Resize(oldSize + otherSize);
    for (int i = 0; i < otherSize; i++) {
        target->bits->Set(oldSize + i, otherSequence->Get(i));
    }
    return target;
}