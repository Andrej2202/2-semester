// test_class.hpp
#pragma once
#include <QString>
#include <cstddef>

template<typename T>
class MyList {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    // Внутренний метод для расширения массива
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    MyList() : data_(nullptr), size_(0), capacity_(0) {}

    ~MyList() { delete[] data_; }

    // 🔑 Конструктор копирования (обязательно при ручной работе с new/delete!)
    MyList(const MyList& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    // 🔑 Оператор копирования
    MyList& operator=(const MyList& other) {
        if (this != &other) {
            delete[] data_;
            capacity_ = other.capacity_;
            size_ = other.size_;
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    void append(const T& value) {
        if (size_ == capacity_) {
            resize(capacity_ == 0 ? 4 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    int count() const { return static_cast<int>(size_); }

    T Get(size_t index){return data_[index];}

    void clear() { 
        size_ = 0;
    }

    bool isEmpty() const { return size_ == 0; }

};