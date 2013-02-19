#include "Calculator.hpp"

Abstract::Abstract()
{
  _funcList[0] = &Abstract::createInt8;
  _funcList[1] = &Abstract::createInt16;
  _funcList[2] = &Abstract::createInt32;
  _funcList[3] = &Abstract::createFloat;
  _funcList[4] = &Abstract::createDouble;
}

IOperand		*Abstract::createInt8(const std::string &value)
{
  IOperand		*out;

  out = new Operand<char>(Int8, atof(value.c_str()));
  return (out);
}

IOperand		*Abstract::createInt16(const std::string &value)
{
  IOperand		*out;

  out = new Operand<short>(Int16, atof(value.c_str()));
  return (out);
}

IOperand		*Abstract::createInt32(const std::string &value)
{
  IOperand		*out;

  out = new Operand<int>(Int32, atof(value.c_str()));
  return (out);
}

IOperand		*Abstract::createFloat(const std::string &value)
{
  IOperand		*out;

  out = new Operand<float>(Float, atof(value.c_str()));
  return (out);
}

IOperand		*Abstract::createDouble(const std::string &value)
{
  IOperand		*out;

  out = new Operand<double>(Double, atof(value.c_str()));
  return (out);
}

IOperand		*Abstract::createOperand(eOperandType type, const std::string &value)
{
  return ((this->*_funcList[type])(value));
}

void			Abstract::push(IOperand *iop)
{
  _stack.push(iop);
}

void			Abstract::pop()
{
  if (_stack.size() <= 0)
    {
      std::cout << "Error: Pop on empty stack." << std::endl;
      exit(-1);
    }
  _stack.pop();
}

IOperand		*Abstract::dump()
{
  if (_stack.size() <= 0)
    return (NULL);
  return (_stack.top());
}

IOperand		*Abstract::add()
{
  IOperand		*a = dump();
  pop();
  IOperand		*b = dump();
  pop();

  push(*a + *b);
  return (dump());
}

IOperand		*Abstract::sub()
{
  IOperand		*a = dump();
  pop();
  IOperand		*b = dump();
  pop();

  push(*a - *b);
  return (dump());
}

IOperand		*Abstract::mul()
{
  IOperand		*a = dump();
  pop();
  IOperand		*b = dump();
  pop();

  push(*a * *b);
  return (dump());
}

IOperand		*Abstract::div()
{
  IOperand		*a = dump();
  pop();
  IOperand		*b = dump();
  pop();

  push(*a / *b);
  return (dump());
}

IOperand		*Abstract::mod()
{
  IOperand		*a = dump();
  pop();
  IOperand		*b = dump();
  pop();

  push(*a % *b);
  return (dump());
}