#include <iostream>
#include <vector>
#include <ctime>
#include "../include/LidarDriver.h"

int main() {
    try {
        // Creazione di un LidarDriver con un buffer di dimensione 3
        LidarDriver lidar(3);

        // Inserimento di scansioni nel buffer
        std::cout << "Inserisco scansioni...\n";

        // Test per vedere se il vettore viene troncato correttamente al numero di misure richiesto
        std::vector<double> v;
        for(int i=1; i<400; i++){
            v.push_back(i);
        }
        lidar.new_scan(v);

        lidar.new_scan({ 4.0, 5.0 });
        lidar.new_scan({ 6.0, 7.0, 8.0, 9.0 });

        // Inserimento di un vettore con numeri casuali
        v.clear();
        std::srand(std::time(nullptr));
        for(int i=1; i<600; i++){
            v.push_back(std::rand() % 101); //  Numero a caso tra 0 e 100
        }
        lidar.new_scan(v);

        // Stampa dell'ultimo vettore inserito
        std::cout << "\nUltima scansione: " << lidar << "\n";

        // Stampa di tutte le scansioni nel buffer
        std::cout << "\nTutte le scansioni nel buffer:\n";
        lidar.print_all_scans();

        // Ottieni la distanza associata a un angolo
        double angle = 0.5;
        std::cout << "\nDistanza per angolo " << angle << ": "
            << lidar.get_distance(angle) << "\n";

        // Rimuovo il vettore più vecchio
        std::cout << "\nRimuovo la scansione piu' vecchia...\n";
        std::vector<double> removedScan = lidar.get_scan();
        std::cout << "\nScansione rimossa: [ ";
        for (double val : removedScan) {
            std::cout << val << " ";
        }
        std::cout << "]\n\n";

        // Stampa delle scansioni rimanenti nel buffer
        std::cout << "Stato attuale del buffer:\n";
        lidar.print_all_scans();

        // Pulizia del buffer
        std::cout << "\nSvuoto il buffer...\n";
        lidar.clear_buffer();

        // Controllo buffer vuoto
        std::cout << "\nStato attuale del buffer:\n";
        lidar.print_all_scans();

        // Provo ad accedere alla distanza quando il buffer è vuoto
        std::cout << "\nProvo a calcolare la distanza con buffer vuoto:\n";
        std::cout << lidar.get_distance(angle) << "\n"; // Questo lancerà un'eccezione

    }
    catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << "\n";
    }
    
    int y;
    std::cout << "Premi un pulsante per terminare l'esecuzione" << std::endl;
    std::cin >> y;

    return 0;
}
