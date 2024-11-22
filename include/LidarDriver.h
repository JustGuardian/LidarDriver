#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H

#include "CircularArray.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>

class LidarDriver{
private:
    CircularArray array;
public:
    //costruttori
    LidarDriver(int x = 10);       //costruttore di default
    LidarDriver(const LidarDriver&); //costruttore di copia

    //metodi
    void new_scan(std::vector<double>); //inserisce un nuovo vettore
    std::vector<double> get_scan();     //restituisce vettore più vecchio e lo rimuove dal buffer
    std::vector<double> latest_scan() const;    //restituisce vettore più nuovo senza rimuoverlo dal buffer
    void clear_buffer();        //svuota il buffer
    double get_distance(double) const;    //resituisce la distanza del vettore più recente di quel relativo angolo
    bool is_buffer_empty() const;
    bool is_buffer_full() const;

    // Dichiarazione dell'operatore di stampa come friend
    void print_all_scans() const;
    friend std::ostream& operator<<(std::ostream& os, const LidarDriver& driver);
};

#endif //!LIDARDRIVER_H