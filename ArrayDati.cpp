#include "include/ArrayDati.h"

void ArrayDati::push(double valore) {
    if (size < dati.size()) {
        dati[size] = valore;
    } else {
        dati.push_back(valore); // Aggiunge un nuovo elemento ridimensionando il vettore
    }
    size++; 
}

// Metodo per rimuovere l'ultimo elemento (pop)
void ArrayDati::pop() {
    if (size > 0) {
        size--; 
    } else {
        throw std::out_of_range("Vettore vuoto");
    }
}

// Metodo per accedere agli elementi (operatore [])
double& ArrayDati::operator[](int index) {
    if (index >= 0 && index < size) {
        return dati[index];
    } else {
        throw std::out_of_range("Indice fuori dai limiti!");
    }
}

// Metodo per stampare gli elementi utilizzati
void ArrayDati::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << dati[i] << " ";
    }
    std::cout << std::endl;
}

// Metodo per ottenere la capacità del vettore (dimensione totale allocata)
int ArrayDati::getSize() const {
    return dati.size();
}

double ArrayDati::getAngle() const{
    return 181/size;
}
