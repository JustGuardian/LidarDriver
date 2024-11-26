#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H

#include "CircularArray.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>

const int DIM_BUFFER = 10; // Dimensione fissa del buffer
class LidarDriver{
private:
    CircularArray array;    
    const double angle_resolution;     //risoluzione angolare
    std::vector<double> adjust_scan_size(std::vector<double>) const;    //controlla il numero di elementi della lista da inserire (se size<181 riempie con 0 fino a 181, se size > 1810 taglia gli elementi dopo)
    size_t calculate_scan_size() const;    //calcola il numero di elementi in ogni vettore
public:
    //costruttori
    LidarDriver(double x = 0.5);       //costruttore di default
    LidarDriver(const LidarDriver&); //costruttore di copia

    //metodi
    void new_scan(const std::vector<double>&); //inserisce un nuovo vettore
    std::vector<double> get_scan();     //restituisce vettore più vecchio e lo rimuove dal buffer
    std::vector<double> latest_scan() const;    //restituisce vettore più nuovo senza rimuoverlo dal buffer
    void clear_buffer();        //svuota il buffer
    double get_distance(double) const;    //resituisce la distanza del vettore più recente di quel relativo angolo
    int get_capacity() const;   //resituisce valore di DIM_BUFFER
    int get_size() const; //restituisce il numero di elementi nel buffer
    int get_num_elementi() const; //restituisce il numero di elementi contenuti in ogni vettore
    double get_angle() const;   //restituisce valore di angle
    bool is_buffer_empty() const;    //restituisce 1 se è vuoto
    bool is_buffer_full() const;    //restituisce 1 se è pieno

    // Dichiarazione dell'operatore di stampa come friend
    void print_all_scans() const;    //metodo per stampare tutto il buffer
    friend std::ostream& operator<<(std::ostream& os, const LidarDriver& driver);     //overloading dell'operatore di stampa (stampa l'ultima lista dati inserita)
};

#endif //!LIDARDRIVER_H
