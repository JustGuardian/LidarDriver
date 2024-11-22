#include "../include/LidarDriver.h"
#include <iostream>
#include <vector>

int main() {
    // Creazione di un oggetto LidarDriver con buffer di dimensione 5
    LidarDriver lidar(5);

    // Inserimento di alcune scansioni
    lidar.new_scan({1.0, 2.0, 3.0});
    lidar.new_scan({4.0, 5.0, 6.0});
    lidar.new_scan({7.0, 8.0, 9.0});

    // Stampa dello stato corrente
    std::cout << "Stato corrente del LidarDriver:\n";
    lidar.print_all_scans();

    // Recupero dell'ultima scansione senza rimuoverla
    std::cout << "Ultima scansione salvata: ";
    for (double val : lidar.latest_scan()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Recupero di una scansione dal buffer
    std::vector<double> scan = lidar.get_scan();
    std::cout << "Scansione piu' vecchia rimossa dal buffer: ";
    for (double val : scan) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Stampa dello stato dopo la rimozione
    std::cout << "Stato del LidarDriver dopo una rimozione:\n";
    lidar.print_all_scans();

    // Calcolo della distanza per un angolo specifico
    try {
        double angle = 45.0;
        double distance = lidar.get_distance(angle);
        std::cout << "Distanza per l'angolo " << angle << " gradi: " << distance << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    // Svuotamento del buffer
    lidar.clear_buffer();
    std::cout << "Buffer svuotato. Stato attuale:\n";
    lidar.print_all_scans();

    int y;
    std::cin >> y;
    return 0;
}
