#include <iostream>
#include <vector>
#include "../include/LidarDriver.h"

int main() {
    try {
        // Creazione di un LidarDriver con capacità elevata
        const int bufferSize = 1000;
        LidarDriver lidar(bufferSize);

        // Test 1: Inserire array lunghissimi
        std::vector<double> largeScan(10000, 1.0);  // Vettore lungo 10.000 con tutti valori 1.0
        lidar.new_scan(largeScan);
        std::cout << "Test 1: Inserito un array molto lungo.\n";
        lidar.print_all_scans();

        // Test 2: Riempire il buffer al massimo e oltre
        for (int i = 0; i < bufferSize + 10; ++i) {
            std::vector<double> scan = {static_cast<double>(i), static_cast<double>(i + 1), static_cast<double>(i + 2)};
            lidar.new_scan(scan);
        }
        std::cout << "Test 2: Riempito il buffer oltre la capacità.\n";
        lidar.print_all_scans();

        // Test 3: Svuotare il buffer completamente
        std::cout << "Test 3: Svuoto il buffer...\n";
        lidar.clear_buffer();
        lidar.print_all_scans();

        // Test 4: Inserire e recuperare array ripetutamente
        for (int i = 0; i < 10000; ++i) {
            std::vector<double> scan = {static_cast<double>(i), static_cast<double>(i * 2), static_cast<double>(i * 3)};
            lidar.new_scan(scan);

            if (i % 50 == 0) {  // Ogni 50 iterazioni, recupera un array dal buffer
                std::vector<double> retrievedScan = lidar.get_scan();
                std::cout << "Iterazione " << i << ": Recuperato il vettore con primo valore " << retrievedScan[0] << ".\n";
            }
        }

        // Test 5: Calcolo della distanza con angoli limite
        lidar.new_scan({0.0, 10.0, 20.0, 30.0, 40.0, 50.0});  // Aggiunta di un nuovo scan noto
        std::cout << "Test 5: Calcolo distanza...\n";
        try {
            std::cout << "Distanza all'angolo 0: " << lidar.get_distance(0) << "\n";
            std::cout << "Distanza all'angolo 180: " << lidar.get_distance(180) << "\n";
            std::cout << "Distanza all'angolo 90: " << lidar.get_distance(90) << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Errore calcolando la distanza: " << e.what() << "\n";
        }

        // Test 6: Casi limite con buffer vuoto
        lidar.clear_buffer();
        std::cout << "Test 6: Recupero da buffer vuoto...\n";
        try {
            std::vector<double> emptyScan = lidar.get_scan();
            std::cout << "Recuperato da buffer vuoto: " << emptyScan.size() << " elementi.\n";
        } catch (const std::exception& e) {
            std::cerr << "Errore: " << e.what() << "\n";
        }

        // Test 7: Stress test con ripetizioni massive
        std::cout << "Test 7: Stress test con 100.000 operazioni...\n";
        for (int i = 0; i < 100000; ++i) {
            lidar.new_scan({static_cast<double>(i)});
            lidar.latest_scan();
            if (i % 10000 == 0) {
                std::cout << "Iterazione: " << i << "\n";
            }
        }

        std::cout << "Test completati senza errori critici.\n";
    } catch (const std::exception& e) {
        std::cerr << "Errore critico durante il test: " << e.what() << "\n";
    }

    return 0;
}
