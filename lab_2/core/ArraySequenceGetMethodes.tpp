template<class T>
ArraySequence<T>* ArraySequence<T>::GetSubList(int startIndex, int endIndex){
    if(startIndex < 0 || endIndex >= data_->GetSize() || startIndex > endIndex){
        throw IndexOutOfRangeException("Index out of range in GetSubList methode ArraySequence.");
    }
    int buffer_length = endIndex - startIndex + 1;
    T* buffer = new T[buffer_length];

    for(auto i = 0; i < buffer_length; i++){
        buffer[i] = data_->Get(startIndex + i);
    }

    Sequence<T>* result = this->Clone();
    delete static_cast<ArraySequence<T>*>(result)->data_; 
    static_cast<ArraySequence<T>*>(result)->data_ = new DynamicArray<T>(buffer, len);
    
    delete[] buffer;
    return result;
}