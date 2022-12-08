#include "MSVector.h"

template<class T>
MSVector<T>::MSVector() {
    Capacity = 0;
    Size = 0;
    vector = new T[Capacity];
}

template<class T>
MSVector<T>::MSVector(int sz) {
    Size = sz;
    Capacity = 2;
    while (Capacity <= Size) {
        Capacity *= 2;
    }
    vector = new T[Capacity];
    //Initialize vector to empty either zero or empty string
}

template<class T>
MSVector<T>::MSVector(T *ptr, int n) {
    //check this! how to call the constructor here
    Size = n;
    Capacity = 2;
    while (Capacity <= Size) {
        Capacity *= 2;
    }
    vector = new T[Capacity];
    for (int i = 0; i < Size; ++i) {
        vector[i] = ptr[i];
    }
}

template<class T>
MSVector<T>::MSVector(const MSVector &otherVector) {
    this->Size = otherVector.Size;
    this->Capacity = otherVector.Capacity;
    vector = nullptr;
    vector = new T[Capacity];
    for (int i = 0; i < otherVector.Size; ++i) {
        this->vector[i] = otherVector.vector[i];
    }
}

template<class T>
MSVector<T>::~MSVector() {
    delete[] vector;
}

template<class T>
MSVector<T> &MSVector<T>::operator=(const MSVector<T> &otherVector) {
    if (this->vector != otherVector.vector) {
        //check this! how to call the constructor here
        this->Size = otherVector.Size;
        this->Capacity = otherVector.Capacity;
        vector = nullptr;
        vector = new T[Capacity];
        for (int i = 0; i < otherVector.Size; ++i) {
            this->vector[i] = otherVector.vector[i];
        }
    }
    return *this;
}

template<class T>
MSVector<int> MSVector<T>::operator=(MSVector<T> && otherVector) noexcept {
    //noexcept?? means it throws no exceptions
    //we removed const from the parameter of the move assignment
    if (this->vector != otherVector.vector) {
        //check this! how to call the constructor here
        this->Size = otherVector.Size;
        this->Capacity = otherVector.Capacity;
        vector = nullptr;
        vector = new T[Capacity];
        for (int i = 0; i < otherVector.Size; ++i) {
            this->vector[i] = otherVector.vector[i];
        }
        //otherVector.vector = nullptr;
        delete[] otherVector.vector;
        otherVector.Size = 0;
        otherVector.Capacity = 0;
    }
    return *this;
}

template<class T>
T &MSVector<T>::operator[](int index) {
    try {
        if (index < 0 || index >= Size)
            throw " Index is Out of Range!\n";
        return vector[index];
    } catch (const char* error) {
        cout << "ERR 101 -> ";
        cerr << error;
        exit(101);
    }
}

template<class T>
int MSVector<T>::push_back(T val) {
    if (Size < Capacity) {
        if (Size == 0)
            this->vector = new T[Capacity + 2];
        this->vector[Size++] = val;
    } else {
        if (Capacity == 0)
            Capacity++;
        Capacity *= 2;
        T *tmpVector = new T[Capacity];
        for (int i = 0; i < Size; ++i) {
            tmpVector[i] = vector[i];
        }
        tmpVector[Size++] = val;

        //Dif between nutllptr and delete
        delete[] this->vector;
        vector = tmpVector;
        tmpVector = nullptr;
    }

    return Size;
}

template<class T>
T MSVector<T>::pop_back() {
    Size--;
    return vector[Size - 1];
}

template<class T>
void MSVector<T>::erase(T* itr) {
    try {
        if (itr - vector < 0 || itr - vector >= Size)
            throw " Invalid Iterator!\n";
        for (int i = itr - vector; i < Size - 1; ++i) {
            *(vector + i) = *(vector + i + 1);
        }
        Size--;
    } catch(const char* error) {
        cerr << error << endl;
        cout << "ERR 105 -> ";
        exit(105);
    }

}

template<class T>
void MSVector<T>::erase(T* itr1, T* itr2) {
    if (itr2 - vector >= itr1 - vector) {
        try {
            if (itr1 - vector < 0 || itr1 - vector >= Size || itr2 - vector < 0 || itr2 - vector >= Size)
                throw " Invalid Iterator!\n";
            Size -= ((itr2 - vector) - (itr1 - vector));
            Size--;
            for (int i = itr1 - vector; i < Size; ++i) {
                *(vector + i) = *(vector + i + ((itr2 - vector) - (itr1 - vector)) + 1);
            }
        } catch(const char* error) {
            cerr << error << endl;
            cout << "ERR 111 -> ";
            exit(111);
        }
    }
}

template<class T>
void MSVector<T>::clear() {
    delete[] this->vector;
    Size = 0;
    Capacity = 2;
}

template<class T>
void MSVector<T>::insert(T* itr, T val) {
    Size++;
    if (Size >= Capacity) {
        for (int i = Size - 1; i >= itr - vector; --i) {
            vector[i + 1] = vector[i];
        }
        vector[itr - vector] = val;
    } else {
        Capacity *= 2;
        for (int i = Size - 1; i >= itr - vector; --i) {
            vector[i + 1] = vector[i];
        }
        vector[itr - vector] = val;
    }
}

template<class T>
T* MSVector<T>::begin() {
    return vector;
}

template<class T>
T* MSVector<T>::end() {
    return vector + Size - 1;
}

template<class T>
bool MSVector<T>::operator==(const MSVector<T> &otherVector) {
    if (this->Size == otherVector.Size) {
        for (int i = 0; i < Size; ++i) {
            if (this->vector[i] != otherVector.vector[i])
                return false;
        }
    } else {
        return false;
    }
    return true;
}

template<class T>
bool MSVector<T>::operator<(const MSVector<T> &otherVector) {
    //Check if this needs to make sure that the sizes of the 2 vectors are equal
    bool allMinEqual = true;
    for (int i = 0; i < ((Size <= otherVector.Size) ? Size : otherVector.Size); ++i) {
        if (this->vector[i] != otherVector.vector[i]) {
            allMinEqual = false;
            break;
        }
    }
    if (allMinEqual) {
        if (this->Size < otherVector.Size)
            return true;
        return false;
    }

    for (int i = 0; i < ((Size < otherVector.Size) ? Size : otherVector.Size); ++i) {
        if (this->vector[i] > otherVector.vector[i])
            return false;
    }
    return true;
}

template<class T>
int MSVector<T>::size() const {
    return Size;
}

template<class T>
int MSVector<T>::capacity() const {
    return Capacity;
}

template<class T>
int MSVector<T>::resize() {
    return 0;
}

template<class T>
bool MSVector<T>::empty() {
    if (Size > 0)
        return false;
    return true;
}

