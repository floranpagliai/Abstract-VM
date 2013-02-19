//
// Operand.hpp for abstract_vm in /home/paglia_f//Dropbox/Epitech/tek2/C++/Abstract-VM/src
//
// Made by floran pagliai
// Login   <paglia_f@epitech.net>
//
// Started on  Tue Feb 19 16:31:59 2013 floran pagliai
// Last update Tue Feb 19 17:14:50 2013 floran pagliai
//

#ifndef __OPERAND_HPP__
#define __OPERAND_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include "IOperand.hpp"
#include "exception.hpp"

typedef struct s_operand {
  eOperandType	type;
  int		precision;
  long		min;
  long		max;
}		t_operand;

static t_operand operands[] =
  {
    {INT8, 0 , -128, 127},
    {INT16, 1, -32768, 32767},
    {INT32, 2, -2147483648, 2147483647},
    {FLOAT, 3, -32768, 32767},
    {DOUBLE, 4, -2147483648, 2147483647},
  };

template <typename T>
class Operand : public IOperand {
private:
  eOperandType	_type;
  int		_precision;
  T		_value;

public:
  explicit Operand(eOperandType type, const double &value) {
    _type = type;
    if (value > operands[type].min)
      {
	if (value < operands[type].max)
	  _precision = operands[type].precision;
	else
	  {
	    std::cout << "Overflow" << std::endl;
	    exit(0);
	  }
      }
    else
      {
	std::cout << "Underflow" << std::endl;
	exit(0);
      }
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

  virtual IOperand *operator-(const IOperand &rhs) const
  {
    IOperand		*operand = NULL;
    eOperandType	type;

    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    switch (type) {
    case INT8:
      operand = new Operand<char>(type, _value - atof(rhs.toString().c_str()));
      break;
    case INT16:
      operand = new Operand<short>(type, _value - atof(rhs.toString().c_str()));
      break;
    case INT32:
      operand = new Operand<int>(type, _value - atof(rhs.toString().c_str()));
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value - atof(rhs.toString().c_str()));
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value - atof(rhs.toString().c_str()));
      break;
    }
    return (operand);
  }

  virtual IOperand *operator*(const IOperand &rhs) const // mul
  {
    IOperand		*operand = NULL;
    eOperandType	type;

    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    switch (type) {
    case INT8:
      operand = new Operand<char>(type, _value * atof(rhs.toString().c_str()));
      break;
    case INT16:
      operand = new Operand<short>(type, _value * atof(rhs.toString().c_str()));
      break;
    case INT32:
      operand = new Operand<int>(type, _value * atof(rhs.toString().c_str()));
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value * atof(rhs.toString().c_str()));
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value * atof(rhs.toString().c_str()));
      break;
    }
    return (operand);
  }

  virtual IOperand *operator/(const IOperand &rhs) const // div
  {
IOperand		*operand = NULL;
    eOperandType	type;

    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    switch (type) {
    case INT8:
      operand = new Operand<char>(type, _value / atof(rhs.toString().c_str()));
      break;
    case INT16:
      operand = new Operand<short>(type, _value / atof(rhs.toString().c_str()));
      break;
    case INT32:
      operand = new Operand<int>(type, _value / atof(rhs.toString().c_str()));
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value / atof(rhs.toString().c_str()));
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value / atof(rhs.toString().c_str()));
      break;
    }
    return (operand);
  }

  virtual IOperand *operator%(const IOperand &rhs) const // mod
  {
//IOperand		*operand = NULL;
//    eOperandType	type;
//
//    if (_value != 0)
//        exit(-1);
//    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
//    switch (type) {
//    case INT8:
//      operand = new Operand<char>(type, _value % atof(rhs.toString().c_str()));
//      break;
//    case INT16:
//      operand = new Operand<short>(type, _value % atof(rhs.toString().c_str()));
//      break;
//    case INT32:
//      operand = new Operand<int>(type, _value % atof(rhs.toString().c_str()));
//      break;
//    case FLOAT:
//      operand = new Operand<float>(type, _value % atof(rhs.toString().c_str()));
//      break;
//    case DOUBLE:
//      operand = new Operand<double>(type, _value % atof(rhs.toString().c_str()));
//      break;
//    }
//    return (operand);
  }

  std::ostream &operator<<(std::ostream &os) {
    os << this->getValue();
    return (os);
  }
};

std::ostream		&operator<<(std::ostream &os, IOperand const &rhs);

#endif /*__OPERAND_HPP */
