template<class T>
T LinkedList<T>::GetFirst() const {
    if (head_ == nullptr) throw IndexOutOfRangeException("LinkedList", "GetFirst", "LinkedList is empty");
    return head_->data;
}

template<class T>
T LinkedList<T>::GetLast() const {
    if (head_ == nullptr) throw IndexOutOfRangeException("LinkedList", "GetLast", "LinkedList is empty");
    return tail_->data;
}

template<class T>
T LinkedList<T>::Get(int index) const {
    if (index < 0) {
        throw IndexOutOfRangeException("LinkedList", "Get", "Index < 0");
    }

    Node_* current = head_;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }
    if (current == nullptr) {
        throw IndexOutOfRangeException("LinkedList", "Get", "Index > length");
    }

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
    int len = GetLength();
    if (startIndex < 0 || endIndex < 0 || startIndex >= len || endIndex >= len || startIndex > endIndex) {
        throw IndexOutOfRangeException("LinkedList", "GetSubList", "Invalid sublist range");
    }

    LinkedList<T>* result = new LinkedList<T>();
    Node_* current = head_;

    for (int i = 0; i < startIndex; ++i) {
        current = current->next;
    }
    int count = endIndex - startIndex + 1;
    for (int i = 0; i < count; ++i) {
        result->Append(current->data);
        current = current->next;
    }

    return result;
}