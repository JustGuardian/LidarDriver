#include <iostream>
#include <vector>
#include "../include/LidarDriver.h"

int main() {
    try {
        // Creazione di un LidarDriver con un buffer di dimensione 3
        LidarDriver lidar(3);

        // Inserimento di scansioni nel buffer
        std::cout << "Inserisco scansioni:\n";
        lidar.new_scan({ 1.0, 2.0, 3.0 });
        lidar.new_scan({ 4.0, 5.0 });
        lidar.new_scan({ 6.0, 7.0, 8.0, 9.0 });

        // Stampa dell'ultimo vettore inserito
        std::cout << "Ultima scansione: " << lidar << "\n";

        // Stampa di tutte le scansioni nel buffer
        std::cout << "Tutte le scansioni nel buffer:\n";
        lidar.print_all_scans();

        // Ottieni la distanza associata a un angolo
        double angle = 1.0;
        std::cout << "Distanza per angolo " << angle << ": "
            << lidar.get_distance(angle) << "\n";

        // Rimuovo il vettore più vecchio
        std::cout << "Rimuovo la scansione piu' vecchia:\n";
        std::vector<double> removedScan = lidar.get_scan();
        std::cout << "Scansione rimossa: [ ";
        for (double val : removedScan) {
            std::cout << val << " ";
        }
        std::cout << "]\n";

        // Stampa delle scansioni rimanenti nel buffer
        std::cout << "Stato attuale del buffer:\n";
        lidar.print_all_scans();

        // Pulizia del buffer
        std::cout << "Svuoto il buffer.\n";
        lidar.clear_buffer();

        // Controllo buffer vuoto
        std::cout << "Stato attuale del buffer:\n";
        lidar.print_all_scans();

        // Provo ad accedere alla distanza quando il buffer è vuoto
        std::cout << "Provo a calcolare la distanza con buffer vuoto:\n";
        std::cout << lidar.get_distance(angle) << "\n"; // Questo lancerà un'eccezione

    }
    catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << "\n";
    }

    return 0;

    int y;
    std::cin >> y;
}
