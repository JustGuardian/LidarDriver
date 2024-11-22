#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H

#include "CircularArray.h"
#include <vector>
#include <iostream>

class LidarDriver{
private:
    CircularArray array;
public:
    LidarDriver(int x = 10);       //costruttore
    void new_scan(std::vector<double>); //inserisce un nuovo vettore
    std::vector<double> get_scan();     //restituisce vettore più vecchio e lo rimuove dal buffer
    void clear_buffer();        //svuota il buffer
    double get_distance(double);    //resituisce la distanza del vettore più recente di quel relativo angolo
};

#endif //!LIDARDRIVER_H