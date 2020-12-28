/*
Iterator library for Sltl
Author: Christopher Huggins
*/

//accessing private ptr
//inheriting from output iter
//[]

#include <utility>

template <class T>
class Input_Iterator {
public:
    Input_Iterator<T>(Input_Iterator<T> & cpy_itr) {
        ptr = *cpy_itr;
    }

    ~Input_Iterator<T>() {
        ptr == nullptr;
    }

    T & operator->() {
        return *ptr;
    }

    T & operator++() {
        ++ptr;
        return *ptr;
    }

    void operator++(int) {
        ++ptr;
        return;
    }

    T & operator*() {
        return *ptr;
    }

    bool operator==(Input_Iterator<T> & rhs) {
        return (ptr == rhs.ptr);
    }

    bool operator!=(Input_Iterator<T> & rhs) {
        return (ptr != rhs.ptr);
    }

    void swap(Input_Iterator<T> & lhs, Input_Iterator<T> & rhs) {
        std::swap(lhs, rhs);
    }

private: 
    T* ptr;
};

template<class T>
class Forward_Iterator : public Input_Iterator<T> {
public:
    Forward_Iterator<T>() : ptr(nullptr) {};
private:
    T* ptr;
};

template<class T>
class Bidirectional_Iterator : public Forward_Iterator<T> {
public:
    T & operator--() {
        --ptr;
        return *ptr;
    }

    void operator--(int) {
        --ptr;
        return;
    }
private:
    T* ptr;
};

template<class T>
class Random_Access_Iterator : public Bidirectional_Iterator<T> {
public:
    T* operator+(int val) {
        ptr += val;
        return ptr;
    }

    int operator-(Random_Access_Iterator<T> & rhs) {
        return ptr - rhs.ptr;
    }

    T* operator-(int val) {
        ptr -= val;
        return ptr;
    }

    void operator+=(int val) {
        ptr += val;
        return;
    }

    void operator-=(int val) {
        ptr -= val;
        return;
    }

    bool operator<(Random_Access_Iterator<T> & rhs) {
        return (ptr < rhs.ptr);
    }

    bool operator>(Random_Access_Iterator<T> & rhs) {

    }

    bool operator<=(Random_Access_Iterator<T> & rhs) {

    }

    bool operator>=(Random_Access_Iterator<T> & rhs) {

    }

    T & operator[](int val) {

    }

private:
    T* ptr;
};

template<class T>
class Output_Iterator {

};