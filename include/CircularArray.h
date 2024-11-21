#ifndef CIRCULARARRAY_H
#define CIRCULARARRAY_H

#include <vector>
#include <iostream>
#include <stdexcept>

class CircularArray {
private:
    std::vector<std::vector<double>> buffer;  // Buffer contenente i vettori
    const int BUFFER_DIM;  // Capacità massima del buffer
    int head;  // Indice dell'elemento più vecchio
    int tail;  // Indice dell'elemento più recente
    int dataSize;  // Numero di elementi nel buffer

    int incrementIndex(int index) const;  // Metodo per incrementare l'indice (circular)

public:
    // Costruttori
    CircularArray(int size);  // Costruttore con dimensione
    CircularArray(const CircularArray &vecchioArray);  // Copy constructor
    CircularArray(CircularArray &&vecchioArray);  // Move constructor
    
    // Metodi
    void clear();  // Svuota il buffer
    void enqueue(const std::vector<double>& elemento);  // Aggiungi elemento al buffer
    void enqueue(std::vector<double>&& elemento);  // Aggiungi elemento al buffer (move)
    std::vector<double> dequeue();  // Rimuove e ritorna l'elemento più vecchio
    int getSize() const;  // Ottiene la dimensione del buffer
    bool isEmpty() const;  // Verifica se il buffer è vuoto
    bool isFull() const;  // Verifica se il buffer è pieno
    int capacity() const;  // Ritorna la capacità del buffer

    // Operatori
    bool operator==(const CircularArray& other) const;  // Confronta due CircularArray per uguaglianza
    bool operator!=(const CircularArray& other) const;  // Confronta due CircularArray per disuguaglianza
    std::vector<double>& operator[](int indice);  // Accesso con indice relativo
    const std::vector<double>& operator[](int indice) const;  // Accesso con indice relativo (const)

    // Stampa
    void print(std::ostream& os) const;  // Stampa lo stato del buffer
    friend std::ostream& operator<<(std::ostream& os, const CircularArray& array);  // Operatore di stampa
};

#endif // CIRCULARARRAY_H
