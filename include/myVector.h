#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <initializer_list> // Necessario per std::initializer_list
#include <utility>          // Utile per std::move

// 1. Dichiarazione del template
template <typename T>
class myVector {
    int count;   // numero di elementi effettivi
    int sz;      // capacità del buffer
    T* elem;     // 2. Puntatore agli elementi (ora di tipo T, non più double)

public:
    class Invalid {}; // viene lanciata in caso di eccezioni 

    explicit myVector(int s); // costruttore (explicit è consigliato per costruttori con 1 argomento)
    ~myVector(); // distruttore 

    myVector(std::initializer_list<T> lst); // 3. La lista ora accetta tipo T
    myVector(const myVector& a); // deep copy (Costruttore di copia)
    myVector& operator=(const myVector& a); // overloading operatore = per la copia

    // NOTA: Ho corretto i commenti qui sotto, erano errati nell'originale
    myVector(myVector&& a); // Costruttore di movimento (Move Constructor)
    myVector& operator=(myVector&& a); // Assegnamento di movimento (Move Assignment)

    T& operator[](int c); // 4. Restituisce un riferimento a T
    const T& operator[](int c) const; // Restituisce un riferimento const a T

    T& at(int n); // 5. Metodo at restituisce T
    const T& at(int n) const; 

    void reserve(int n); 
    void push_back(const T& el); // 6. Accetta un elemento di tipo T
    void pop_back();

    int size() const { return count; } 
    int capacity() const { return sz; }
    
    void print(); // Stampa (attenzione: T deve supportare l'operatore <<)
};

#include "myVector.hpp"

#endif
