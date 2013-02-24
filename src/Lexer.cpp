#include "Lexer.hpp"

void Lexer::addLine(std::string str) {
    if (str[0] != ';')
        _line.push_back(str);
}

std::list<std::string> Lexer::getContent(std::string line) {
    std::list<std::string> tokens;
    std::string tmp;
    for (int i = 0; line.c_str()[i]; i++) {
        if (line.c_str()[i] == ' ' || line.c_str()[i] == '(' || line.c_str()[i] == ')') {
            i++;
            tokens.push_back(tmp);
            tmp.clear();
        }
        tmp += line.c_str()[i];
    }
    return (tokens);
}

void Lexer::execLines() {
    Calculator c;
    std::string tmp;
    std::string line;
    for (std::list<std::string>::iterator it = _line.begin(); it != _line.end(); ++it) {
        line = *it;
        for (int i = 0; line.c_str()[i]; i++) {
            if (line.c_str()[i] == ')') {
                std::list<std::string> tokens = getContent(line);
                if (tokens.front() == "push") {
                    tokens.pop_front();
                    int x = 0;
                    while (operands[x++].name != tokens.front()) {
                    }
                    tokens.pop_front();
                    IOperand *op = c.createOperand(operands[x - 1].type, tokens.front());
                    tokens.pop_front();
                    c.push(op);

                } else if (tokens.front() == "assert") {
                    tokens.pop_front();
                    IOperand *op = c.get();
                    if (my_atoi(tokens.front()) == op->getType()) {
                        tokens.pop_front();
                        if (tokens.front() != op->toString()) {
                            throw Exception("assert instruction not verify.");
                        }
                        tokens.pop_front();
                    } else
                        throw Exception("assert instruction not verify.");
                }
            }
        }
        if (line == "add")
            c.add();
        else if (line == "sub")
            c.sub();
        else if (line == "mul")
            c.mul();
        else if (line == "div")
            c.div();
        else if (line == "mod")
            c.mod();
        else if (line == "pop")
            c.pop();
        else if (line == "dump")
            c.dump();
    }
    if (line != "exit") {
        throw Exception("No exit instruction found.");
    }
}