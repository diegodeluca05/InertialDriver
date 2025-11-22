#ifndef LETTURA_H
#define LETTURA_H

#include <iostream>
class Lettura 
{
    private:
    const int size = 6;
    double yaw_v;
    double yaw_a;
    double pitch_v;
    double pitch_a;
    double roll_v;
    double roll_a;

    public:
    class Invalid {};
    explicit Lettura():yaw_a(0), yaw_v(0), pitch_a(0), pitch_v(0), roll_a(0), roll_v(0) {}
    explicit Lettura(double yv, double ya, double pv, double pa, double rv, double ra):
        yaw_v(yv), yaw_a(ya), pitch_v(pv), pitch_a(pa), roll_v(rv), roll_a(ra) {}
    
    double getYawV() const;
    double getYawA() const;
    double getPitchV() const;
    double getPitchA() const;
    double getRollV() const;
    double getRollA() const;


    void print();
    Lettura(std::initializer_list<double> lst);
Lettura& operator=(const Lettura& other);


};
std::ostream& operator<<(std::ostream& os, const Lettura& l);
#endif
