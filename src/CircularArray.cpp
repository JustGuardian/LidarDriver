#include "../include/CircularArray.h"
#include <stdexcept>
#include <algorithm>

// Metodo per svuotare completamente il buffer
void CircularArray::clear() {
    std::for_each(buffer.begin(), buffer.end(), [](auto& v) { v.clear(); });
    head = tail = dataSize = 0;
}

// Definizione costruttore di default
CircularArray::CircularArray(int size)
  : buffer(size), 
    BUFFER_DIM(size), 
    head(0), 
    tail(0), 
    dataSize(0) {}

// Definizione copy constructor
CircularArray::CircularArray(const CircularArray &vecchioArray) 
  : buffer(vecchioArray.buffer), 
    BUFFER_DIM(vecchioArray.BUFFER_DIM), 
    head(vecchioArray.head), 
    tail(vecchioArray.tail), 
    dataSize(vecchioArray.dataSize) {}

// Definizione move constructor
CircularArray::CircularArray(CircularArray &&vecchioArray) 
  : buffer(std::move(vecchioArray.buffer)), 
    BUFFER_DIM(vecchioArray.BUFFER_DIM), 
    head(vecchioArray.head), 
    tail(vecchioArray.tail), 
    dataSize(vecchioArray.dataSize) {
    vecchioArray.head = vecchioArray.tail = vecchioArray.dataSize = 0;
}

// Metodo incremento indice
int CircularArray::incrementIndex(int index) const {
    return (index + 1) % BUFFER_DIM;
}

// Metodo per inserire un vettore nel buffer
void CircularArray::enqueue(const std::vector<double>& elemento) {
    if (isFull()) {
        head = incrementIndex(head);
        --dataSize;
    }
    buffer[tail] = elemento;
    tail = incrementIndex(tail);
    ++dataSize;
}

// Metodo per inserire un vettore utilizzando move semantics
void CircularArray::enqueue(std::vector<double>&& elemento) {
    if (isFull()) {
        head = incrementIndex(head);
        --dataSize;
    }
    buffer[tail] = std::move(elemento);
    tail = incrementIndex(tail);
    ++dataSize;
}

// Metodo per rimuovere il vettore più vecchio (FIFO)
std::vector<double> CircularArray::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Buffer vuoto.");
    }
    std::vector<double> elemento = std::move(buffer[head]);
    head = incrementIndex(head); 
    --dataSize;
    return elemento;
}

// Metodo per visualizzare il primo elemento senza rimuoverlo
const std::vector<double>& CircularArray::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Buffer vuoto.");
    }
    return buffer[head];
}

// Metodo per ottenere il numero di elementi nel buffer
int CircularArray::getSize() const { return dataSize; }

// Metodo per controllare se il buffer è vuoto
bool CircularArray::isEmpty() const { return dataSize == 0; }

// Metodo per controllare se il buffer è pieno
bool CircularArray::isFull() const { return dataSize == BUFFER_DIM; }

// Metodo per ottenere la dimensione del buffer
int CircularArray::capacity() const { return BUFFER_DIM; }

// Operatore di confronto (uguaglianza)
bool CircularArray::operator==(const CircularArray& other) const {
    // Confronta dimensione del buffer e numero di elementi
    if (BUFFER_DIM != other.BUFFER_DIM || dataSize != other.dataSize) {
        return false;
    }
    // Confronta il contenuto del buffer in base alla posizione logica degli elementi
    for (int i = 0; i < dataSize; ++i) {
        if ((*this)[i] != other[i]) {
            return false;
        }
    }
    return true;
}

// Operatore di confronto (disuguaglianza)
bool CircularArray::operator!=(const CircularArray& other) const {
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
    os << "CircularArray (active elements): [ ";
    for (int i = 0; i < dataSize; ++i) {
        os << "[ ";
        for (double val : (*this)[i]) {
            os << val << " ";
        }
        os << "] ";
    }
    os << "]\n";
}

// Overloading dell'operatore di stampa <<
std::ostream& operator<<(std::ostream& os, const CircularArray& array) {
    array.print(os);
    return os;
}
