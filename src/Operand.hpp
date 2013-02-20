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
#include "Exception.hpp"

typedef struct s_operand {
  eOperandType	type;
  std::string   name;
  int		precision;
  long		min;
  long		max;
}		t_operand;

static t_operand operands[] =
  {
    {INT8, "int8", 0 , -128, 127},
    {INT16, "int16", 1, -32768, 32767},
    {INT32, "int32", 2, -2147483648, 2147483647},
    {FLOAT, "float", 3, -32768, 32767},
    {DOUBLE, "double", 4, -2147483648, 2147483647},
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
    if (value < operands[type].max)
      {
	if (value > operands[type].min)
	  _precision = operands[type].precision;
	else
	  throw Exception("Underflow.");
      }
    else
      throw Exception("Overflow.");
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
      operand = new Operand<char>(type, _value + my_atof(rhs.toString()));
      break;
    case INT16:
      operand = new Operand<short>(type, _value + my_atof(rhs.toString()));
      break;
    case INT32:
      operand = new Operand<int>(type, _value + my_atof(rhs.toString()));
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value + my_atof(rhs.toString()));
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value + my_atof(rhs.toString()));
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
      operand = new Operand<char>(type, _value - my_atof(rhs.toString()));
      break;
    case INT16:
      operand = new Operand<short>(type, _value - my_atof(rhs.toString()));
      break;
    case INT32:
      operand = new Operand<int>(type, _value - my_atof(rhs.toString()));
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value - my_atof(rhs.toString()));
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value - my_atof(rhs.toString()));
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
      operand = new Operand<char>(type, _value * my_atof(rhs.toString()));
      break;
    case INT16:
      operand = new Operand<short>(type, _value * my_atof(rhs.toString()));
      break;
    case INT32:
      operand = new Operand<int>(type, _value * my_atof(rhs.toString()));
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value * my_atof(rhs.toString()));
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value * my_atof(rhs.toString()));
      break;
    }
    return (operand);
  }

  virtual IOperand *operator/(const IOperand &rhs) const
  {
IOperand		*operand = NULL;
    eOperandType	type;
     const Operand		&tmp = static_cast<const Operand &>(rhs);

    if (my_atof(tmp.toString()) == 0)
      throw Exception("Division by zero.");
    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    switch (type) {
    case INT8:
      operand = new Operand<char>(type, _value / my_atof(rhs.toString()));
      break;
    case INT16:
      operand = new Operand<short>(type, _value / my_atof(rhs.toString()));
      break;
    case INT32:
      operand = new Operand<int>(type, _value / my_atof(rhs.toString()));
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value / my_atof(rhs.toString()));
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value / my_atof(rhs.toString()));
      break;
    }
    return (operand);
  }

  virtual IOperand *operator%(const IOperand &rhs) const
  {
      IOperand                  *operand = NULL;
      eOperandType              type;
      const Operand		&tmp = static_cast<const Operand &>(rhs);

    if (my_atof(tmp.toString()) == 0)
      throw Exception("Modulo by zero.");
    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    if (_type == FLOAT || rhs.getType() == FLOAT)
        throw Exception("Modulo with float.");
    else if (_type == DOUBLE || rhs.getType() == DOUBLE)
        throw Exception("Modulo with double.");
    operand = new Operand(type, (int)_value % my_atoi(tmp.toString()));
    return (operand);
  }

  std::ostream &operator<<(std::ostream &os) {
    os << this->getValue();
    return (os);
  }
};

std::ostream		&operator<<(std::ostream &os, IOperand const &rhs);

#endif /*__OPERAND_HPP */
