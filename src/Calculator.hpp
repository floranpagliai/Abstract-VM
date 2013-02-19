#ifndef __CALCULATOR_HPP__
#define	__CALCULATOR_HPP__

# include <cstdlib>
# include <string>
# include <stack>
# include "IOperand.hpp"
# include "Operand.hpp"

typedef	std::stack<IOperand *> opStack;

class	Calculator
{
private:
  typedef IOperand *(Calculator::*funcPtr)(const std::string &);

private:
  funcPtr		_funcList[5];
  opStack		_stack;

private:
  IOperand		*createInt8(const std::string &value);
  IOperand		*createInt16(const std::string &value);
  IOperand		*createInt32(const std::string &value);
  IOperand		*createFloat(const std::string &value);
  IOperand		*createDouble(const std::string &value);

public:
  Calculator();
  ~Calculator() {}

  IOperand		*createOperand(eOperandType type, const std::string &value);
  void			push(IOperand *rhs);
  void			pop();
  IOperand		*dump();

  IOperand		*add();
  IOperand		*sub();
  IOperand		*mul();
  IOperand		*div();
  IOperand		*mod();
};


#endif	/* __CALCULATOR_HPP__ */

