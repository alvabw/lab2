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

    std::string toString() override;

    double operator()(double d) const override;

    Logarithm* clone() const override;





    //default constructor 

    Logarithm();



    //constructor som skapar logaritmisk uttryck 

    Logarithm(double c1, double c2, int b, const Expression& E);



    //copy constructor 

    Logarithm(const Logarithm& L);



    //assigment operator 

    Logarithm& operator=(const Logarithm& rhs);



    Logarithm& set_base(int b1);











private:

    double c1;

    double c2;

    int b;

    Expression* E;

};

