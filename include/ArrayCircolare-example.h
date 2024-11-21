#ifndef ARRAYCIRCOLARE_H
#define ARRAYCIRCOLARE_H

#include <iostream>
#include <stdexcept>

class arrayCircolare {
private:
    int* buffer;       // Puntatore per array dinamico
    int size;          // Dimensione dell'array
    int head = 0;
    int tail = 0;
    bool is_full = false;

public:
    explicit arrayCircolare(int dimensione); // Costruttore con dimensione
    ~arrayCircolare();                       // Distruttore per liberare memoria

    void enqueue(int value);  // Aggiungi un elemento
    int dequeue();            // Rimuovi un elemento
    void print() const;       // Stampa i dati
};

#endif // ARRAYCIRCOLARE_H


#include "arrayCircolare.h"

arrayCircolare::arrayCircolare(int dimensione)
    : size(dimensione), buffer(new int[dimensione]) {}

arrayCircolare::~arrayCircolare() {
    delete[] buffer; // Libera la memoria allocata dinamicamente
}

void arrayCircolare::enqueue(int value) {
    if (is_full) {
        head = (head + 1) % size; // Sovrascrive il dato più vecchio
    }
    buffer[tail] = value;
    tail = (tail + 1) % size;
    is_full = (tail == head);
}

int arrayCircolare::dequeue() {
    if (head == tail && !is_full) {
        throw std::runtime_error("Buffer vuoto!");
    }
    int value = buffer[head];
    head = (head + 1) % size;
    is_full = false;
    return value;
}

void arrayCircolare::print() const {
    int count = is_full ? size : (tail + size - head) % size;
    for (int i = 0; i < count; ++i) {
        std::cout << buffer[(head + i) % size] << " ";
    }
    std::cout << "\n";
}
