#ifndef CIRCULARARRAY_H
#define CIRCULARARRAY_H

#include "ArrayDati.h"
#include <vector>
#include <stdexcept> // Per std::out_of_range

class CircularArray {
private:
    std::vector<ArrayDati*> buffer;     // Buffer circolare di puntatori
    int BUFFER_DIM;                     // Dimensione massima del buffer
    int head, tail;                     // Indice di testa e di coda
    int dataSize;                       // Numero di elementi attualmente nel buffer

public:
    // Costruttore: inizializza il buffer con la capacità specificata
    explicit CircularArray(int size = 10) : buffer(size, nullptr), BUFFER_DIM(size), head(0), tail(0), dataSize(0) {}

    // Distruttore: dealloca tutti gli oggetti ancora presenti nel buffer
    ~CircularArray(){
        for(auto ptr : buffer){
            delete ptr;
        }
    }

    // Metodo per inserire un oggetto nel buffer
    void enque(ArrayDati*);

    // Metodo per rimuovere l'oggetto più vecchio (FIFO)
    ArrayDati* deque();

    // Metodo per ottenere il numero di elementi nel buffer
    int getSize() const;

    // Metodo per controllare se il buffer è vuoto
    bool isEmpty() const;

    // Metodo per controllare se il buffer è pieno
    bool isFull() const;

    // Metodo per accedere agli elementi tramite indice relativo
    ArrayDati* operator[](int indice) const;

    // Metodo per stampare lo stato del buffer
    void print(std::ostream& os = std::cout) const;

    // Overloading dell'operatore di stampa <<
    friend std::ostream& operator<<(std::ostream& os, const CircularArray& array);
};

#endif // CIRCULARARRAY_H
