/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <vector>
#include <cmath>
#include <format>
// ADD implementation of the member functions for class Polynomial

//conversion from expressions to string
//std::string Polynomial::toString() {
 Polynomial::operator std::string() const{

    std::string S = "";
    for (int i = 0; i < coeff.size(); i++) {
        if (i == 0) {
            S += std::format("{:.2f}", coeff[i]);
        }
        else {
            if (coeff[i] < 0) {
                S += std::format(" - {:.2f} * X^{}", abs(coeff[i]), i);
            }
            else {
                S += std::format(" + {:.2f} * X^{}", coeff[i], i);
            }
        }
    }
    return S; 
}


//Få ett y-värde genom att skicka in ett värde på x 
double Polynomial::operator()(double d) const {
    //man skickar in ett värde "d" för x i this som är ett polynom
    double returnValue = 0;

    for (int i = 0; i < coeff.size(); i++) {
        returnValue += ((coeff[i])* (std::pow(d,i)));
    }
    return returnValue; 
}


//convert vector into a polynomial
Polynomial::Polynomial(const std::vector<double>& V) {
    for (double i : V) {
        coeff.push_back(i); 
    }
    
}

//convert real constant into a polynomial
Polynomial::Polynomial(double arg) {
    coeff.push_back(arg); 
}

Polynomial* Polynomial::clone() const {
    return new Polynomial{*this};
}

//an assignment operator
Polynomial& Polynomial::operator=(const Polynomial& rhs) {
    if (this != &rhs) {
        coeff = rhs.coeff; 
    }
    return *this; 
}

//add and assign operator
Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
    for (size_t i = 0; i < rhs.coeff.size(); i++) {

        if (i >= coeff.size()) { //SEDAN läggs de resternde till 
            coeff.push_back(rhs.coeff[i]); 
        }
        else {
            coeff[i] += rhs.coeff[i]; //först händer detta 
        }
    }
    return *this; 
    //[1, 2, 3] + [1, 2] = [2, 4, 3]
}

Polynomial operator+(const Polynomial& lhs, const Polynomial rhs){   //tv å const...???
    Polynomial p(lhs); //using the copy constructor, changing p dont affect lhs
    return p += rhs; //changing p, instead of changing lhs
}


Polynomial operator+(const Polynomial& lhs, double rhs) {
   return lhs + Polynomial(rhs);
}

//subcript operator
double& Polynomial::operator[](int index) {  //modifierar coeff vid ett index
        return coeff[index]; 
}

double Polynomial::operator[](int index) const { //hämtar en coeff vid ett index 
    return coeff[index];
}

//a1=2;
//2 = a1; 

