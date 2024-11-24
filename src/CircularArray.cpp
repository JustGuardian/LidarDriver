#include "../include/CircularArray.h"
#include <algorithm>

// Metodo incremento indice
int CircularArray::incrementIndex(int index) const {
    return (index + 1) % BUFFER_DIM;
}

// Costruttore di default
CircularArray::CircularArray(int size)
  : buffer(size), 
    BUFFER_DIM(size), 
    head(0), 
    tail(0), 
    dataSize(0) {}

// Costruttore di copia
CircularArray::CircularArray(const CircularArray &vecchioArray) 
  : buffer(vecchioArray.buffer), 
    BUFFER_DIM(vecchioArray.BUFFER_DIM), 
    head(vecchioArray.head), 
    tail(vecchioArray.tail), 
    dataSize(vecchioArray.dataSize) {}

// Costruttore di move
CircularArray::CircularArray(CircularArray &&vecchioArray) 
  : buffer(std::move(vecchioArray.buffer)), 
    BUFFER_DIM(vecchioArray.BUFFER_DIM), 
    head(vecchioArray.head), 
    tail(vecchioArray.tail), 
    dataSize(vecchioArray.dataSize) {
    vecchioArray.head = vecchioArray.tail = vecchioArray.dataSize = 0;
}

// Metodo per svuotare il buffer
void CircularArray::clear() {
    std::for_each(buffer.begin(), buffer.end(), [](auto& v) { v.clear(); });
    head = tail = dataSize = 0;
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

// Metodo per inserire un vettore con move semantics
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
    std::vector<double> elemento = std::move(buffer[head]);
    head = incrementIndex(head);
    --dataSize;
    return elemento;
}

// Restituisce il vettore più recente
std::vector<double> CircularArray::getLatestVector() const {
    if (isEmpty()) {
        return {}; // Restituisce un vettore vuoto
    }
    int lastIndex = (tail == 0) ? BUFFER_DIM - 1 : tail - 1;
    return buffer[lastIndex];
}

// Metodo per ottenere il numero di elementi nel buffer
int CircularArray::getSize() const { return dataSize; }

// Metodo per calcolare l'angolo
double CircularArray::getAngle() const {
    const std::vector<double>& lastVector = getLatestVector(); // Lancia eccezione se buffer vuoto
    return 181.0 / lastVector.size();
}

// Metodo per controllare se il buffer è vuoto
bool CircularArray::isEmpty() const { return dataSize == 0; }

// Metodo per controllare se il buffer è pieno
bool CircularArray::isFull() const { return dataSize == BUFFER_DIM; }

// Metodo per ottenere la capacità del buffer
int CircularArray::capacity() const { return BUFFER_DIM; }

// Operatore di confronto (uguaglianza)
bool CircularArray::operator==(const CircularArray& other) const {
    if (BUFFER_DIM != other.BUFFER_DIM || dataSize != other.dataSize) {
        return false;
    }
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
void CircularArray::print_all() const {
    if (isEmpty()) {
        std::cout << "{ }" << std::endl;
        return;
    }

    std::cout << "{\n";
    for (int i = 0; i < dataSize; ++i) {
        std::cout << "[ ";
        for (double val : (*this)[i]) {
            std::cout << val << " ";
        }
        if(i<array.getSize()-1){
            std::cout << "],\n\n";
        }else{
             std::cout << "]\n";
        }
    }
    std::cout << "}" << std::endl;
}



// Overloading dell'operatore di stampa <<
std::ostream& operator<<(std::ostream& os, const CircularArray& array) {
    if (array.isEmpty()) {
        os << "[ ]";
    } else {
        const std::vector<double>& lastVector = array.getLatestVector();
        os << "[ ";
        for (double val : lastVector) {
            os << val << " ";
        }
        os << "]";
    }
    return os;
}

