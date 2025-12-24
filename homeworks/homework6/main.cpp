#include <iostream>
#include "Source.h"


int main()
{
    double x, y;
    std::cout << "Ââåäèòå õ è ó: ";
    std::cin >> x >> y;
    double R = calculate_R(x);
    double S = calculate_S(y);
    std::cout << "R = " << R << std::endl;
    std::cout << "S = " << S << std::endl;
    return 0;
}
