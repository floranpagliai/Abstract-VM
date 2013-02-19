#include <iostream>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Calculator.hpp"

int		main(int ac, char **av)
{
  (void) ac;
  (void) av;
  Calculator	a;
  IOperand	*op1 = a.createOperand(INT8, "2");
  IOperand	*op2 = a.createOperand(INT8, "2");
  IOperand	*op3 = a.createOperand(INT8, "130");

  a.push(op1);
  a.push(op2);
  a.push(op3);
  a.push(a.createOperand(DOUBLE, "2.2"));

  std::cout << "Result add: " << *(a.add()) << std::endl;
  std::cout << "Result add: " << *(a.add()) << std::endl;
  std::cout << "Result add: " << *(a.add()) << std::endl;

  return (0);
}
