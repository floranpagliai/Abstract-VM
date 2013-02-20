#include <sstream>

int     my_atoi(std::string str) {
    std::stringstream           ss;
    int                         nb;

    ss << str;
    ss >> nb;
    return nb;
}
