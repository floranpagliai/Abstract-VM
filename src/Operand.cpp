#include "Operand.hpp"

std::ostream &operator<<(std::ostream &os, IOperand const &rhs) {
    os << rhs.toString();
    return (os);
}
