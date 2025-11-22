#include"../include/misura.h"
#include"../include/lettura.h"
#include<iostream>
void Misura::print() {
    for(int i = 0; i < size; i++) {
        std::cout << "Lettura " << i << " :" << std::endl;
        std::cout << getArray()[i]<<std::endl;
    }
}
Lettura* Misura::getArray() {
    return arr;
}
Lettura Misura::operator[](int index) const {
    if(index < 0 || index >= size) {
        throw Invalid();
    }
    return arr[index];
}
Lettura& Misura::operator[](int index) {
    if(index < 0 || index >= size) {
        throw Invalid();
    }
    return arr[index];
}
