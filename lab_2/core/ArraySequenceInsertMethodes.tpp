template<class T>
void ArraySequence<T>::AppendInternal(T item){
    int temp = data_->GetSize();
    data_->Resize(temp + 1);
    data_->Set(temp, item);
}

template<class T>
Sequence<T>* ArraySequence<T>::Append(T item){
    Sequence<T>* target = this->Instance();
    static_cast<ArraySequence<T>*>(target)->AppendInternal(item);
    return target;
}

template<class T>
void ArraySequence<T>::PrependInternal(T item){
    int temp = data_->GetSize();
    data_->Resize(temp + 1);
    for(int i = temp; i > 0; i--){
        data_->Set(i, data_->Get(i-1));
    }
    data_->Set(0, item);
}

template<class T>
Sequence<T>* ArraySequence<T>::Prepend(T item){
    Sequence<T>* target = this->Instance();
    static_cast<ArraySequence<T>*>(target)->PrependInternal(item);
    return target;
}


template<class T>
void ArraySequence<T>::InsertAtInternal(T item, int index){
    int temp = data_->GetSize();
    data_->Resize(temp + 1);
    for(int i = temp; i > index; i--){
        data_->Set(i, data_->Get(i-1));
    }
    data_->Set(index, item);
}

template<class T>
Sequence<T>* ArraySequence<T>::InsertAt(T item, int index){
    if (index < 0 || index >= this->GetLength()) {
        throw IndexOutOfRangeException("Index out of range in GetSubList methode ArraySequence.");
    }
    Sequence<T>* target = this->Instance();
    static_cast<ArraySequence<T>*>(target)->InsertAtInternal(item, index);
    return target;
}