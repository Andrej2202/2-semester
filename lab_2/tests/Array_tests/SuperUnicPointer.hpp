#pragma once 
#include <memory>
template <typename T>
class SuperUnicPointer{
private:
    T* pointer_;
public:
// makenew
    SuperUnicPointer(T* pointer) : pointer_(pointer) {}
    ~SuperUnicPointer() {delete pointer_;}

    SuperUnicPointer(const SuperUnicPointer&) = delete;
    SuperUnicPointer& operator=(const SuperUnicPointer&) = delete;

    SuperUnicPointer(SuperUnicPointer&& other) : pointer_(other.pointer_) {
        other.pointer_ = nullptr;
    }

    SuperUnicPointer& operator=(SuperUnicPointer&& other) {
        if (this != &other) {
            delete pointer_;
            pointer_ = other.pointer_;
            other.pointer_ = nullptr;
            //std::make_unique
        }
        return *this;
    }

    T* get() const { return pointer_; }
    T& operator*() const { return *pointer_; }
    T* operator->() const { return pointer_; }


};