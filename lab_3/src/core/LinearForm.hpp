#pragma once
#include <Sequence.hpp>
#include <Algorithms.hpp>
#include <Exceptions.hpp>
#include <algorithm>

template <template <typename> class Container, typename T>
class LinearForm {
private:
    Container<T>* coeffs;

    Container<T>* cloneCoeffs(const Container<T>* src) const;

public:
    LinearForm(Container<T>* coefficients);
    LinearForm(const LinearForm& other);
    LinearForm& operator=(const LinearForm& other);
    ~LinearForm();

    LinearForm operator+(const LinearForm& other) const;
    LinearForm operator-(const LinearForm& other) const;
    LinearForm operator*(const T& scalar) const;
    

    T Evaluate(const Container<T>& args) const;
    T operator()(const Container<T>& args) const;


    const Container<T>& GetCoefficients() const;
    size_t GetArity() const;
};

#include "LinearForm.tpp"