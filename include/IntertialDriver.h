#include<iostream>



class lettura{
    double yaw_v;
    double yaw_a;
    double pitch_v;
    double pitch_a;
    double roll_v;
    double roll_a;
    
};

class InertialDriver {
    private:
        lettura misura[17];
        static const int BUFFER_DIM=10; //numero a caso da cambiare
        int puntantore=0; //puntatore che riporta la prima posizione libera 

    public:
        void push_back(const lettura (&arr)[17] ){ //accetta un array stile C contenente una misura e la memorizza nel buffer 

        }
        lettura* pop_front(){ // fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer; (restituisce un riferimento alla prima posizone dell'array)


        }
        void clear_buffet(){ // elimina (senza restituirle) tutte le misure salvate;

        }
        lettura get_reading(int num) { //accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer;

        }



};
