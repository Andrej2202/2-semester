template<class T>
Sequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex) const{
    if(startIndex < 0 || endIndex >= data_->GetSize() || startIndex > endIndex){
        throw IndexOutOfRangeException("ArraySequence", "GetSubList", "size of new container out of range.");
    }
    int buffer_length = endIndex - startIndex + 1;
    T* buffer = new T[buffer_length];

    for(auto i = 0; i < buffer_length; i++){
        buffer[i] = data_->Get(startIndex + i);
    }

    Sequence<T>* result = this->Clone();
    delete static_cast<ArraySequence<T>*>(result)->data_; 
    static_cast<ArraySequence<T>*>(result)->data_ = new DynamicArray<T>(buffer, buffer_length);
    
    delete[] buffer;
    return result;
}