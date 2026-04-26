#pragma once

template<std::integral T>
struct BitProxy {
    T& ref;
    size_t idx;

    BitProxy& operator=(bool val) {
        if (val) ref |= (static_cast<T>(1) << idx);
        else     ref &= ~(static_cast<T>(1) << idx);
        return *this;
    }
    operator bool() const {
        return (ref >> idx) & 1;
    }
};

template<std::integral T>
class Bit {
private:
    T& storage;
    size_t idx;
public:
    Bit(T& ref, size_t index) : storage(ref), idx(index) {}
    
    bool operator[](size_t) const { return (storage >> idx) & 1; }
    BitProxy<T> operator[](size_t) { return BitProxy<T>{storage, idx}; }
    operator bool() const { return (storage >> idx) & 1; }
};