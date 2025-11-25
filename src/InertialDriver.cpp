// ...existing code...
#include <iostream>
#include "../include/myVector.h"
#include "../include/lettura.h"
#include "../include/misura.h"
#include "../include/InertialDriver.h"

using std::cout;
using std::endl;

// Costruttore
InertialDriver::InertialDriver()
    : buffer(dimbuffer), pnttr(0), count(0)
{}

// Stampa semplice (usa l'operatore <<)
void InertialDriver::print() {
    cout << *this << endl;  
    cout << "Buffer size: " << dimbuffer << ", Current count: " << count << ", Next pointer: " << pnttr << endl;
}

// push_back: inserisce una misura nel buffer circolare (sovrascrive la più vecchia se pieno)
void InertialDriver::push_back(const Misura mis) {
    buffer.at(pnttr) = mis;
    pnttr = (pnttr + 1) % dimbuffer;
    if (count < dimbuffer) ++count;
}

// pop_front: restituisce la misura più vecchia e la rimuove dal buffer
Misura InertialDriver::pop_front() {
    if (count == 0) throw Invalid();
    int old = (pnttr - count);
    if (old < 0) old += dimbuffer;
    Misura mis = buffer.at(old);
    buffer.at(old) = Misura(); // azzera la posizione (opzionale)
    --count;
    return mis;
}

// clear_buffer: svuota il buffer
void InertialDriver::clear_buffer() {
    for (int i = 0; i < dimbuffer; ++i) buffer.at(i) = Misura();
    count = 0;
    pnttr = 0;
}

// get_reading: ritorna la lettura num (0..16) della misura più recente (non rimuove)
Lettura InertialDriver::get_reading(int num) const {
    if (num < 0 || num >= 17) throw Invalid();
    if (count == 0) throw Invalid();
    int last_index = (pnttr - 1);
    if (last_index < 0) last_index += dimbuffer;
    const Misura& last = buffer.at(last_index);
    return last[num]; // usa operator[] di Misura
}

// operator<< : stampa l'ultima misura salvata (non la rimuove)
std::ostream& operator<<(std::ostream& os, const InertialDriver& driver) {
    if (driver.count == 0) {
        os << "Buffer vuoto.";
        return os;
    }

    int last_index = (driver.pnttr - 1);
    if (last_index < 0) last_index += dimbuffer;

    const Misura& last_misura = driver.buffer.at(last_index);

    os << "Ultima misura salvata:" << endl;
    for (int i = 0; i < 17; ++i) {
        const Lettura& lettura = last_misura[i];
        // Se Lettura ha metodi getYawV(), ecc. usali. Altrimenti adatta qui.
        os << "Sensore " << i + 1 << ": "
           << "Yaw_v: " << lettura.getYawV() << ", "
           << "Yaw_a: " << lettura.getYawA() << ", "
           << "Pitch_v: " << lettura.getPitchV() << ", "
           << "Pitch_a: " << lettura.getPitchA() << ", "
           << "Roll_v: " << lettura.getRollV() << ", "
           << "Roll_a: " << lettura.getRollA() << '\n';
    }
    return os;
}
// ...existing code...
