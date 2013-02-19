#ifndef __IOPERAND_HPP__
#define __IOPERAND_HPP__

#include <string>
#include <iostream>

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

typedef struct	s_operand
{
  eOperandType	type;
  std::string	type_name;
  int		precision;
  long		max_size;
  long		min_size;
} t_operand;

class IOperand {
public:
    virtual std::string const& toString() const = 0;

    virtual int getPrecision() const = 0;
    virtual eOperandType getType() const = 0;

    virtual IOperand *operator+(const IOperand &rhs) const = 0;
    virtual IOperand *operator-(const IOperand &rhs) const = 0;
    virtual IOperand *operator*(const IOperand &rhs) const = 0;
    virtual IOperand *operator/(const IOperand &rhs) const = 0;
    virtual IOperand *operator%(const IOperand &rhs) const = 0;

    virtual ~IOperand() {
    }
};

#endif /*__IOPERAND_HPP__ */

