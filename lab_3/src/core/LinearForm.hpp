#pragma once
#include <Sequence.hpp>
#include <Algorithms.hpp>
#include <stdexcept>
#include <ostream>
#include <algorithm>

template<typename T>
class LinearForm {
private:
    Sequence<T>* coeffs;

    //глубокое копирование дабы не юзать Clone() из Sequence a.k.a разделение ответственности?....
    Sequence<T>* cloneCoeffs(const Sequence<T>* src) const {
        if (!src) return nullptr;
        Sequence<T>* copy = src->CreateEmpty();
        try {
            for (size_t i = 0; i < src->GetLength(); ++i) {
                copy->Append(src->Get(i));
            }
        } catch (...) {
            delete copy;
            throw;
        }
        return copy;
    }

public:
    explicit LinearForm(Sequence<T>* coefficients);
    LinearForm(const LinearForm& other);
    LinearForm& operator=(const LinearForm& other);
    ~LinearForm();

    
    LinearForm operator+(const LinearForm& other) const;
    LinearForm operator-(const LinearForm& other) const;
    LinearForm operator*(const T& scalar) const;
    
    
    T Evaluate(const Sequence<T>& args) const;
    T operator()(const Sequence<T>& args) const;

    
    const Sequence<T>& GetCoefficients() const { return *coeffs; }
    size_t GetArity() const { return coeffs->GetLength() - 1; }

    // Дружественный вывод но он чисто для отладки и терминального интерфейса на 1 парах
    friend std::ostream& operator<<(std::ostream& os, const LinearForm& form) {
        os << "F(x) = ";
        for (size_t i = 0; i < form.coeffs->GetLength(); i++) {
            os << form.coeffs->Get(i);
            if (i == 0 && form.coeffs->GetLength() > 1) os << " + ";
            else if (i > 0 && i < form.coeffs->GetLength() - 1) os << "x" << i << " + ";
            else if (i == form.coeffs->GetLength() - 1 && i > 0) os << "x" << i;
        }
        return os;
    }
};

#include "LinearForm.tpp"