template<typename T, typename Func>
Sequence<T>* map(const Sequence<T>& seq, Func f) {
    Sequence<T>* res = seq.CreateEmpty();
    for (size_t i = 0; i < seq.GetLength(); i++) res->Append(f(seq.Get(i)));
    return res;
}

template<typename T, typename Pred>
Sequence<T>* where(const Sequence<T>& seq, Pred pred) {
    Sequence<T>* res = seq.CreateEmpty();
    for (size_t i = 0; i < seq.GetLength(); i++)
        if (pred(seq.Get(i))) res->Append(seq.Get(i));
    return res;
}

template<typename T, typename Func>
T reduce(const Sequence<T>& seq, Func f, const T& initial) {
    T acc = initial;
    for (int i = static_cast<int>(seq.GetLength()) - 1; i >= 0; --i)
        acc = f(seq.Get(i), acc);
    return acc;
}