#include "../include/LidarDriver.h"

// Costruttore di default
LidarDriver::LidarDriver(int size) : array(size) {}

// Costruttore di copia
LidarDriver::LidarDriver(const LidarDriver& vect) : array(vect.array) {}

// Inserisce un nuovo vettore
void LidarDriver::new_scan(std::vector<double> vect) {
    array.enqueue(vect);
}

// Restituisce vettore più vecchio e lo rimuove dal buffer
std::vector<double> LidarDriver::get_scan() {
    return array.dequeue();
}

// Restituisce vettore più nuovo senza rimuoverlo dal buffer
std::vector<double> LidarDriver::latest_scan() const {
    return array.getLatestVector();
}

// Svuota il buffer
void LidarDriver::clear_buffer() {
    array.clear();
}

// Restituisce la distanza associata a un angolo
double LidarDriver::get_distance(double angle) const {
    if (angle < 0 || angle > 180) {
        throw std::out_of_range("L'angolo deve essere compreso tra 0 e 180 gradi.");
    }
    const std::vector<double>& lastScan = array.getLatestVector();
    int index = static_cast<int>(std::round(angle / array.getAngle()));
    return lastScan.at(index);
}

bool LidarDriver::is_buffer_empty() const { return array.isEmpty(); }

bool LidarDriver::is_buffer_full() const { return array.isFull(); }

void LidarDriver::print_all_scans() const {
    if (array.isEmpty()) {
        std::cout << "[ ]" << std::endl;
        return;
    }

    std::cout << "[ ";
    for (int i = 0; i < array.getSize(); ++i) {
        const std::vector<double>& scan = array[i];  // Accesso agli array memorizzati
        std::cout << "[ ";
        for (double val : scan) {
            std::cout << val << " ";
        }
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;
}


// Overloading dell'operatore di stampa <<
std::ostream& operator<<(std::ostream& os, const LidarDriver& driver) {
    if (driver.is_buffer_empty()) {
        os << "[ ]";
        return os;
    }

    std::vector<double> lastScan = driver.latest_scan();
    os << "[ ";
    for (double val : lastScan) {
        os << val << " ";
    }
    os << "]";
    return os;
}


