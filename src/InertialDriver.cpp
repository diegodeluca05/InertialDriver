#include <iostream>
#include "lettura.h"
#include "myVector.h"
#include "misura.h"
using namespace std;

class InertialDriver {
        const int BUFFER_DIM=2;
    private:
        int pnttr=0; //putnatore che punta al primo spazio libero
        int count=0; //contatore che tiene conto del numero di elementi nel buffer
        myVector<Misura> buffer;


    public:
        class Invalid {};
        explicit InertialDriver() : buffer(BUFFER_DIM) {};
        void print(); 

        void push_back(const Misura mis){ //accetta un array stile C contenente una misura e la memorizza nel buffer 
            buffer.at(pnttr)=mis;
            if (pnttr==BUFFER_DIM-1){
                pnttr=0;
            }
            else {
                pnttr++;
            }

            
            if (count<BUFFER_DIM){
                count++;
            }

        }

        Misura pop_front(){ // fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer; (restituisce un riferimento alla prima posizone dell'array)
            if (count==0) {
                throw Invalid();
            }
            int old=0; //indice dell'elemento più vecchio
            if (pnttr - count < 0) {
                old = (pnttr - count) + BUFFER_DIM;
            }
            else{
                old = pnttr - count;
            }
            Misura mis=buffer.at(old);
            buffer.at(old) = Misura();
            count--;
            return mis;
         }

        void clear_buffet(){ // elimina (senza restituirle) tutte le misure salvate;
            for(int i=0;i<BUFFER_DIM;i++) {
                buffer.at(i)=Misura();
            }
            count=0;
            pnttr=0;
        }



        lettura get_reading(int num) { //accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer;

        }



};
