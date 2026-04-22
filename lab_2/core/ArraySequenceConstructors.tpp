template<class T>
ArraySequence<T>::ArraySequence(T* items, int count) {
    if (count < 0) 
        throw std::invalid_argument("Argument out of range in constructor");
    data_ = new DynamicArray<T>(items, count);
}


template<class T>
ArraySequence<T>::Arraysequence(const LinkedList <T> & list){
    int length = list.GetLength();
    data_ = new DynamicArray<T>(length);
    for(auto i = 0; i < length; i++){
        data_->Set(i, list.Get(i));
    }
}

template<class T>
ArraySequence<T>::Arraysequence(const ArraySequence<T> & array){
    data_ = new DynamicArray<T>(*other.data);
}