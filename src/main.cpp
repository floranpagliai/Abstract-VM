/*
 * File:   main.cpp
 * Author: floran
 *
 * Created on 13 février 2013, 13:58
 */


using namespace std;

int main(int argc, char** argv) {
    Calculator calc;

    calc.push(21);
    calc.push(42);
    calc.dump();
    calc.sub();
    calc.dump();
    calc.push(21);
    calc.add();
    calc.dump();
    return 0;
}

