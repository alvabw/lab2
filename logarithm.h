/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {
    // ADD CODE
public: 
    //de två virtual aka derived 
    explicit operator std::string() const override;
    double operator()(double d) const override;
    Logarithm* clone() const override; 


    //default constructor
    Logarithm(); 

    //destructor
    ~Logarithm();

    //constructor som skapar logaritmisk uttryck
    Logarithm(const Expression& arg1, double arg2, double arg3, int arg4); 

    //copy constructor
    Logarithm(const Logarithm& rhs);

    //assigment operator
    Logarithm& operator=(const Logarithm& rhs); 

    Logarithm& set_base(int b1); 

  



private: 
    double c1; 
    double c2; 
    int b; 
    Expression* E; 
};
