#ifndef ARRAYDATI_H
#define ARRAYDATI_H

#include <iostream>
#include <vector>
#include <stdexcept> // Per std::out_of_range

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

    //Operatore di assegnazione
    ArrayDati& operator=(const ArrayDati& other);

    //Operatore di confronto
    bool operator==(const ArrayDati& other);

    // Metodo per scrviere gli elementi (operatore [])
    double& operator[](int indice);

    // Metodo per leggere gli elementi (operatore [])
    double operator[](int index) const;

    // Metodo per stampare gli elementi utilizzati
    void print(std::ostream& os = std::cout) const;

    // Metodo per ottenere il numero di elementi utilizzati (size)
    int getSize() const;

    //Metodo per ottenere l'angolo tra le misurazioni
    double getAngle() const;

    // Overloading dell'operatore di stampa <<
    friend std::ostream& operator<<(std::ostream& os, const ArrayDati& array);
};

#endif // !ARRAYDATI_H