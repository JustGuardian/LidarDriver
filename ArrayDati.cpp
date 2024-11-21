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

//Operatore di assegnazione
ArrayDati& ArrayDati::operator=(const ArrayDati& other) {
    if (this != &other) { // Evita auto-assegnazione
        dati = other.dati; 
        size = other.size; 
    }
    return *this; 
}

//Operatore di confronto
bool ArrayDati::operator==(const ArrayDati& other){
    if (this == &other)
        return true;
    if (this->getSize() != other.getSize())
        return false;
    for (int i = 0; i<this->getSize(); i++) {
        if ((*this)[i] != other[i])
            return false;
    } 
    return true;
}

//Operatore di confronto
bool ArrayDati::operator!=(const ArrayDati& other){
    if (this == &other)
        return false;
    if (this->getSize() != other.getSize())
        return true;
    for (int i = 0; i<this->getSize(); i++) {
        if ((*this)[i] != other[i])
            return true;
    } 
    return false;
}


// Metodo per accedere agli elementi (operatore [])
double& ArrayDati::operator[](int index) {
    if (index >= 0 && index < size) {
        return dati[index];
    } else {
        throw std::out_of_range("Indice fuori dai limiti!");
    }
}

double ArrayDati::operator[](int index) const {
    if (index >= 0 && index < size) {
        return dati[index];
    } else {
        throw std::out_of_range("Indice fuori dai limiti!");
    }
}

// Metodo per stampare gli elementi utilizzati
void ArrayDati::print(std::ostream& os) const {
    os << "[";
    for (int i = 0; i < size; ++i) {
        os << dati[i];
        if (i < size - 1) {
            os << ", ";
        }
    }
    os << "]";
}

// Metodo per ottenere la capacità del vettore (dimensione totale allocata)
int ArrayDati::getSize() const {
    return size;
}

double ArrayDati::getAngle() const{
    return 181.0/size;
}

std::ostream& operator<<(std::ostream& os, const ArrayDati& array) {
    array.print(os);
    return os;
}
