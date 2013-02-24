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
        if (ac == 2) {
            std::ifstream file(av[1], std::ios::in);
            if (!file) {
                throw Exception("File not found");
            }
            while (getline(file, line)) {
                lexer.addLine(line);
            }
            file.close();
            lexer.execLines();
        } else {
            do {
                getline(std::cin, line, '\n');
                lexer.addLine(line);
            } while (line.find(";;") == line.npos);
            lexer.execLines();
        }
    } catch (const Exception &e) {
        std::cerr << "ERROR : " << e.what() << std::endl;
    }
    return (0);
}
