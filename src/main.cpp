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
        do {
            std::cout << "Inserisci la dimensione del buffer (numero positivo): ";
            std::cin >> buffer_size;

            if (std::cin.fail() || buffer_size <= 0) {
                std::cout << "Errore: devi inserire un numero intero positivo.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                buffer_size = -1;
            }
        } while (buffer_size <= 0);

        LidarDriver lidar(buffer_size);
        int scelta;

        do {
            print_menu();
            std::cin >> scelta;

            if (std::cin.fail()) {
                std::cout << "Errore: devi inserire un numero valido.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                scelta = -1;
                continue;
            }

            switch (scelta) {
                case 1: {
                    int num_elements;
                    do {
                        std::cout << "Inserisci il numero di elementi del vettore (numero positivo): ";
                        std::cin >> num_elements;

                        if (std::cin.fail() || num_elements <= 0) {
                            std::cout << "Errore: devi inserire un numero intero positivo.\n";
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            num_elements = -1;
                        }
                    } while (num_elements <= 0);

                    std::vector<double> v(num_elements);
                    std::cout << "Inserisci gli elementi del vettore (separati da spazio): ";
                    for (double& val : v) {
                        std::cin >> val;
                        if (std::cin.fail()) {
                            std::cout << "Errore: input non valido.\n";
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            val = 0; // Imposta un valore predefinito per proseguire
                        }
                    }
                    lidar.new_scan(v);
                    std::cout << "Vettore aggiunto con successo.\n";
                    break;
                }

                case 2:
                    if (!lidar.is_buffer_empty()) {
                        std::cout << "Ultima scansione: " << lidar << "\n";
                    } else {
                        std::cout << "Il buffer è vuoto.\n";
                    }
                    break;

                case 3:
                    std::cout << "Tutte le scansioni nel buffer:\n";
                    lidar.print_all_scans();
                    break;

                case 4: {
                    if (!lidar.is_buffer_empty()) {
                        double angle;
                        bool valid_input = false;
                
                        do {
                            std::cout << "Inserisci l'angolo (0-180 gradi): ";
                            std::cin >> angle;
                
                            if (std::cin.fail() || angle < 0 || angle > 180) {
                                std::cout << "Errore: devi inserire un numero compreso tra 0 e 180.\n";
                                std::cin.clear();                 // Resetta lo stato di errore dello stream
                                std::cin.ignore(10000, '\n');     // Svuota il buffer di input
                            } else {
                                valid_input = true;               // Input valido
                            }
                        } while (!valid_input);
                
                        std::cout << "Distanza per angolo " << angle << ": " 
                                  << lidar.get_distance(angle) << "\n";
                    } else {
                        std::cout << "Il buffer è vuoto.\n";
                    }
                    break;
                }


                case 5:
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

                case 6:
                    lidar.clear_buffer();
                    std::cout << "Buffer svuotato con successo.\n";
                    break;

                case 7: {
                    int num_elements;
                    do {
                        std::cout << "Inserisci il numero di elementi casuali (numero positivo): ";
                        std::cin >> num_elements;

                        if (std::cin.fail() || num_elements <= 0) {
                            std::cout << "Errore: devi inserire un numero intero positivo.\n";
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            num_elements = -1;
                        }
                    } while (num_elements <= 0);

                    std::vector<double> random_vector(num_elements);
                    std::srand(std::time(nullptr));
                    for (double& val : random_vector) {
                        val = std::rand() % 101;
                    }

                    lidar.new_scan(random_vector);
                    std::cout << "Vettore casuale aggiunto con successo: " << lidar << "\n";
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
