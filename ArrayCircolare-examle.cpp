#include "include/ArrayCircolare-example.h"

arrayCircolare::~arrayCircolare() {
    delete[] buffer; // Libera la memoria allocata dinamicamente
}

void arrayCircolare::enqueue(double value) {
    if (is_full) {
        head = (head + 1) % size; // Sovrascrive il dato più vecchio
    }
    buffer[tail] = value;
    tail = (tail + 1) % size;
    is_full = (tail == head);
}

double arrayCircolare::dequeue() {
    if (head == tail && !is_full) {
        throw std::runtime_error("Buffer vuoto!");
    }
    double value = buffer[head];
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
