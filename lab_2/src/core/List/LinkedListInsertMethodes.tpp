template<class T>
void LinkedList<T>::Append(T item){
    Node_* newNode_ = new Node_(item);
    if (length_ == 0) head_ = tail_ = newNode_;
    else {
        tail_->next = newNode_;
        tail_ = newNode_;
    }
    length_++;
}

template<class T>
void LinkedList<T>::Prepend(T item){
    Node_* newNode_ = new Node_(item);
    if (length_ == 0) head_ = tail_ = newNode_;
    else {
        newNode_->next = head_;
        head_ = newNode_;
    }
    length_++;
}

template<class T>
void LinkedList<T>::InsertAt(T item, int index){
    if (index < 0 || index >= length_)
        throw IndexOutOfRange("Index out of range in LinkedList::InsertAt");
    if (index == 0) {
        Prepend(item);
        return;
    }
    Node_* current = head_;
    for (int i = 0; i < index - 1; ++i) current = current->next;
    Node_* newNode_ = new Node_(item);
    newNode_->next = current->next;
    current->next = newNode_;
    length_++;
}

template<class T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list){
    if (list == nullptr) return new LinkedList<T>(*this);
    LinkedList<T>* result = new LinkedList<T>(*this);
    Node_* current = list->head_;
    while (current != nullptr) {
        result->Append(current->data);
        current = current->next;
    }
    return result;
}