template<class T>
T LinkedList<T>::GetFirst() const {
    if (head_ == nullptr) throw IndexOutOfRangeException("LinkedList is empty");
    return head_->data;
}

template<class T>
T LinkedList<T>::GetLast() const {
    if (head_ == nullptr) throw IndexOutOfRangeException("LinkedList is empty");
    return tail_->data;
}

template<class T>
T LinkedList<T>::Get(int index) const {
    if (index < 0) throw IndexOutOfRangeException("Index out of range in LinkedList::Get");
    Node_* current = head_;
    for (int i = 0; i < index; ++i) {
        if (current == nullptr) throw IndexOutOfRangeException("Index out of range in LinkedList::Get");
        current = current->next;
    }
    if (current == nullptr) throw IndexOutOfRangeException("Index out of range in LinkedList::Get");
    return current->data;
}

template<class T>
int LinkedList<T>::GetLength() const {
    int count = 0;
    Node_* current = head_;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

template<class T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= currentLength || startIndex > endIndex)
        throw IndexOutOfRangeException("Invalid sublist range in LinkedList");

    LinkedList<T>* result = new LinkedList<T>();
    Node_* current = head_;
    for (int i = 0; i <= endIndex; ++i) {
        if (i >= startIndex) result->Append(current->data);
        current = current->next;
    }
    return result;
}