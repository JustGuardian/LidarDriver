#include <iostream>
#include <vector>
#include "../include/CircularArray.h"

int main() {
    // Creazione di un CircularArray con dimensione 3
    CircularArray buffer(3);

    // Creazione di alcuni vettori di test
    std::vector<double> vec1 = {1.1, 2.2, 3.3};
    std::vector<double> vec2 = {4.4, 5.5, 6.6};
    std::vector<double> vec3 = {7.7, 8.8, 9.9};
    std::vector<double> vec4 = {10.10, 11.11, 12.12};

    // Inserimento di vettori nel buffer
    std::cout << "Enqueuing vec1:" << std::endl;
    buffer.enque(vec1);
    std::cout << buffer << std::endl;

    std::cout << "Enqueuing vec2:" << std::endl;
    buffer.enque(vec2);
    std::cout << buffer << std::endl;

    std::cout << "Enqueuing vec3:" << std::endl;
    buffer.enque(vec3);
    std::cout << buffer << std::endl;

    // Prova di sovrascrivere un elemento (perché il buffer è pieno)
    std::cout << "Enqueuing vec4 (overflow, dovrebbe rimuovere vec1):" << std::endl;
    buffer.enque(vec4);
    std::cout << buffer << std::endl;

    // Rimozione di un elemento (FIFO)
    std::cout << "Dequeuing an element:" << std::endl;
    std::vector<double> dequeued = buffer.deque();
    std::cout << "Dequeued vector: ";
    for (double val : dequeued) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << buffer << std::endl;

    // Accedere a un elemento tramite l'operatore []
    std::cout << "Accessing an element by index (index 0):" << std::endl;
    std::vector<double>& accessedVec = buffer[0];
    std::cout << "Accessed vector: ";
    for (double val : accessedVec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Confronto tra due CircularArray
    CircularArray anotherBuffer(3);
    anotherBuffer.enque(vec2);
    anotherBuffer.enque(vec3);
    anotherBuffer.enque(vec4);

    if (buffer == anotherBuffer) {
        std::cout << "The buffers are equal." << std::endl;
    } else {
        std::cout << "The buffers are not equal." << std::endl;
    }


    int y;
    std::cin >> y;
    return 0;
}
