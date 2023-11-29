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

std::string Polynomial::toString() {



    std::string S = "";

    for (int i = 0; i < coeff.size(); i++) {

        if (i == 0) {

            S += coeff[i];

        }

        if (i == 1) {

            S += std::format("+ {:.2f} * x", coeff[i]); //två decimaler efter decimaltecknet 

        }

        S += std::format("+ {:.2f} * x^{}", coeff[i], i);



    }

    return S;

}





//Få ett y-värde genom att skicka in ett värde på x  

double Polynomial::operator()(double d) const {

    //man skickar in ett värde "d" för x i this som är ett polynom 

    int returnValue = 0;



    for (int i = 0; i <= coeff.size(); i++) {

        returnValue += (coeff[i] * std::pow(d, i));

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

    return new Polynomial{ *this };

}



//add and assign operator 

Polynomial& Polynomial::operator+=(const Polynomial& rhs) {

    for (int i = 0; i < rhs.coeff.size(); i++) {

        if (i >= coeff.size()) {

            coeff.push_back(rhs.coeff[i]);

        }

        else {

            coeff[i] += rhs.coeff[i];

        }

    }

    return *this;

    //[1, 2, 3] + [1, 2] = [2, 4, 3] 

}



Polynomial& Polynomial::operator+(const Polynomial& rhs) const {   //tv å const...??? 

    Polynomial p(*this); //using the copy constructor, changing p dont affect lhs 

    p += rhs; //changing p  

    return(p); //returned by value  

}





Polynomial& operator+(double d, Polynomial& p) {



    return Polynomial(d) + p;



    //p.coeff[0] += d;   // Assuming coeff is the array of coefficients in your Polynomial 

    //return p; 

}



//subcript operator 

double& Polynomial::operator[](int index) {

    return coeff[index];



}



