#include <iostream>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Calculator.hpp"
#include "exception.hpp"

int main(int ac, char **av) {
    (void) ac;
    (void) av;
    try {
        Calculator a;
        IOperand *op1 = a.createOperand(INT8, "2");
        IOperand *op2 = a.createOperand(INT8, "2");
        IOperand *op3 = a.createOperand(INT8, "3");

        a.push(op1);
        a.push(op2);
        a.push(op3);
        a.push(a.createOperand(INT8, "3"));

        std::cout << "Dump: " << std::endl;
        a.dump();
        std::cout << "Result add: " << *(a.add()) << std::endl;
        std::cout << "Dump: " << std::endl;
        a.dump();
        std::cout << "Result sub: " << *(a.sub()) << std::endl;
        std::cout << "Dump: " << std::endl;
        a.dump();
        std::cout << "Result mul: " << *(a.mul()) << std::endl;
        std::cout << "Result mul: " << *(a.mul()) << std::endl;
    } catch (const Exception &e) {
        std::cerr << "ERROR : " << e.what() << std::endl;
    }

    return (0);
}
