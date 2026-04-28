#pragma once 

template <typename T>
class SuperUnicPointer{
private:
    T* pointer_;
public:
    SuperUnicPointer(T* pointer) : pointer_(pointer) {}
    ~SuperUnicPointer() {delete pointer_}

    SuperUnicPointer(const SuperUnicPointer&) = delete;
    SuperUnicPointer& operator=(const SuperUnicPointer&) = delete;

    SuperUnicPointer(SuperUnicPointer&& other) : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    SuperUnicPointer& operator=(SuperUnicPointer&& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T* get() const { return ptr; }
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }


}