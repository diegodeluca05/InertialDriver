#include <iostream>
#include "../include/myVector.h"
#include "../include/lettura.h"
#include "../include/misura.h"
#include "../include/InertialDriver.h"

using std::cout;
using std::endl;

// Costruttore
InertialDriver::InertialDriver()
    : buffer(BUFFER_DIM), pnttr(0), count(0)
{}



// push_back: inserisce una misura nel buffer circolare (sovrascrive la più vecchia se pieno)
void InertialDriver::push_back(const Misura& mis) {
    buffer.at(pnttr) = mis;
    pnttr = (pnttr + 1) % BUFFER_DIM;
    if (count < BUFFER_DIM) ++count;
}

// pop_front: restituisce la misura più vecchia e la rimuove dal buffer
Misura InertialDriver::pop_front() {
    if (count == 0) throw Invalid();
    int old = (pnttr - count);
    if (old < 0) old += BUFFER_DIM;
    Misura mis = buffer.at(old);
    buffer.at(old) = Misura(); // azzera la posizione (opzionale)
    --count;
    return mis;
}

// clear_buffer: svuota il buffer
void InertialDriver::clear_buffer() {
    for (int i = 0; i < BUFFER_DIM; ++i) buffer.at(i) = Misura();
    count = 0;
    pnttr = 0;
}

// get_reading: ritorna la lettura num (0..16) della misura più recente (non rimuove)
Lettura InertialDriver::get_reading(int num) const {
    if (num < 0 || num >= 17) throw Invalid();
    if (count == 0) throw Invalid();
    int last_index = (pnttr - 1);
    if (last_index < 0) last_index += BUFFER_DIM;
    const Misura& last = buffer.at(last_index);
    return last[num]; // usa operator[] di Misura
}

//metodo che ritorna l'ultima  misura sottoforma di stringa
std::string InertialDriver::printLastMisura(){
    std::ostringstream output;

    if(count == 0){
        output << "Buffer vuoto";
        return output.str(); 
    }

    int lastIndex = pnttr-1;
    if(lastIndex < 0) lastIndex += BUFFER_DIM;

    const Misura& lastMisura = buffer.at(lastIndex);

    output << "Ultima misura salvata: \n";
    for (int i = 0; i < 17; i++)
    {
        const Lettura& lettura = lastMisura[i];
        output 
                << "[Yaw_v: " << lettura.getYawV() << ", "
                << "Yaw_a: " << lettura.getYawA() << ", "
                << "Pitch_v: " << lettura.getPitchV() << ", "
                << "Pitch_a: " << lettura.getPitchA() << ", "
                << "Roll_v: " << lettura.getRollV() << ", "
                << "Roll_a: " << lettura.getRollA() << "]\n";   
    }
    return output.str();
    

}






// operator<< : stampa l'ultima misura salvata (non la rimuove)
std::ostream& operator<<(std::ostream& os,  InertialDriver& driver) {


    return os << driver.printLastMisura();

}




