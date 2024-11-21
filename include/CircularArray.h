#ifndef CIRCULARARRAY_H
#define CIRCULARARRAY_H

#include <vector>
#include <stdexcept> // Per std::out_of_range
#include <iostream>

class CircularArray {
private:
    std::vector<std::vector<double>> buffer;    // Buffer circolare di vettori di double
    const int BUFFER_DIM;                       // Dimensione massima del buffer
    int head, tail;                             // Indice di testa e di coda
    int dataSize;                               // Numero di elementi attualmente nel buffer

public:
    // Costruttore: inizializza il buffer con la capacità specificata
    explicit CircularArray(int size = 10) : buffer(size), BUFFER_DIM(size), head(0), tail(0), dataSize(0) {}

    // Distruttore: non è necessario deallocare nulla poiché std::vector si occupa automaticamente della memoria
    ~CircularArray();

    // Metodo per svuotare completamente il buffer
    void clear(); 

    // Metodo per inserire un vettore nel buffer
    void enqueue(const std::vector<double>& elemento);

    // Metodo per rimuovere il vettore più vecchio (FIFO)
    std::vector<double> dequeue();

    // Metodo per ottenere il numero di elementi nel buffer
    int getSize() const;

    // Metodo per controllare se il buffer è vuoto
    bool isEmpty() const;

    // Metodo per controllare se il buffer è pieno
    bool isFull() const;

    // Operatore di confronto per uguaglianza
    bool operator==(const CircularArray& other);

    // Operatore di confronto per disuguaglianza
    bool operator!=(const CircularArray& other);

    // Metodo per accedere agli elementi tramite indice relativo
    std::vector<double>& operator[](int indice);
    const std::vector<double>& operator[](int indice) const;

    // Metodo per stampare lo stato del buffer
    void print(std::ostream& os = std::cout) const;

    // Overloading dell'operatore di stampa <<
    friend std::ostream& operator<<(std::ostream& os, const CircularArray& array);
};

#endif // CIRCULARARRAY_H
