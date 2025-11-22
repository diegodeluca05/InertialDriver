#include<iostream>
#include"lettura.h"
#ifndef MISURA_H
#define MISURA_H
class Misura 
{
    private:
    static const int size = 17;
    Lettura arr[size];
    public:
    class Invalid {};
    explicit Misura() {};
    explicit Misura(const Lettura first[size]) {
        for(int i=0; i<size; i++) {
            arr[i] = first[i];
        }
    }
    void print();
    Lettura* getArray();
    Lettura operator[](int index) const;
    Lettura& operator[](int index);

};
#endif
