#include <array>
#include <iostream>

template <typename T, size_t SIZE>
class CircularQueue {
private:
    std::array<T, SIZE> buffer = {};
    size_t head = 0;
    size_t tail = 0;
    bool is_full = false;

public:
    void enqueue(T value) {
        if (is_full) {
            std::cout << "Buffer pieno. Sovrascrivo l'elemento più vecchio.\n";
            head = (head + 1) % SIZE;  // Sovrascrivi il più vecchio
        }
        buffer[tail] = value;
        tail = (tail + 1) % SIZE;
        is_full = (tail == head);
    }

    T dequeue() {
        if (head == tail && !is_full) {
            throw std::runtime_error("Buffer vuoto!");  // Niente da rimuovere
        }
        T value = buffer[head];
        head = (head + 1) % SIZE;
        is_full = false;
        return value;
    }

    void print() const {
        size_t idx = head;
        size_t count = (tail + SIZE - head) % SIZE;
        for (size_t i = 0; i < count; ++i) {
            std::cout << buffer[(idx + i) % SIZE] << " ";
        }
        std::cout << "\n";
    }
};

