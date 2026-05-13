#pragma region constructors
template<typename T>
LinearForm<T>::LinearForm(Sequence<T>* coefficients) : coeffs(coefficients) {
    if (!coeffs || coeffs->GetLength() == 0) {
        delete coeffs;
        throw IndexOutOfRangeException("LinearForm", "constructor", "requires at least a0 coefficient");
    }
}

template<typename T>
LinearForm<T>::LinearForm(const LinearForm& other) {
    coeffs = cloneCoeffs(other.coeffs);
}

template<typename T>
LinearForm<T>::~LinearForm() {
    delete coeffs;
}
#pragma endregion

#pragma region operations
template<typename T>
LinearForm<T> LinearForm<T>::operator+(const LinearForm& other) const {
    size_t n1 = coeffs->GetLength();
    size_t n2 = other.coeffs->GetLength();
    size_t maxN = (n1 > n2) ? n1 : n2;

    Sequence<T>* result = coeffs->CreateEmpty();
    try {
        for (size_t i = 0; i < maxN; i++) {
            T c1 = (i < n1) ? coeffs->Get(i) : T(0);
            T c2 = (i < n2) ? other.coeffs->Get(i) : T(0);
            result->Append(c1 + c2);
        }
    } catch (...) {
        delete result;
        throw;
    }
    return LinearForm(result);
}

template<typename T>
LinearForm<T> LinearForm<T>::operator-(const LinearForm& other) const {
    size_t n1 = coeffs->GetLength();
    size_t n2 = other.coeffs->GetLength();
    size_t maxN = (n1 > n2) ? n1 : n2;

    Sequence<T>* result = coeffs->CreateEmpty();
    try {
        for (size_t i = 0; i < maxN; i++) {
            T c1 = (i < n1) ? coeffs->Get(i) : T(0);
            T c2 = (i < n2) ? other.coeffs->Get(i) : T(0);
            result->Append(c1 - c2);
        }
    } catch (...) {
        delete result;
        throw;
    }
    return LinearForm(result);
}

template<typename T>
LinearForm<T> LinearForm<T>::operator*(const T& scalar) const {
    Sequence<T>* scaled = map(*coeffs, [scalar](const T& c) { return c * scalar; });
    return LinearForm(scaled);
}
#pragma endregion

#pragma region other
template<typename T>
T LinearForm<T>::Evaluate(const Sequence<T>& args) const {
    size_t n_vars = coeffs->GetLength() - 1;
    if (args.GetLength() != n_vars) {
        throw InvalidArgumentException("LinearForm", "Evaluate", "arguments ammount does not match arity.");
    }

    T result = coeffs->Get(0); 
    for (size_t i = 1; i < coeffs->GetLength(); i++) {
        result = result + coeffs->Get(i) * args.Get(i - 1);
    }
    return result;
}

template<typename T>
LinearForm<T>& LinearForm<T>::operator=(const LinearForm& other) {
    if (this != &other) {
        Sequence<T>* newCoeffs = cloneCoeffs(other.coeffs);
        delete coeffs;
        coeffs = newCoeffs;
    }
    return *this;
}

template<typename T>
T LinearForm<T>::operator()(const Sequence<T>& args) const {
    return Evaluate(args);
}
#pragma endregion