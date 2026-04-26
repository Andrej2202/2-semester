template<class T>
T ListSequence<T>::GetFirst() const { return data_->GetFirst(); }
template<class T>
T ListSequence<T>::GetLast() const { return data_->GetLast(); }
template<class T>
T ListSequence<T>::Get(int index) const { return data_->Get(index); }
template<class T>
int ListSequence<T>::GetLength() const { return data_->GetLength(); }

template<class T>
Sequence<T>* ListSequence<T>::GetSubsequence(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= data_->GetLength() || startIndex > endIndex)
        throw IndexOutOfRangeException("ListSequence", "GetSubsequence", "Invalid subsequence range.");
    LinkedList<T>* subList = data_->GetSubList(startIndex, endIndex);
    Sequence<T>* result = this->Clone();
    delete static_cast<ListSequence<T>*>(result)->data_;
    static_cast<ListSequence<T>*>(result)->data_ = subList;
    
    return result;
}