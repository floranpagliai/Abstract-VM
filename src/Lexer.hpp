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
    std::list<std::string> _line;
    
public:
    Lexer() {}
    virtual ~Lexer() {}

    void addLine(std::string str);
    std::list<std::string> getContent(std::string line);
    void execLines();
};

#endif	/* __LEXER_HPP__ */

