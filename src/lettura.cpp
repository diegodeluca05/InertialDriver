#include"../include/lettura.h"
#include <iostream>

Lettura::Lettura(std::initializer_list<double> lst){
        if (lst.size() != 6) {
            throw Invalid();
        }
        else
        {
            const double* ptr = lst.begin();

            yaw_v   = ptr[0];
            yaw_a   = ptr[1];
            pitch_v = ptr[2];
            pitch_a = ptr[3];
            roll_v  = ptr[4];
            roll_a  = ptr[5];

            std::cout << "Initializer list di Lettura" << std::endl;;
    }
            
        }


Lettura& Lettura::operator=(const Lettura& other) 
{
    if (this != &other) {
        yaw_v   = other.yaw_v;
        yaw_a   = other.yaw_a;
        pitch_v = other.pitch_v;
        pitch_a = other.pitch_a;
        roll_v  = other.roll_v;
        roll_a  = other.roll_a;
    }
    return *this;
}
void Lettura::print()
{
    std::cout << "Yaw Velocity: " << yaw_v << ", Yaw Acceleration: " << yaw_a << std::endl;
    std::cout << "Pitch Velocity: " << pitch_v << ", Pitch Acceleration: " << pitch_a << std::endl;
    std::cout << "Roll Velocity: " << roll_v << ", Roll Acceleration: " << roll_a << std::endl;
 }
std::ostream& operator<<(std::ostream& os, const Lettura& l) {
    os << "Yaw Velocity: " << l.getYawV() << ", Yaw Acceleration: " << l.getYawA() << "\n"
       << "Pitch Velocity: " << l.getPitchV() << ", Pitch Acceleration: " << l.getPitchA() << "\n"
       << "Roll Velocity: " << l.getRollV() << ", Roll Acceleration: " << l.getRollA();
    return os;
}
double Lettura::getYawV() const {
    return yaw_v;
}
double Lettura::getYawA() const {
    return yaw_a;
}
double Lettura::getPitchV() const { 
    return pitch_v;
}
double Lettura::getPitchA() const {
    return pitch_a;
}
double Lettura::getRollV() const {         
    return roll_v;
}
double Lettura::getRollA() const {
    return roll_a;  
}   
