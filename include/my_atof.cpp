#include <sstream>

double  my_atof(std::string str) {
    std::stringstream           ss;
    double                      nb;

    ss << str;
    ss >> nb;
    return nb;
}
