#pragma region constructors 
template <template <typename> class Container, typename T>
Container<T>* LinearForm<Container, T>::cloneCoeffs(const Container<T>* src) const {
    if (!src) 
        return nullptr;
    Container<T>* copy = src->clone();
    return copy;
}

template <template <typename> class Container, typename T>
LinearForm<Container, T>::LinearForm(Container<T>* coefficients) : coeffs(coefficients) {
    if (!coeffs) throw std::invalid_argument("Coefficients container cannot be null");
}

template <template <typename> class Container, typename T>
LinearForm<Container, T>::LinearForm(const LinearForm& other) : coeffs(other.coeffs->clone()) {}

template <template <typename> class Container, typename T>
LinearForm& LinearForm<Container, T>::operator=(const LinearForm& other) {
    if (this != &other) {
        Container<T>* newCoeffs = cloneCoeffs(other.coeffs);
        delete coeffs;
        coeffs = newCoeffs;
    }
    return *this;
}

template <template <typename> class Container, typename T>
LinearForm<Container, T>::~LinearForm() {
    delete coeffs;
}

template <template <typename> class Container, typename T>
LinearForm LinearForm<Container, T>::operator+(const LinearForm& other) const {
    if (!coeffs || !other.coeffs) throw std::runtime_error("Null container in addition");
    
    size_t len1 = coeffs->GetLength();
    size_t len2 = other.coeffs->GetLength();
    size_t maxLen = std::max(len1, len2);
    
    Container<T>* result = coeffs->CreateEmpty();
    try {
        for (size_t i = 0; i < maxLen; ++i) {
            T val1 = (i < len1) ? coeffs->Get(i) : T{};
            T val2 = (i < len2) ? other.coeffs->Get(i) : T{};
            result->Append(val1 + val2);
        }
    } catch (...) {
        delete result;
        throw;
    }
    return LinearForm(result);
}

template <template <typename> class Container, typename T>
LinearForm LinearForm<Container, T>::operator-(const LinearForm& other) const {
    if (!coeffs || !other.coeffs) throw std::runtime_error("Null container in subtraction");
    
    size_t len1 = coeffs->GetLength();
    size_t len2 = other.coeffs->GetLength();
    size_t maxLen = std::max(len1, len2);
    
    Container<T>* result = coeffs->CreateEmpty();
    try {
        for (size_t i = 0; i < maxLen; ++i) {
            T val1 = (i < len1) ? coeffs->Get(i) : T{};
            T val2 = (i < len2) ? other.coeffs->Get(i) : T{};
            result->Append(val1 - val2);
        }
    } catch (...) {
        delete result;
        throw;
    }
    return LinearForm(result);
}

template <template <typename> class Container, typename T>
LinearForm LinearForm<Container, T>::operator*(const T& scalar) const {
    if (!coeffs) throw std::runtime_error("Null container in scalar multiplication");
    
    Container<T>* result = coeffs->CreateEmpty();
    try {
        for (size_t i = 0; i < coeffs->GetLength(); ++i) {
            result->Append(coeffs->Get(i) * scalar);
        }
    } catch (...) {
        delete result;
        throw;
    }
    return LinearForm(result);
}

template <template <typename> class Container, typename T>
T LinearForm<Container, T>::Evaluate(const Container<T>& args) const {
    if (!coeffs) throw std::runtime_error("Null coefficients container");
    
    size_t n = coeffs->GetLength();
    if (n == 0) throw std::length_error("Empty coefficients");
    
    T result = coeffs->Get(0); 
    size_t argsLen = args.GetLength();
    
    for (size_t i = 1; i < n; ++i) {
        T arg = (i - 1 < argsLen) ? args.Get(i - 1) : T{};
        result = result + coeffs->Get(i) * arg;
    }
    return result;
}

template <template <typename> class Container, typename T>
T LinearForm<Container, T>::operator()(const Container<T>& args) const {
    return Evaluate(args);
}

template <template <typename> class Container, typename T>
const Container<T>& LinearForm<Container, T>::GetCoefficients() const { 
    if (!coeffs) throw std::runtime_error("Null coefficients container");
    return *coeffs; 
}

template <template <typename> class Container, typename T>
size_t LinearForm<Container, T>::GetArity() const { 
    if (!coeffs) throw std::runtime_error("Null coefficients container");
    return coeffs->GetLength() - 1;
}

#pragma endregion