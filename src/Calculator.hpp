//
// Calculator.hpp for abstract_vm in /home/paglia_f//Dropbox/Epitech/tek2/C++/Abstract-VM/src
//
// Made by floran pagliai
// Login   <paglia_f@epitech.net>
//
// Started on  Tue Feb 19 16:31:12 2013 floran pagliai
// Last update Tue Feb 19 17:33:08 2013 floran pagliai
//

#ifndef __CALCULATOR_HPP__
#define	__CALCULATOR_HPP__

#include <iostream>
#include <string>
#include <list>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Exception.hpp"

typedef std::list<IOperand *> opStack;

class Calculator {
private:
    typedef IOperand *(Calculator::*funcPtr)(const std::string &);
    funcPtr _funcList[5];
    opStack _stack;

private:
    IOperand *createInt8(const std::string &value);
    IOperand *createInt16(const std::string &value);
    IOperand *createInt32(const std::string &value);
    IOperand *createFloat(const std::string &value);
    IOperand *createDouble(const std::string &value);

public:
    Calculator();

    ~Calculator() {
    }

    IOperand *createOperand(eOperandType type, const std::string &value);

    IOperand *get();

    void push(IOperand *rhs);
    void pop();
    void dump();

    void add();
    void sub();
    void mul();
    void div();
    void mod();
};


#endif	/* __CALCULATOR_HPP__ */

