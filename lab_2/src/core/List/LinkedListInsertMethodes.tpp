template<class T>
void LinkedList<T>::Append(T item) {
    Node_* newNode = new Node_(item);
    if (head_ == nullptr) {
        head_ = tail_ = newNode;
    } else {
        tail_->next = newNode;
        tail_ = newNode;
    }
}

template<class T>
void LinkedList<T>::Prepend(T item) {
    Node_* newNode = new Node_(item);
    if (head_ == nullptr) {
        head_ = tail_ = newNode;
    } else {
        newNode->next = head_;
        head_ = newNode;
    }
}

template<class T>
void LinkedList<T>::InsertAt(T item, int index) {
    if (index < 0)
        throw IndexOutOfRangeException("LinkedList", "InsertAt");
    
    int currentLength = GetLength();
    if (index >= currentLength) 
        throw IndexOutOfRangeException("LinkedList", "InsertAt");
        
    if (index == 0) {
        Prepend(item);
        return;
    }

    Node_* current = head_;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    Node_* newNode = new Node_(item);
    newNode->next = current->next;
    current->next = newNode;
}

template<class T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list) {
    if (list == nullptr) 
        return new LinkedList<T>(*this);
    
    LinkedList<T>* result = new LinkedList<T>(*this);
    Node_* current = list->head_;

    while (current != nullptr) {
        result->Append(current->data);
        current = current->next;
    }
    return result;
}