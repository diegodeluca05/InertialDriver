#include <iostream>
#include "../include/IntertialDriver.h"
#include "../include/lettura.h"
#include "../include/misura.h"

using namespace std;

int main() {
    // Crea un oggetto InertialDriver con un buffer di 2 misure (BUFFER_DIM = 2)
    InertialDriver driver;

    // Crea alcune letture (esempio) per ogni sensore
    Lettura letture[17] = {
        {1.1, 2.1, 3.1, 4.1, 5.1, 6.1},
        {1.2, 2.2, 3.2, 4.2, 5.2, 6.2},
        {1.3, 2.3, 3.3, 4.3, 5.3, 6.3},
        {1.4, 2.4, 3.4, 4.4, 5.4, 6.4},
        {1.5, 2.5, 3.5, 4.5, 5.5, 6.5},
        {1.6, 2.6, 3.6, 4.6, 5.6, 6.6},
        {1.7, 2.7, 3.7, 4.7, 5.7, 6.7},
        {1.8, 2.8, 3.8, 4.8, 5.8, 6.8},
        {1.9, 2.9, 3.9, 4.9, 5.9, 6.9},
        {2.0, 3.0, 4.0, 5.0, 6.0, 7.0},
        {2.1, 3.1, 4.1, 5.1, 6.1, 7.1},
        {2.2, 3.2, 4.2, 5.2, 6.2, 7.2},
        {2.3, 3.3, 4.3, 5.3, 6.3, 7.3},
        {2.4, 3.4, 4.4, 5.4, 6.4, 7.4},
        {2.5, 3.5, 4.5, 5.5, 6.5, 7.5},
        {2.6, 3.6, 4.6, 5.6, 6.6, 7.6},
        {2.7, 3.7, 4.7, 5.7, 6.7, 7.7}
    };

    Lettura letture1[17] = {
        Lettura({1.0, 2.0, 3.0, 4.0, 5.0, 6.0}),
        Lettura({1.1, 2.1, 3.1, 4.1, 5.1, 6.1}),
        Lettura({1.2, 2.2, 3.2, 4.2, 5.2, 6.2}),
        Lettura({1.3, 2.3, 3.3, 4.3, 5.3, 6.3}),
        Lettura({1.4, 2.4, 3.4, 4.4, 5.4, 6.4}),
        Lettura({1.5, 2.5, 3.5, 4.5, 5.5, 6.5}),
        Lettura({1.6, 2.6, 3.6, 4.6, 5.6, 6.6}),
        Lettura({1.7, 2.7, 3.7, 4.7, 5.7, 6.7}),
        Lettura({1.8, 2.8, 3.8, 4.8, 5.8, 6.8}),
        Lettura({1.9, 2.9, 3.9, 4.9, 5.9, 6.9}),
        Lettura({2.0, 3.0, 4.0, 5.0, 6.0, 7.0}),
        Lettura({2.1, 3.1, 4.1, 5.1, 6.1, 7.1}),
        Lettura({2.2, 3.2, 4.2, 5.2, 6.2, 7.2}),
        Lettura({2.3, 3.3, 4.3, 5.3, 6.3, 7.3}),
        Lettura({2.4, 3.4, 4.4, 5.4, 6.4, 7.4}),
        Lettura({2.5, 3.5, 4.5, 5.5, 6.5, 7.5}),
        Lettura({2.6, 3.6, 4.6, 5.6, 6.6, 7.6})
    };

    Lettura letture2[17] = {
        Lettura({3.0, 4.0, 5.0, 6.0, 7.0, 8.0}),
        Lettura({3.1, 4.1, 5.1, 6.1, 7.1, 8.1}),
        Lettura({3.2, 4.2, 5.2, 6.2, 7.2, 8.2}),
        Lettura({3.3, 4.3, 5.3, 6.3, 7.3, 8.3}),
        Lettura({3.4, 4.4, 5.4, 6.4, 7.4, 8.4}),
        Lettura({3.5, 4.5, 5.5, 6.5, 7.5, 8.5}),
        Lettura({3.6, 4.6, 5.6, 6.6, 7.6, 8.6}),
        Lettura({3.7, 4.7, 5.7, 6.7, 7.7, 8.7}),
        Lettura({3.8, 4.8, 5.8, 6.8, 7.8, 8.8}),
        Lettura({3.9, 4.9, 5.9, 6.9, 7.9, 8.9}),
        Lettura({4.0, 5.0, 6.0, 7.0, 8.0, 9.0}),
        Lettura({4.1, 5.1, 6.1, 7.1, 8.1, 9.1}),
        Lettura({4.2, 5.2, 6.2, 7.2, 8.2, 9.2}),
        Lettura({4.3, 5.3, 6.3, 7.3, 8.3, 9.3}),
        Lettura({4.4, 5.4, 6.4, 7.4, 8.4, 9.4}),
        Lettura({4.5, 5.5, 6.5, 7.5, 8.5, 9.5}),
        Lettura({4.6, 5.6, 6.6, 7.6, 8.6, 9.6})
    };

    Lettura letture3[17] = {
        Lettura({5.0, 6.0, 7.0, 8.0, 9.0, 10.0}),
        Lettura({5.1, 6.1, 7.1, 8.1, 9.1, 10.1}),
        Lettura({5.2, 6.2, 7.2, 8.2, 9.2, 10.2}),
        Lettura({5.3, 6.3, 7.3, 8.3, 9.3, 10.3}),
        Lettura({5.4, 6.4, 7.4, 8.4, 9.4, 10.4}),
        Lettura({5.5, 6.5, 7.5, 8.5, 9.5, 10.5}),
        Lettura({5.6, 6.6, 7.6, 8.6, 9.6, 10.6}),
        Lettura({5.7, 6.7, 7.7, 8.7, 9.7, 10.7}),
        Lettura({5.8, 6.8, 7.8, 8.8, 9.8, 10.8}),
        Lettura({5.9, 6.9, 7.9, 8.9, 9.9, 10.9}),
        Lettura({6.0, 7.0, 8.0, 9.0, 10.0, 11.0}),
        Lettura({6.1, 7.1, 8.1, 9.1, 10.1, 11.1}),
        Lettura({6.2, 7.2, 8.2, 9.2, 10.2, 11.2}),
        Lettura({6.3, 7.3, 8.3, 9.3, 10.3, 11.3}),
        Lettura({6.4, 7.4, 8.4, 9.4, 10.4, 11.4}),
        Lettura({6.5, 7.5, 8.5, 9.5, 10.5, 11.5}),
        Lettura({6.6, 7.6, 8.6, 9.6, 10.6, 11.6})
    };
    
    
    // Crea alcune misure con 17 letture ciascuna
    Misura mis1(letture);
    Misura mis2(letture1);
    Misura mis3(letture2);
    Misura mis4(letture3);


    // Aggiungi le misure al buffer (driver ha un buffer circolare di dimensione 2)
    driver.push_back(mis1);
    driver.push_back(mis2);
    driver.push_back(mis3);  // La mis3 sovrascriverà mis1 perché il buffer è di dimensione 2

    // Stampa il contenuto dell'ultima misura nel buffer usando l'operatore <<
    cout << "Ultima misura salvata dopo il primo ciclo di inserimenti:" << endl;
    cout << driver << endl;

    // Aggiungi un'altra misura per vedere come funziona la sovrascrittura
    driver.push_back(mis4);  // La misura più vecchia sarà sovrascritta (mis2)

    // Stampa l'ultima misura dopo la sovrascrittura
    cout << "Ultima misura salvata dopo la sovrascrittura:" << endl;
    cout << driver << endl;

    return 0;
}

