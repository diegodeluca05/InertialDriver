#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include <iostream>
#include "myVector.h"
#include "lettura.h"
#include "misura.h"

class InertialDriver {
private:
    static const int BUFFER_DIM = 2;

    int pnttr;       // Puntatore alla prossima posizione libera
    int count;       // Numero di elementi attualmente nel buffer
    myVector<Misura> buffer;

public:
    class Invalid {};

    // Costruttore
    explicit InertialDriver();

    // Aggiunge una misura nel buffer
    void push_back(const Misura mis);

    // Rimuove la misura più vecchia
    Misura pop_front();

    // Svuota il buffer
    void clear_buffer();

    Lettura get_reading(int num);

    friend std::ostream& operator<<(std::ostream& os, const InertialDriver& driver);
};

#endif
