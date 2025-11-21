#include "myVector.h"
#include <iostream>

using namespace std;

// --- IMPLEMENTAZIONE DEI METODI ---

template <typename T>
myVector<T>::myVector(int s) : count(s), sz(s), elem(new T[s]) {
    if(s == 0) 
        elem = nullptr;
    else {
        for (int i = 0; i < s; ++i)
            elem[i] = T(); 
    }
}

template <typename T>
myVector<T>::myVector(const myVector<T>& arg) 
    : sz{arg.sz}, count{arg.count}, elem{new T[arg.sz]}
{
    for(int i = 0; i < sz; ++i) {
        elem[i] = arg.elem[i];
    }
}

template <typename T>
myVector<T>::myVector(initializer_list<T> lst) 
    : sz(static_cast<int>(lst.size())), count(static_cast<int>(lst.size())), elem{new T[sz]}
{
    int i = 0;
    for(const T& val : lst) {
        elem[i] = val;
        i++;
    }
    cout << "operatore <> overload " << endl;
}

template <typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& a)
{
    if (this == &a) return *this;

    T* p = new T[a.sz];
    for(int i = 0; i < a.sz; ++i) {
        p[i] = a.elem[i];
    }

    delete[] elem;
    elem = p;
    sz = a.sz;
    count = a.count;
    cout << "uso operator= overload";
    return *this;
}

template <typename T>
myVector<T>::myVector(myVector<T>&& a) 
    : sz{a.sz}, count{a.count}, elem{a.elem}
{
    a.sz = 0;
    a.count = 0;
    a.elem = nullptr;
}

template <typename T>
myVector<T>& myVector<T>::operator=(myVector<T>&& a)
{
    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    count = a.count;
    
    a.elem = nullptr;
    a.sz = 0;
    a.count = 0;
    
    cout << "operatore = move (overciola) " << endl;
    return *this;
}

template <typename T>
myVector<T>::~myVector() {
    delete[] elem;
}

template <typename T>
T& myVector<T>::operator[](int c) {
    return elem[c];
}

template <typename T>
const T& myVector<T>::operator[](int c) const {
    return elem[c];
}

template <typename T>
T& myVector<T>::at(int n) {
    if (n >= count || n < 0)
        throw typename myVector<T>::Invalid();
    return elem[n];
}

template <typename T>
const T& myVector<T>::at(int n) const {
    if (n >= count || n < 0)
        throw typename myVector<T>::Invalid();
    return elem[n];
}

template <typename T>
void myVector<T>::reserve(int n) {
    if (sz >= n) return;

    T* p = new T[n];
    for (int i = 0; i < count; ++i) {
        p[i] = elem[i]; 
    }

    delete[] elem;
    elem = p;
    sz = n;
}

template <typename T>
void myVector<T>::push_back(const T& el) {
    if (count == sz) {
        int newCap = (sz == 0) ? 1 : sz * 2;
        reserve(newCap);
    }
    elem[count++] = el;
}

template <typename T>
void myVector<T>::pop_back() {
    if (count > 0)
        --count;
    else
        throw typename myVector<T>::Invalid();
}

template <typename T>
void myVector<T>::print()
{
    for(int i = 0; i < count; i++)
    {
        cout << elem[i] << endl; 
    }
}

// ==============================================
// ISTANZIAZIONE ESPLICITA (Fondamentale!)
// Senza queste righe, avrai errori di linker se separi .h e .cpp
// ==============================================

// Genera il codice per int
template class myVector<int>;

// Genera il codice per double
template class myVector<double>;
template class myVector<std::string>;

// Se ti servono stringhe, scommenta la riga sotto:
// #include <string>
// template class myVector<std::string>;
