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

typedef struct s_func {
    std::string name;

}		t_func;

static t_func funcs[] =
  {
    {"add"},
  };

class Lexer {
private:
    std::list<std::string> _line;
public:

    Lexer() {
    }

    virtual ~Lexer() {
    }

    void addLine(std::string str) {
        for (int i = 0; str[i]; i++) {
            if (str[i] != ';')
                _line.push_back(str);
            break;
        }
    }

    std::list<std::string> getContent(std::string line) {
        std::list<std::string>  tokens;
        std::string             tmp;
            for (int i = 0; line.c_str()[i]; i++) {
                if (line.c_str()[i] == ' ' || line.c_str()[i] == '(' || line.c_str()[i] == ')') {
                    i++;
                    tokens.push_back(tmp);
                    tmp.clear();
                }
                tmp += line.c_str()[i];
            }
        return(tokens);
    }

    void execLines() {
        Calculator              c;
        std::string             tmp;
        std::string             line;
        for (std::list<std::string>::iterator it = _line.begin(); it != _line.end(); ++it) {
            line = *it;
            for (int i = 0; line.c_str()[i]; i++)
            {
                if (line.c_str()[i] == ')'){
                    std::list<std::string>  tokens = getContent(line);
                    if (tokens.front() == "push") {
                        tokens.pop_front();
                        int x = 0;
                        while(operands[x++].name != tokens.front()) {
                        }
                        tokens.pop_front();
                        IOperand *op = c.createOperand(operands[x - 1].type, tokens.front());
                        tokens.pop_front();
                        c.push(op);

                    }
                    else if (tokens.front() == "assert") {
                        tokens.pop_front();
                        IOperand *op = c.get();
                        if (my_atoi(tokens.front()) == op->getType()) {
                            tokens.pop_front();
                            if (tokens.front() != op->toString()) {
                                throw Exception("assert instruction not verify.");
                            }
                            tokens.pop_front();
                        }
                        else
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

