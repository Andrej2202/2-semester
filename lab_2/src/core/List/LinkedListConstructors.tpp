template <class T>
LinkedList<T>::LinkedList(T* items, int count) : head_(nullptr), tail_(nullptr) {
    if (count < 0){
        throw InvalidArgumentException("LinkedList",  "constructor", "size of container is < 0.");
    } 
    if (count > MAX_ARR_SIZE){
        throw InvalidArgumentException("I'm just a little indi developer, don't push to much elements :(");
    }
    for (int i = 0; i < count; i++){
        Append(items[i]);
    }
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head_(nullptr), tail_(nullptr) {
    Node_* current = other.head_;
    while (current != nullptr) {
        Node_* newNode_ = new Node_(current->data);
        if (!head_) head_ = tail_ = newNode_;
        else {
            tail_->next = newNode_;
            tail_ = newNode_;
        }
        current = current->next;
    }
}