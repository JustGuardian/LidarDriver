#include <iostream>
#include <vector>
#include <ctime>
#include "../include/LidarDriver.h"

void print_menu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Aggiungi un nuovo vettore\n";
    std::cout << "2. Visualizza l'ultimo vettore\n";
    std::cout << "3. Visualizza tutte le scansioni nel buffer\n";
    std::cout << "4. Ottieni la distanza per un angolo\n";
    std::cout << "5. Rimuovi il vettore più vecchio\n";
    std::cout << "6. Svuota il buffer\n";
    std::cout << "7. Aggiungi un vettore di elementi casuali\n";
    std::cout << "0. Esci\n";
    std::cout << "Scelta: ";
}

int main() {
    try {
        // Chiedi all'utente la dimensione del buffer
        int buffer_size;
        std::cout << "Inserisci la dimensione del buffer: ";
        std::cin >> buffer_size;

        LidarDriver lidar(buffer_size);
        int scelta;

        do {
            print_menu();
            std::cin >> scelta;

            switch (scelta) {
            case 1: {
                // Aggiungi un nuovo vettore
                std::cout << "Inserisci il numero di elementi del vettore: ";
                int num_elements;
                std::cin >> num_elements;

                std::vector<double> v(num_elements);
                std::cout << "Inserisci gli elementi del vettore (separati da spazio): ";
                for (double& val : v) {
                    std::cin >> val;
                }
                lidar.new_scan(v);
                std::cout << "Vettore aggiunto con successo.\n";
                break;
            }

            case 2: {
                // Visualizza l'ultimo vettore
                if (!lidar.is_buffer_empty()) {
                    std::cout << "Ultima scansione: " << lidar << "\n";
                } else {
                    std::cout << "Il buffer è vuoto.\n";
                }
                break;
            }

            case 3: {
                // Visualizza tutte le scansioni
                std::cout << "Tutte le scansioni nel buffer:\n";
                lidar.print_all_scans();
                break;
            }

            case 4: {
                // Ottieni la distanza per un angolo
                if (!lidar.is_buffer_empty()) {
                    double angle;
                    std::cout << "Inserisci l'angolo (in radianti): ";
                    std::cin >> angle;
                    std::cout << "Distanza per angolo " << angle << ": "
                              << lidar.get_distance(angle) << "\n";
                } else {
                    std::cout << "Il buffer è vuoto.\n";
                }
                break;
            }

            case 5: {
                // Rimuovi il vettore più vecchio
                if (!lidar.is_buffer_empty()) {
                    std::vector<double> removed_scan = lidar.get_scan();
                    std::cout << "Scansione rimossa: [ ";
                    for (double val : removed_scan) {
                        std::cout << val << " ";
                    }
                    std::cout << "]\n";
                } else {
                    std::cout << "Il buffer è già vuoto.\n";
                }
                break;
            }

            case 6: {
                // Svuota il buffer
                lidar.clear_buffer();
                std::cout << "Buffer svuotato con successo.\n";
                break;
            }

            case 7: {
                // Aggiungi un vettore di elementi casuali
                std::cout << "Inserisci il numero di elementi casuali: ";
                int num_elements;
                std::cin >> num_elements;

                std::vector<double> random_vector(num_elements);
                std::srand(std::time(nullptr));
                for (double& val : random_vector) {
                    val = std::rand() % 101; // Numero casuale tra 0 e 100
                }

                lidar.new_scan(random_vector);
                std::cout << "Vettore casuale aggiunto con successo: "<< lidar << "\n";
                break;
            }

            case 0:
                std::cout << "Uscita dal programma.\n";
                break;

            default:
                std::cout << "Scelta non valida. Riprova.\n";
            }
        } while (scelta != 0);
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << "\n";
    }

    return 0;
}

