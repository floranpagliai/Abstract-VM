#include <iostream>
#include <fstream>
#include <string>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Calculator.hpp"
#include "Exception.hpp"
#include "Lexer.hpp"

int main(int ac, char **av) {
    try {
        Lexer           lexer;
        std::string     line;
        if (ac > 1) {
            std::ifstream file(av[1], std::ios::in);
            if (!file) {
                throw Exception("File not found");
            }
            do {
                getline(file, line);
                lexer.addLine(line);
            } while (line != "exit" && line != ";;");
            file.close();
            lexer.printLine();
        }
//      else {
//            do {
//                getline(std::cin, line, '\n');
//            } while (line.find(";;") == line.npos);
//        }
        //        Calculator a;
        //        IOperand *op1 = a.createOperand(INT8, "0");
        //        IOperand *op2 = a.createOperand(INT8, "2");
        //        IOperand *op3 = a.createOperand(INT8, "4");
        //
        //        a.push(op1);
        //        a.push(op2);
        //        a.push(op3);
        //        a.push(a.createOperand(INT8, "2"));
        //
        //        std::cout << "Dump: " << std::endl;
        //        a.dump();
        //        std::cout << "Result add: " << *(a.add()) << std::endl;
        //        std::cout << "Dump: " << std::endl;
        //        a.dump();
        //        std::cout << "Result sub: " << *(a.sub()) << std::endl;
        //        std::cout << "Dump: " << std::endl;
        //        a.dump();
        //        std::cout << "Result mod: " << *(a.mod()) << std::endl;
        //        std::cout << "Result mul: " << *(a.mul()) << std::endl;
    } catch (const Exception &e) {
        std::cerr << "ERROR : " << e.what() << std::endl;
    }
    return (0);
}
