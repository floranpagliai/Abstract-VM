#include "Operand.hpp"

std::ostream &operator<<(std::ostream &os, IOperand const &iop) {
    os << iop.toString();
    return (os);
}