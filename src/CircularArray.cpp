#include "../include/CircularArray.h"

// Metodo per svuotare completamente il buffer
void CircularArray::clear() {
    buffer.clear();  // Rimuove tutti gli elementi dal buffer
    head = 0;
    tail = 0;
    dataSize = 0;
}

// Metodo per inserire un vettore nel buffer
void CircularArray::enqueue(const std::vector<double>& elemento) {
    if (isFull()) {
        // Dealloca il più vecchio elemento
        buffer[head].clear();  // Svuota il vettore
        head = (head + 1) % BUFFER_DIM; // Sposta la testa avanti
        --dataSize;
    }

    // Inserisce il nuovo elemento nella posizione di coda
    buffer[tail] = elemento;
    tail = (tail + 1) % BUFFER_DIM;
    ++dataSize;
}

// Metodo per rimuovere il vettore più vecchio (FIFO)
std::vector<double> CircularArray::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Buffer vuoto.");
    }

    // Rimuove il vettore più vecchio
    std::vector<double> elemento = buffer[head];
    buffer[head].clear();  // Svuota il vettore
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

// Operatore di confronto (uguaglianza)
bool CircularArray::operator==(const CircularArray& other) {
    if (BUFFER_DIM != other.BUFFER_DIM || head != other.head || tail != other.tail || dataSize != other.dataSize) {
        return false;
    }

    // Confronta il contenuto del buffer
    for (int i = 0; i < BUFFER_DIM; ++i) {
        if (buffer[i] != other.buffer[i]) {
            return false;
        }
    }
    return true;
}

// Operatore di confronto (disuguaglianza)
bool CircularArray::operator!=(const CircularArray& other) {
    return !(*this == other);
}

// Metodo per accedere agli elementi tramite indice relativo
std::vector<double>& CircularArray::operator[](int indice) {
    if (indice < 0 || indice >= dataSize) {
        throw std::out_of_range("Indice fuori dai limiti.");
    }
    return buffer[(head + indice) % BUFFER_DIM];
}

const std::vector<double>& CircularArray::operator[](int indice) const {
    if (indice < 0 || indice >= dataSize) {
        throw std::out_of_range("Indice fuori dai limiti.");
    }
    return buffer[(head + indice) % BUFFER_DIM];
}

// Metodo per stampare lo stato del buffer
void CircularArray::print(std::ostream& os) const {
    os << "CircularArray: [ ";
    for (int i = 0; i < BUFFER_DIM; ++i) {
        if (!buffer[i].empty()) {
            os << "[ ";
            for (double val : buffer[i]) {
                os << val << " ";
            }
            os << "] ";
        } else {
            os << "nullptr ";
        }
    }
    os << "]" << std::endl;
}

// Overloading dell'operatore di stampa <<
std::ostream& operator<<(std::ostream& os, const CircularArray& array) {
    array.print(os);
    return os;
}
