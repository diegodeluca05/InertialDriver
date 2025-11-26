#include <iostream>
#include "../include/lettura.h"
#include "../include/misura.h"
#include "../include/myVector.h"  
#include "../include/InertialDriver.h"
using namespace std;

int main() {
    // Crea un oggetto InertialDriver con un buffer di 2 misure (BUFFER_DIM = 2)
    InertialDriver driver;

    // Crea alcune letture (esempio) per ogni sensore
    Lettura letture1[17] = {
        Lettura({1.11, 2.12, 3.13, 4.14, 5.15, 6.16}),
        Lettura({1.21, 2.22, 3.23, 4.24, 5.25, 6.26}),
        Lettura({1.31, 2.32, 3.33, 4.34, 5.35, 6.36}),
        Lettura({1.41, 2.42, 3.43, 4.44, 5.45, 6.46}),
        Lettura({1.51, 2.52, 3.53, 4.54, 5.55, 6.56}),
        Lettura({1.61, 2.62, 3.63, 4.64, 5.65, 6.66}),
        Lettura({1.71, 2.72, 3.73, 4.74, 5.75, 6.76}),
        Lettura({1.81, 2.82, 3.83, 4.84, 5.85, 6.86}),
        Lettura({1.91, 2.92, 3.93, 4.94, 5.95, 6.96}),
        Lettura({2.02, 3.03, 4.04, 5.05, 6.06, 7.07}),
        Lettura({2.12, 3.23, 4.34, 5.45, 6.56, 7.67}),
        Lettura({2.22, 3.33, 4.44, 5.55, 6.66, 7.77}),
        Lettura({2.32, 3.43, 4.54, 5.65, 6.76, 7.87}),
        Lettura({2.42, 3.53, 4.64, 5.75, 6.86, 7.97}),
        Lettura({2.52, 3.63, 4.74, 5.85, 6.96, 8.07}),
        Lettura({2.62, 3.73, 4.84, 5.95, 7.06, 8.17}),
        Lettura({2.72, 3.83, 4.94, 6.06, 7.17, 8.28})
    };

    Lettura letture2[17] = {
        Lettura({1.02, 2.03, 3.04, 4.05, 5.06, 6.07}),
        Lettura({1.12, 2.13, 3.14, 4.15, 5.16, 6.17}),
        Lettura({1.22, 2.23, 3.24, 4.25, 5.26, 6.27}),
        Lettura({1.32, 2.33, 3.34, 4.35, 5.36, 6.37}),
        Lettura({1.42, 2.43, 3.44, 4.45, 5.46, 6.47}),
        Lettura({1.52, 2.53, 3.54, 4.55, 5.56, 6.57}),
        Lettura({1.62, 2.63, 3.64, 4.65, 5.66, 6.67}),
        Lettura({1.72, 2.73, 3.74, 4.75, 5.76, 6.77}),
        Lettura({1.82, 2.83, 3.84, 4.85, 5.86, 6.87}),
        Lettura({1.92, 2.93, 3.94, 4.95, 5.96, 6.97}),
        Lettura({2.02, 3.03, 4.04, 5.05, 6.06, 7.07}),
        Lettura({2.12, 3.23, 4.34, 5.45, 6.56, 7.67}),
        Lettura({2.12, 3.13, 4.14, 5.15, 6.16, 7.17}),
        Lettura({2.22, 3.23, 4.24, 5.25, 6.26, 7.27}),
        Lettura({2.32, 3.33, 4.34, 5.35, 6.36, 7.37}),
        Lettura({2.42, 3.43, 4.44, 5.45, 6.46, 7.47}),
        Lettura({2.52, 3.53, 4.54, 5.55, 6.56, 7.57})
    };

    Lettura letture3[17] = {
        Lettura({3.04, 4.05, 5.06, 6.07, 7.08, 8.09}),
        Lettura({3.14, 4.15, 5.16, 6.17, 7.18, 8.19}),
        Lettura({3.24, 4.25, 5.26, 6.27, 7.28, 8.29}),
        Lettura({3.34, 4.35, 5.36, 6.37, 7.38, 8.39}),
        Lettura({3.44, 4.45, 5.46, 6.47, 7.48, 8.49}),
        Lettura({3.54, 4.55, 5.56, 6.57, 7.58, 8.59}),
        Lettura({3.64, 4.65, 5.66, 6.67, 7.68, 8.69}),
        Lettura({3.74, 4.75, 5.76, 6.77, 7.78, 8.79}),
        Lettura({3.84, 4.85, 5.86, 6.87, 7.88, 8.89}),
        Lettura({3.94, 4.95, 5.96, 6.97, 7.98, 8.99}),
        Lettura({4.04, 5.05, 6.06, 7.07, 8.08, 9.09}),
        Lettura({4.14, 5.15, 6.16, 7.17, 8.18, 9.19}),
        Lettura({4.24, 5.25, 6.26, 7.27, 8.28, 9.29}),
        Lettura({4.34, 5.35, 6.36, 7.37, 8.38, 9.39}),
        Lettura({4.44, 5.45, 6.46, 7.47, 8.48, 9.49}),
        Lettura({4.54, 5.55, 6.56, 7.57, 8.58, 9.59}),
        Lettura({4.57, 5.78, 6.46, 7.65, 8.75, 9.76})
    };

    Lettura letture4[17] = {
        Lettura({5.06, 6.07, 7.08, 8.09, 9.10, 10.11}),
        Lettura({5.16, 6.17, 7.18, 8.19, 9.20, 10.21}),
        Lettura({5.26, 6.27, 7.28, 8.29, 9.30, 10.31}),
        Lettura({5.36, 6.37, 7.38, 8.39, 9.40, 10.41}),
        Lettura({5.46, 6.47, 7.48, 8.49, 9.50, 10.51}),
        Lettura({5.56, 6.57, 7.58, 8.59, 9.60, 10.61}),
        Lettura({5.66, 6.67, 7.68, 8.69, 9.70, 10.71}),
        Lettura({5.76, 6.77, 7.78, 8.79, 9.80, 10.81}),
        Lettura({5.86, 6.87, 7.88, 8.89, 9.90, 10.91}),
        Lettura({5.96, 6.97, 7.98, 8.99, 9.00, 10.01}),
        Lettura({6.06, 7.07, 8.08, 9.09, 10.10, 11.11}),
        Lettura({6.16, 7.17, 8.18, 9.19, 10.20, 11.21}),
        Lettura({6.26, 7.27, 8.28, 9.29, 10.30, 11.31}),
        Lettura({6.36, 7.37, 8.38, 9.39, 10.40, 11.41}),
        Lettura({6.46, 7.47, 8.48, 9.49, 10.50, 11.51}),
        Lettura({6.56, 7.57, 8.58, 9.59, 10.60, 11.61}),
        Lettura({6.66, 7.67, 8.68, 9.69, 10.70, 11.71})
    };
    
    Misura mis1(letture1);
    Misura mis2(letture2);
    Misura mis3(letture3);
    Misura mis4(letture4);

    driver.push_back(mis1);
    driver.push_back(mis2);
    driver.push_back(mis3);
    cout<<driver<<endl;



    /*
    // Crea alcune misure con 17 letture ciascuna
    Misura mis1(letture);
    driver.print();
    Misura mis2(letture1);
    Misura mis3(letture2);
    Misura mis4(letture3);


    // Aggiungi le misure al buffer (driver ha un buffer circolare di dimensione 2)
    driver.push_back(mis1);
    driver.print();
    driver.get_reading(0).print();
    cout<<"primo push valido"<<endl;
    driver.push_back(mis2);
    driver.print();
    cout<<"secondo push valido"<<endl;
    cout<<"terzo push valido? no dimensione buffer=2"<<endl;
    driver.push_back(mis3);  // La mis3 sovrascriverà mis1 perché il buffer è di dimensione 2

    // Stampa il contenuto dell'ultima misura nel buffer usando l'operatore <<
    cout << "Ultima misura salvata dopo il primo ciclo di inserimenti:" << endl;
    cout << driver << endl;

    // Aggiungi un'altra misura per vedere come funziona la sovrascrittura
    driver.push_back(mis4);  // La misura più vecchia sarà sovrascritta (mis2)
    driver.pop_front(); // rimuove mis3
    driver.print();
    cout<<"dopo pop front"<<endl;

    // Stampa l'ultima misura dopo la sovrascrittura
    cout << "Ultima misura salvata dopo la sovrascrittura:" << endl;
    cout << driver << endl;

    return 0;
    */
}
