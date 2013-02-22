/*
 * File:   Lexer.hpp
 * Author: floran
 *
 * Created on 20 février 2013, 18:32
 */

#ifndef __LEXER_HPP__
#define	__LEXER_HPP__

#include <iostream>
#include <string>
#include <list>
#include "Calculator.hpp"
#include "Operand.hpp"

class Lexer {
private:
    typedef void (Calculator::*funcPtr)();
    std::list<std::string> _line;
    funcPtr _funcList[7];
public:

    Lexer() {
        _funcList[0] = &Calculator::add;
        _funcList[1] = &Calculator::sub;
        _funcList[2] = &Calculator::mul;
        _funcList[3] = &Calculator::div;
        _funcList[4] = &Calculator::mod;
        _funcList[5] = &Calculator::pop;
        _funcList[6] = &Calculator::dump;
    }

    virtual ~Lexer() {
    }

    void addLine(std::string str) {
        if (str[0] != ';')
            _line.push_back(str);
    }

    std::list<std::string> getContent(std::string line) {
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

    void execLines() {
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
        }
        c.dump();
    }

    void printLines() {
        for (std::list<std::string>::iterator it = _line.begin(); it != _line.end(); ++it)
            std::cout << *it << std::endl;
    }
};

#endif	/* __LEXER_HPP__ */

