#include "include/CircularArray.h"

// Metodo per inserire un oggetto nel buffer
void CircularArray::enque(ArrayDati* elemento) {
    if (isFull()) {
        // Dealloca il più vecchio elemento
        delete buffer[head];
        buffer[head] = nullptr;
        head = (head + 1) % BUFFER_DIM; // Sposta la testa avanti
        --dataSize;
    }

    // Inserisce il nuovo elemento nella posizione di coda
    buffer[tail] = elemento;
    tail = (tail + 1) % BUFFER_DIM;
    ++dataSize;
}

// Metodo per rimuovere l'oggetto più vecchio (FIFO)
ArrayDati* CircularArray::deque() {
    if (isEmpty()) {
        throw std::underflow_error("Buffer vuoto.");
    }

    // Rimuove l'oggetto più vecchio
    ArrayDati* elemento = buffer[head];
    buffer[head] = nullptr;
    head = (head + 1) % BUFFER_DIM;
    --dataSize;
    return elemento;
}

// Metodo per ottenere il numero di elementi nel buffer
int CircularArray::getSize() const { return dataSize; }

// Metodo per controllare se il buffer è vuoto
bool CircularArray::isEmpty() const { return dataSize == 0; }

// Metodo per controllare se il buffer è pieno
bool CircularArray::isFull() const { return dataSize == BUFFER_DIM; }

// Metodo per accedere agli elementi tramite indice relativo
ArrayDati* CircularArray::operator[](int indice) const {
    if (indice < 0 || indice >= dataSize) {
        throw std::out_of_range("Indice fuori dai limiti.");
    }
    return buffer[(head + indice) % BUFFER_DIM];
}

// Metodo per stampare lo stato del buffer
void CircularArray::print(std::ostream& os) const {
    os << "CircularArray: [ ";
    for (int i = 0; i < BUFFER_DIM; ++i) {
        if (buffer[i]) {
            os << *buffer[i] << " ";
        } else {
            os << "nullptr ";
        }
    }
    os << "]" << std::endl;
}

// Overloading dell'operatore di stampa <<
std::ostream& operator<<(std::ostream& os, const CircularArray& array){
    array.print(os);
    return os;
}

