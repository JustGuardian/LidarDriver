#include "../include/LidarDriver.h"

// Costruttore di default
LidarDriver::LidarDriver(int size) : array(size) {}

// Costruttore di copia
LidarDriver::LidarDriver(const LidarDriver& vect) : array(vect.array) {}

//Formatta il vettore con le specifiche che sono richieste dall'esercizio
std::vector<double> LidarDriver::adjust_scan_size(std::vector<double> vect) const {
    const size_t minSize = 181;
    const size_t maxSize = 181;

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
    if (array.isEmpty()) {
        std::cout << "[ ]" << std::endl;
        return;
    }
    
    std::cout << "[\n";
    for (int i = 0; i < array.getSize(); ++i) {
        const std::vector<double>& scan = array[i];  // Accesso agli array memorizzati

        //std::cout << scan.size();
        std::cout << "[";
        for (double val : scan) {
            std::cout << val << " ";
        }
        if(i<array.getSize()-1){
            std::cout << "],\n\n";
        }else{
             std::cout << "]\n";
        }
        
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


