#include "../include/CircularArray.h"
#include <iostream>

int main() {
    try {
        int y;
        std::cout << "Premi un tasto per iniziare: ";
        std::cin >> y;

        std::cout << "Inizio controllo" << std::endl;

        // Crea un oggetto ArrayDati con 182 elementi
        ArrayDati array1(182);
        for (int i = 0; i < 181; i++) {
            array1.push(i);
        }

        std::cout << "Meta' controllo" << std::endl;

        // Crea un buffer circolare di dimensione 3
        CircularArray array4(3);

        // Inserisci nuovi oggetti dinamici nel buffer circolare
        for (long long i = 0; i < 1000000000; i++) {
            array4.enque(new ArrayDati(array1));
        }

        std::cout << "Fine controllo" << std::endl;

        int x;
        std::cout << "Premi un tasto per terminare: ";
        std::cin >> x;
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    return 0;
}
