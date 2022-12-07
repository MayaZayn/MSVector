#ifndef VECTOR_MSVECTOR_H
#define VECTOR_MSVECTOR_H

#include <iostream>
using namespace std;

template<class T>
class MSVector {
private:
    //How can we use std::iterator or should be just typedef?
    T *vector = new T[2];
    int Size, Capacity;
//    typedef T* iterator;

public:
    // Constructors and Big 5
    MSVector();
    explicit MSVector (int);
    MSVector (T*, int);
    MSVector (const MSVector&);
    ~MSVector();
    MSVector &operator=(const MSVector<T>&);
    MSVector<int> operator=(MSVector<T>&&) noexcept ;

    // Access operator
    T& operator[](int);  // Throw an exception if out of range

    // Modifying operations
    int push_back(T);
    T pop_back();
    void erase(T*);        // Remove item at iterator
                           // Throw exception if invalid iter
    void erase(T*, T*);    // Remove items between
                           // iterator 1 <= iterator 2 otherwise do nothing
                           // Throw exception if any iterator outside range
    void clear();
    void insert(T*, T);    // Insert item at iterator
                           // Throw exception if invalid

    // Iterators
    T* begin();
    T* end();

    // 2 comparison operators
    bool operator==(const MSVector<T>&);
    bool operator< (const MSVector<T>&);

    // Capacity operators
    int size() const;
    int capacity() const;
    int resize();         // Relocate to bigger space
    bool empty();

    // Friend overloaded operator
    // It is working, but I don't know why couldn't it be implemented in the source file itself
    friend ostream& operator << (ostream& out, MSVector<T> vec) {
        for (int i = 0; i < vec.Size; ++i) {
            out << vec.vector[i] << ' ';
        }
        out << endl;
        return out;
    }
};




#endif //VECTOR_MSVECTOR_H
