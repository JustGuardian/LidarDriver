#include "include/ArrayDati.h"

int main(){
    ArrayDati array(182);
    for (int i = 0; i<200; i++){
        array.push(i);
    }

    std::cout << array << " " << array.getAngle() << " " << array.getSize() << " " << 181/array.getSize() << std::endl;



    int y;
    std::cin >> y;
}