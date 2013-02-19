//
// Operand.cpp for abstract_vm in /home/paglia_f//Dropbox/Epitech/tek2/C++/Abstract-VM/src
// 
// Made by floran pagliai
// Login   <paglia_f@epitech.net>
// 
// Started on  Tue Feb 19 16:32:09 2013 floran pagliai
// Last update Tue Feb 19 16:32:10 2013 floran pagliai
//

#include "Operand.hpp"

std::ostream &operator<<(std::ostream &os, IOperand const &rhs) {
    os << rhs.toString();
    return (os);
}
