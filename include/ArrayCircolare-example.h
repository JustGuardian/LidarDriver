#ifndef ARRAYCIRCOLARE_H
#define ARRAYCIRCOLARE_H

#include <iostream>
#include <stdexcept>

class arrayCircolare {
private:
    double* buffer;       // Puntatore per array dinamico
    int size;          // Dimensione dell'array
    int head = 0;
    int tail = 0;
    bool is_full = false;

public:
    explicit arrayCircolare(int dimensione) : size(dimensione), buffer(new double[dimensione]) {}; // Costruttore con dimensione
    ~arrayCircolare();        // Distruttore per liberare memoria

    double* 

    void enqueue(double value);  // Aggiungi un elemento
    double dequeue();            // Rimuovi un elemento
    void print() const;       // Stampa i dati
};

#endif // ARRAYCIRCOLARE_H


