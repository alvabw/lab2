/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include "expression.h"
#include <format>

class Polynomial : public Expression {
    // ADD CODE

public: 
    //explicit operator std::string() const override;
    explicit operator std::string() const override;

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
    Polynomial& operator=(const Polynomial& rhs); //inte default, vi har tagit bort default i expression.h

    //add and assign operator
    Polynomial& operator+=(const Polynomial& rhs); 

    //addition of two polynomials
    friend Polynomial operator+(const Polynomial& lhs, const Polynomial rhs);

    //addition of polynomial with real double
    friend Polynomial operator+( const Polynomial& lhs, double rhs); //friend has accesss to private data members: coeff :)
  //  friend Polynomial& operator+=(double d, Polynomial p);
    
    // subscript operator access the value of a coefficient.
    double& operator[](int index);
    double operator[](int index) const;

private:
    std::vector<double> coeff; 
};

