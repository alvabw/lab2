/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <format>
#include <cmath>
#include <vector>


// ADD implementation of the member functions for class Logarithm
Logarithm::operator std::string() const {
	//hur man kallar p� den:  std::string{l0}; 
	
	std::string sign = c2 < 0.0 ? "-" : "+"; 
	std::string S = std::format("{:.2f} {} {:.2f} * Log_{}( {} )", c1, sign, std::abs(c2), b, std::string{ *E }); //dereference E eftersom E �r en pointer

	return S; 
}

//F� ett y-v�rde genom att skicka in ett v�rde p� x 
double Logarithm::operator()(double d) const{
	 //man skickar in ett v�rde "d" f�r x i this som �r ett polynom
	double returnValue = 0.0;
	double expressionValue = (*E)(d); 

	returnValue += c1 + c2 * (std::log(expressionValue)/std::log(b));
	return returnValue;
}

//default contructor
Logarithm::Logarithm() {

	c1 = 0.0; c2 = 1.0; b = 2; E = new Polynomial{{0,1} };
}

//destructor
Logarithm::~Logarithm(){
	delete E;
	/*b = 0; beh�vs inte. De �r emeber variabler som st�das upp automatiskt
	c1 = 0; 
	c2 = 0;*/
}


Logarithm::Logarithm(const Expression& arg1, double arg2, double arg3, int arg4) {
	
	c1 = arg2; 
	c2 = arg3;
	//man kan inte skriva E = E eftersom vi inte har f�rsett expression med en operator= 
	E = arg1.clone(); //skapar en ny logarithm 
	b = arg4; 
}

//copy constructor
Logarithm::Logarithm(const Logarithm& rhs) {
	c1 = rhs.c1;
	c2 = rhs.c2;
	b = rhs.b;
	E = (*rhs.E).clone(); //dereference
}

//assignment opperator
Logarithm& Logarithm::operator=(const Logarithm& rhs) {
	c1 = rhs.c1; 
	c2 = rhs.c2; 
	b = rhs.b;
	delete E;
	E = (*rhs.E).clone(); 

	return *this; 
}

//set_base modifies the base b 
Logarithm& Logarithm::set_base(int b1) {
	b = b1; 
	return *this; 
	
}

//clone virtual
Logarithm* Logarithm::clone() const {
	return new Logarithm{ *this }; //returns pointer till det nya objektet. man kallar p� den med en pointer ocks�. :) 
}