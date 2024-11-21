#ifndef ARRAYDATI_H
#define ARRAYDATI_H

#include <iostream>
#include <vector>

class ArrayDati {
private:
    std::vector<double> dati; // Contenitore per i dati
    int size;                 // Numero di elementi attualmente utilizzati

public:
    // Costruttore: inizializza il vettore con 181 elementi
    ArrayDati(int x = 181) : dati(x < 181 ? 181 : x), size(0) {}

    // Metodo per aggiungere un elemento (push)
    void push(double valore);

    // Metodo per rimuovere l'ultimo elemento (pop)
    void pop();

    // Metodo per ottenere il numero di elementi utilizzati (size)
    int getSize() const;

    // Metodo per accedere agli elementi (operatore [])
    double& operator[](int indice);

    // Metodo per stampare gli elementi utilizzati
    void print() const;

    // Metodo per ottenere la capacità del vettore (dimensione totale allocata)
    int getSize() const;

    double getAngle() const;
};

#endif ARRAYDATI_H