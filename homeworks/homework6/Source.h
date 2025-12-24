#include <cmath>
#include <stdexcept>
using namespace std;

const double pi = 3.1415;


double calculate_S(double y) {
    if (y <= 0) throw std::invalid_argument("¬ведите y >= 0!");
    return sqrt(sqrt(y)) * pow(2, 1 / y);
}

double calculate_R(double x) {
    if (fmod(x, 4) == 0) throw std::invalid_argument("¬ведите x не кратный 4");
    return cos(pi / 4 * x) / sin(pi / 4 * x);
}