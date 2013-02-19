#ifndef __OPERAND_HPP__
#define __OPERAND_HPP__

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "IOperand.hpp"

template <typename T>
class Operand : public IOperand {
private:
  eOperandType	_type;
  int		_precision;
  T		_value;

public:

  explicit Operand(eOperandType type, const double &value) {
    _type = type;
    if (value > -128 && value < 127)
      _precision = 0;
    else if (value > -32768 && value < 32767)
      _precision = 1;
    else if (value > -2147483648 && value < 2147483647)
      _precision = 2;
    else if (value > -32768 && value < 32767)
      _precision = 3;
    else if (value > -12147483648 && value < 2147483647)
      _precision = 4;
    else
      exit(0);
    _value = value;
  }

  virtual std::string const &toString() const {
    std::string *str = new std::string();
    std::ostringstream ss;

    if (_type == INT8)
      ss << (int) _value;
    else
      ss << _value;
    str->append(ss.str());
    return (*str);
  }
  
  virtual int getPrecision() const {
    return (_precision);
  }

  virtual eOperandType getType() const {
    return (_type);
  }

  virtual T getValue() const {
    return (_value);
  }

  virtual IOperand *operator+(const IOperand &rhs) const {
    IOperand		*operand = NULL;
    eOperandType	type;

    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    switch (type) {
    case INT8:
      operand = new Operand<char>(type, _value + atof(rhs.toString().c_str()));
      break;
    case INT16:
      operand = new Operand<short>(type, _value + atof(rhs.toString().c_str()));
      break;
    case INT32:
      operand = new Operand<int>(type, _value + atof(rhs.toString().c_str()));
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value + atof(rhs.toString().c_str()));
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value + atof(rhs.toString().c_str()));
      break;
    }
    return (operand);
  }

  virtual IOperand *operator-(const IOperand &rhs) const // sub
  {
    
  }

  virtual IOperand *operator*(const IOperand &rhs) const // mul
  {
    
  }

  virtual IOperand *operator/(const IOperand &rhs) const // div
  {
    
  }

  virtual IOperand *operator%(const IOperand &rhs) const // mod
  {
    
  }

  std::ostream &operator<<(std::ostream &os) {
    os << this->getValue();
    return (os);
  }
};

std::ostream		&operator<<(std::ostream &os, IOperand const &rhs);

#endif /*__OPERAND_HPP */
