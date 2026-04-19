inline constexpr int MAX_ARR_SIZE = 100000;

template <class T>
DynamicArray :: DynamicArray(int size) : size_(size){
    if(size < 0){
        throw IndexOutOfRangeException();
    }
    if(size > MAX_ARR_SIZE){
        throw IndexOutOfRangeException("I'm just a little indi developer, don't push to much elements :(");
    }
    this->size_ = size;
    data = new T[this->size_];
}

template <class T>
DynamicArray :: DynamicArray(T* items, int count) : size_(count){
    if(count < 0 or count > MAX_ARR_SIZE){
        throw IndexOutOfRangeException();
    }
    size = count;
    data = new T[size];
    std::copy(items, items + size, data);
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) : size(other.size) {
    data = new T[size];
    std::copy(other.data, other.data + size, data);
}

template<class T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}