template <class T>
DynamicArray<T> :: DynamicArray(int size) : size_(size){
    if(size < 0){
        throw InvalidArgumentException("DynamicArray", "constructor", "size of new container < 0.");
    }
    if(size > MAX_ARR_SIZE){
        throw InvalidArgumentException("I'm just a little indi developer, don't push to much elements :(");
    }
    data_ = new T[this->size_];
}

template <class T>
DynamicArray<T> :: DynamicArray(T* items, int count) : size_(count){
    if(count < 0 or count > MAX_ARR_SIZE){
        throw InvalidArgumentException("DynamicArray", "constructor", "size of new container out of range.");
    }
    data_ = new T[size_];
    std::copy(items, items + size_, data_);
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) : size_(other.size_) {
    data_ = new T[size_];
    std::copy(other.data_, other.data_ + size_, data_);
}

template<class T>
T DynamicArray<T>::Get(int index){
    if(index < 0 || index >= size_){
        throw IndexOutOfRangeException("DynamicArray", "Get", "index is not in size bounds.");
    }
    return data_[index];
}

template<class T>
void DynamicArray<T>::Set(int index, T value){
    if(index < 0 || index >= size_){
        throw IndexOutOfRangeException("DynamicArray", "Set", "index is not in size bounds.");
    }
    data_[index] = value;
}

template<class T>
void DynamicArray<T>::Resize(int newSize){
    if (newSize < 0 || newSize > MAX_ARR_SIZE) {
        throw InvalidArgumentException("DynamicArray", "resize", "size of new container out of range.");
    }

    T* newData = new T[newSize]();
    int copyCount = (newSize < size_) ? newSize : size_;
    for (int i = 0; i < copyCount; ++i) {
        newData[i] = data_[i];
    }

    delete[] data_;
    data_ = newData;
    size_ = newSize;
}