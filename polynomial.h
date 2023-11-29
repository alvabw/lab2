/*************************

* Class Polynomial       *

* TNG033: Lab 2          *

**************************/



#pragma once 



#include <iostream> 

#include <vector> 

#include "expression.h" 



class Polynomial : public Expression {

    // ADD CODE 



public:

    //explicit operator std::string() const override; 

    std::string toString() override;

    double operator()(double d) const override;





    //constructor create a set with elements in V 

    explicit Polynomial(const std::vector<double>& V);



    //create polynom from a real constant 

    Polynomial(double arg);



    //copy constructor 

    Polynomial(const Polynomial&) = default;



    //destructor 

    ~Polynomial() = default;



    Polynomial* clone() const override;



    //an assignment operator 

    Polynomial& operator=(const Polynomial&) = default;



    //add and assign operator 

    Polynomial& operator+=(const Polynomial& rhs);



    //addition of two polynomials 

    Polynomial& operator+(const Polynomial& rhs) const;



    //addition of polynomial with real double 

    friend Polynomial& operator+(double d, Polynomial p); //friend has accesss to private data members: coeff :) 

    //  friend Polynomial& operator+=(double d, Polynomial p); 



      // subscript operator access the value of a coefficient. 

    double& operator[](int index);



private:

    std::vector<double> coeff;

};



/*

* std::vector should be used to store polinomial's coefficients

*/



