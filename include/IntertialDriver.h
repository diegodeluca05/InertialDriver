#include "myVector.h"
#include "lettura.h"
#include "misura.h"
#include <iostream>
    const int dimbuffer=2;

class InertialDriver {
    private:
    myVector<Misura> first;

    public:
    class Invalid {};
    explicit InertialDriver() : first(dimbuffer) {};
    
    void print(); 

};
