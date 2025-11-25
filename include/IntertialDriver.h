// ...existing code...
#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include "myVector.h"
#include "lettura.h"
#include "misura.h"
#include <iostream>

constexpr int dimbuffer = 2;

class InertialDriver {
private:
    myVector<Misura> buffer;   // buffer circolare delle misure
    int pnttr;                 // indice del primo spazio libero (tail)
    int count;                 // numero di elementi attualmente presenti

public:
    class Invalid {};

    explicit InertialDriver();

    void print();
    Misura pop_front();
    void push_back(const Misura mis);
    void clear_buffer();
    Lettura get_reading(int num) const;

    friend std::ostream& operator<<(std::ostream& os, const InertialDriver& driver);
};

#endif // INERTIALDRIVER_H
// ...existing code...
