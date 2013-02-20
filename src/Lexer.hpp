/*
 * File:   Lexer.hpp
 * Author: floran
 *
 * Created on 20 février 2013, 18:32
 */

#ifndef LEXER_HPP
#define	LEXER_HPP

#include <iostream>
#include <string>
#include <list>

class Lexer {
private:
    std::list<std::string> _line;
public:

    Lexer() {
    }

    virtual ~Lexer() {
    }

    void addLine(std::string str) {
        if ()
        _line.push_back(str);
    }

    void printLine() {
        for (std::list<std::string>::iterator it = _line.begin(); it != _line.end(); ++it)
            std::cout << *it << std::endl;
    }
};

#endif	/* LEXER_HPP */

