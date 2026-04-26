template<class T>
void ListSequence<T>::AppendInternal(T item) {
    data_->Append(item);
}

template<class T>
Sequence<T>* ListSequence<T>::Append(T item){
    Sequence<T>* target = this->Instance();
    static_cast<ListSequence<T>*>(target)->AppendInternal(item);
    return target;
}

template<class T>
void ListSequence<T>::PrependInternal(T item) {
    data_->Prepend(item);
}

template<class T>
Sequence<T>* ListSequence<T>::Prepend(T item){
    Sequence<T>* target = this->Instance();
    static_cast<ListSequence<T>*>(target)->PrependInternal(item);
    return target;
}

template<class T>
void ListSequence<T>::InsertAtInternal(T item, int index) {
    data_->InsertAt(item, index);
}

template<class T>
Sequence<T>* ListSequence<T>::InsertAt(T item, int index){
    Sequence<T>* target = this->Instance();
    static_cast<ListSequence<T>*>(target)->InsertAtInternal(item, index);
    return target;
}

template<class T>
void ListSequence<T>::ConcatInternal(Sequence<T>* smth) {
    if (smth == nullptr) return;
    int len = smth->GetLength();
    for (int i = 0; i < len; ++i) {
        data_->Append(smth->Get(i));
    }
}

template<class T>
Sequence<T>* ListSequence<T>::Concat(Sequence<T>* smth){
    Sequence<T>* target = this->Clone();
    static_cast<ListSequence<T>*>(target)->ConcatInternal(smth);
    return target;
}