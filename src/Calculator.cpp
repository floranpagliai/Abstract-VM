//
// Calculator.cpp for abstract_vm in /home/paglia_f//Dropbox/Epitech/tek2/C++/Abstract-VM/src
// 
// Made by floran pagliai
// Login   <paglia_f@epitech.net>
// 
// Started on  Tue Feb 19 16:31:29 2013 floran pagliai
// Last update Tue Feb 19 17:37:22 2013 floran pagliai
//

#include "Calculator.hpp"

Calculator::Calculator()
{
  _funcList[0] = &Calculator::createInt8;
  _funcList[1] = &Calculator::createInt16;
  _funcList[2] = &Calculator::createInt32;
  _funcList[3] = &Calculator::createFloat;
  _funcList[4] = &Calculator::createDouble;
}

IOperand		*Calculator::createInt8(const std::string &value)
{
  IOperand		*operand;

  operand = new Operand<char>(INT8, atof(value.c_str()));
  return (operand);
}

IOperand		*Calculator::createInt16(const std::string &value)
{
  IOperand		*operand;

  operand = new Operand<short>(INT16, atof(value.c_str()));
  return (operand);
}

IOperand		*Calculator::createInt32(const std::string &value)
{
  IOperand		*operand;

  operand = new Operand<int>(INT32, atof(value.c_str()));
  return (operand);
}

IOperand		*Calculator::createFloat(const std::string &value)
{
  IOperand		*operand;

  operand = new Operand<float>(FLOAT, atof(value.c_str()));
  return (operand);
}

IOperand		*Calculator::createDouble(const std::string &value)
{
  IOperand		*operand;

  operand = new Operand<double>(DOUBLE, atof(value.c_str()));
  return (operand);
}

IOperand		*Calculator::createOperand(eOperandType type, const std::string &value)
{
  return ((this->*_funcList[type])(value));
}

void			Calculator::push(IOperand *rhs)
{
  _stack.push(rhs);
}

void			*Calculator::pop()
{
  if (_stack.size() <= 0)
    {
      std::cout << "Pop on empty stack." << std::endl;
      exit(-1);
    }
  _stack.pop();
}

IOperand		*Calculator::get()
{
  if (_stack.size() <= 0)
    return (NULL);
  return (_stack.top());
}

IOperand		*Calculator::dump()
{
  if (_stack.size() <= 0)
    return (NULL);
  return (_stack.top());
}

IOperand		*Calculator::add()
{
  IOperand		*a = get();
  pop();
  IOperand		*b = get();
  pop();

  push(*a + *b);
  return (get());
}

IOperand		*Calculator::sub()
{
  IOperand		*a = get();
  pop();
  IOperand		*b = get();
  pop();

  push(*a - *b);
  return (get());
}

IOperand		*Calculator::mul()
{
  IOperand		*a = get();
  pop();
  IOperand		*b = get();
  pop();

  push(*a * *b);
  return (get());
}

IOperand		*Calculator::div()
{
  IOperand		*a = get();
  pop();
  IOperand		*b = get();
  pop();

  push(*a / *b);
  return (get());
}

IOperand		*Calculator::mod()
{
  IOperand		*a = get();
  pop();
  IOperand		*b = get();
  pop();

  push(*a % *b);
  return (get());
}
