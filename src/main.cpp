#include <iostream>
#include <vector>
#include <ctime>
#include <climits> // INT_MAX
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

void clearInputStream(){
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

void add_new_scan(LidarDriver& lidar) {
    std::vector<double> v(lidar.get_num_elementi());
    std::cout << "Inserisci gli elementi del vettore (separati da spazio): ";
    for (double& val : v) {
        std::cin >> val;
        if (std::cin.fail()) {
            std::cout << "Errore: input non valido.\n";
            clearInputStream();
            val = 0; // Imposta un valore predefinito per proseguire
        }
    }

    clearInputStream();
    lidar.new_scan(v);
    std::cout << "Vettore aggiunto con successo.\n";
}

void display_last_scan(LidarDriver& lidar) {
    if (!lidar.is_buffer_empty()) {
        std::cout << "Ultima scansione: " << lidar << "\n";
    } else {
        std::cout << "Il buffer e' vuoto.\n";
    }
}

void display_all_scans(LidarDriver& lidar) {
    std::cout << "Tutte le scansioni nel buffer:\n";
    lidar.print_all_scans();
}

void get_distance_for_angle(LidarDriver& lidar) {
    if (!lidar.is_buffer_empty()) {
        double angle;
        bool valid_input = false;

        do {
            std::cout << "Inserisci l'angolo (0-180 gradi): ";
            std::cin >> angle;

            if (std::cin.fail() || angle < 0 || angle > 180) {
                std::cout << "Errore: devi inserire un numero compreso tra 0 e 180.\n";
                clearInputStream();
            } else {
                valid_input = true;
            }
        } while (!valid_input);

        std::cout << "\nDistanza per angolo " << angle << ": " 
                  << lidar.get_distance(angle) << "\n";
    } else {
        std::cout << "Il buffer e' vuoto.\n";
    }
}

void remove_oldest_scan(LidarDriver& lidar) {
    if (!lidar.is_buffer_empty()) {
        std::vector<double> removed_scan = lidar.get_scan();
        std::cout << "Scansione rimossa: [ ";
        for (double val : removed_scan) {
            std::cout << val << " ";
        }
        std::cout << "]\n";
    } else {
        std::cout << "Il buffer e' gia' vuoto.\n";
    }
}

void clear_buffer(LidarDriver& lidar) {
    lidar.clear_buffer();
    std::cout << "Buffer svuotato con successo.\n";
}

void add_random_scan(LidarDriver& lidar) {
    int num_elements;
    do {
        std::cout << "Inserisci il numero di elementi casuali (numero positivo): ";
        std::cin >> num_elements;

        if (std::cin.fail() || num_elements <= 0) {
            std::cout << "Errore: devi inserire un numero intero positivo.\n";
            clearInputStream();
            num_elements = -1;
        }
    } while (num_elements <= 0);

    std::vector<double> random_vector(num_elements);
    std::srand(std::time(nullptr));
    for (double& val : random_vector) {
        val = std::rand() % 101;
    }

    lidar.new_scan(random_vector);
    std::cout << "Vettore casuale aggiunto con successo.\n";
}

int main() {
    try {
        int angle_size;
        do {
            std::cout << "Inserisci la risoluzione angolare (0.1 - 1): ";
            std::cin >> angle_size;

            if (std::cin.fail() || angle_size < 0.1 || angle_size > 1) {
                std::cout << "Errore: devi inserire un numero intero positivo tra 0.1 e 1.\n";
                clearInputStream();
                angle_size = -1;
            }
        } while (angle_size <= 0);
        clearInputStream();

        LidarDriver lidar(angle_size);
        int scelta;

        do {
            print_menu();
            std::cin >> scelta;

            if (std::cin.fail()) {
                std::cout << "Errore: devi inserire un numero valido.\n";
                clearInputStream();
                scelta = -1;
                continue;
            }


            switch (scelta) {
                case 1: add_new_scan(lidar); break;
                case 2: display_last_scan(lidar); break;
                case 3: display_all_scans(lidar); break;
                case 4: get_distance_for_angle(lidar); break;
                case 5: remove_oldest_scan(lidar); break;
                case 6: clear_buffer(lidar); break;
                case 7: add_random_scan(lidar); break;
                case 0: std::cout << "Uscita dal programma.\n"; break;
                default: std::cout << "Scelta non valida. Riprova.\n";
            }
        } while (scelta != 0);
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << "\n";
    }

    std::cout << "Premi Invio per continuare...\n";
    std::cin.get(); // Attende fino a quando l'utente preme Invio
    return 0;
}
