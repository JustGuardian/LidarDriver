#include "../include/LidarDriver.h"

// Costruttore di default
LidarDriver::LidarDriver() : array(DIM_BUFFER) {}

// Costruttore di copia
LidarDriver::LidarDriver(const LidarDriver& vect) : array(vect.array) {}

//Formatta il vettore con le specifiche che sono richieste dall'esercizio
std::vector<double> LidarDriver::adjust_scan_size(std::vector<double> vect) const {
    const size_t minSize = 181;
    const size_t maxSize = 1810;

    if (vect.size() < minSize){
        vect.resize(minSize, 0.0);
    }

    if (vect.size() > maxSize){
        vect.resize(maxSize);
    }
    return vect;
}

// Inserisce un nuovo vettore
void LidarDriver::new_scan(const std::vector<double>& vect) {
    array.enqueue(adjust_scan_size(vect));
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
    if (array.isEmpty()) {
        throw std::runtime_error("Il buffer e' vuoto. Nessuna scansione disponibile per calcolare la distanza.");
    }

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
    array.print_all();
}


// Overloading dell'operatore di stampa <<
std::ostream& operator<<(std::ostream& os, const LidarDriver& driver) {
    os << driver.array;
    return os;
}


