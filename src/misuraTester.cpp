#include<iostream>
#include"../include/lettura.h"
#include"../include/misura.h"


int main() {
    // 1. Creiamo 17 Lettura diverse
    Lettura letture[17];
    for (int i = 0; i < 17; ++i) {
        letture[i] = Lettura(
            i * 1.0,   // yaw_v
            i * 2.0,   // yaw_a
            i * 3.0,   // pitch_v
            i * 4.0,   // pitch_a
            i * 5.0,   // roll_v
            i * 6.0    // roll_a
        );
    }

    // 2. Creiamo la misura
    Misura m(letture);

    // 3. Test operator[]
    std::cout << "Test accesso operator[]:\n";
    for (int i = 0; i < 17; ++i) {
        std::cout << "Sensore " << i << ": " << m[i] << "\n";
    }

    // 4. Test data()
    std::cout << "\nTest data():\n";
    const Lettura* arr = m.getArray();
    for (int i = 0; i < 17; ++i) {
        std::cout << "From data() sensore " << i << ": " << arr[i] << "\n";
    }

    std::cout << "\nTEST COMPLETATO.\n";
    return 0;
}
