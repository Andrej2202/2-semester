template<class T>
T LinkedList<T>::GetFirst() const {
    if (length_ == 0) throw IndexOutOfRange("LinkedList is empty");
    return head_->data;
}

template<class T>
T LinkedList<T>::GetLast() const {
    if (length_ == 0) throw IndexOutOfRange("LinkedList is empty");
    return tail_->data;
}

template<class T>
T LinkedList<T>::Get(int index) const {
    if (index < 0 || index >= length_) 
        throw IndexOutOfRange("Index out of range in LinkedList::Get");
    Node_* current = head_;
    for (int i = 0; i < index; ++i) current = current->next;
    return current->data;
}

template<class T>
int LinkedList<T>::GetLength() const{
     return length_; 
}

template<class T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= length_ || startIndex > endIndex)
        throw IndexOutOfRange("Invalid sublist range in LinkedList");
        
    LinkedList<T>* result = new LinkedList<T>();
    Node_* current = head_;
    for (int i = 0; i <= endIndex; ++i) {
        if (i >= startIndex) result->Append(current->data);
        current = current->next;
    }
    return result;
}