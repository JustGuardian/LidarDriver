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

/*
#include "arrayCircolare.h"

void arrayCircolare::enqueue(int value) {
    if (is_full) {
        head = (head + 1) % SIZE; // Sovrascrive il dato più vecchio
    }
    buffer[tail] = value;
    tail = (tail + 1) % SIZE;
    is_full = (tail == head);
}

int arrayCircolare::dequeue() {
    if (head == tail && !is_full) {
        throw std::runtime_error("Buffer vuoto!");
    }
    int value = buffer[head];
    head = (head + 1) % SIZE;
    is_full = false;
    return value;
}

void arrayCircolare::print() const {
    int count = is_full ? SIZE : (tail + SIZE - head) % SIZE;
    for (int i = 0; i < count; ++i) {
        std::cout << buffer[(head + i) % SIZE] << " ";
    }
    std::cout << "\n";
}
*/