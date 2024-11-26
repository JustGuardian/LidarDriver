#include "../include/LidarDriver.h"

// Costruttore di default
LidarDriver::LidarDriver(int x) 
  : array(DIM_BUFFER),
    angle(x >= 0.1 && x <= 1 ? x : (x < 0.1 ? 0.1 : 1)) {}

// Costruttore di copia
LidarDriver::LidarDriver(const LidarDriver& vect) 
  : array(vect.array),
    DIM_BUFFER(vect.DIM_BUFFER),
    angle(vect.angle) {}

//Formatta il vettore con le specifiche che sono richieste dall'esercizio
std::vector<double> LidarDriver::adjust_scan_size(std::vector<double> vect) const {
    const size_t size = 180/angle + 1;

    if (vect.size() < size){
        vect.resize(size, 0.0);
    }

    if (vect.size() > size){
        vect.resize(size);
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

    return array.getLatestVector()[static_cast<int>(std::round(angle / get_angle()))];
}

//capacità buffer
int LidarDriver::get_capacity() const{ return DIM_BUFFER; }

//numero elementi nel buffer
int LidarDriver::get_size() const{ return array.getSize(); }

//numero di elementi in ogni singolo vettore
int LidarDriver::get_num_elementi() const{
    return static_cast<int>(std::round(angle / get_angle()));
}

//risoluzione angolare
double LidarDriver::get_angle() const{ return angle; }

//1 se vettore è vuoto
bool LidarDriver::is_buffer_empty() const { return array.isEmpty(); }

//1 se vettore è pieno
bool LidarDriver::is_buffer_full() const { return array.isFull(); }

//stampa l'intero buffer
void LidarDriver::print_all_scans() const { array.print_all();}

// Overloading dell'operatore di stampa <<
std::ostream& operator<<(std::ostream& os, const LidarDriver& driver) {
    os << driver.array;
    return os;
}


