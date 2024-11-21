#include <iostream>

class ArrayCircolareDouble{
    public:
    ArrayCircolareDouble(int);
    void enqueue(double);
    double dequeue();
    private:
    int BUFFER_DIM; //grandezza buffer
    int dataSize = 0; //numero dati caricati nel vettore
    double* array; //puntatore al vettore
    int head, tail; //testa e coda del vettore, inizializzati a 0
};