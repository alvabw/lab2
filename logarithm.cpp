/*********************************************************

* Class Logarithm member functions implementation        *

* TNG033: Lab 2                                          *

**********************************************************/



#include "logarithm.h" 

#include "polynomial.h" 

#include <format> 

#include <cmath> 





// ADD implementation of the member functions for class Logarithm 

std::string Logarithm::toString() {

	//hur man kallar på den:  std::string{l0};  



	std::string S = std::format("{:.2f} + {:.2f} * log_{}({})", c1, c2, b, (*E).toString());//dereference E eftersom E är en pointer 

}



//Få ett y-värde genom att skicka in ett värde på x  

double Logarithm::operator()(double d) const {

	//man skickar in ett värde "d" för x i this som är ett polynom 

	int returnValue = 0;



	returnValue += c1 + c2 * (log((*E).operator()(d)) / log(b));

	return returnValue;

}





//default contructor 

Logarithm::Logarithm() : c1{ 0.0 }, c2{ 0.0 }, b{ 2 }, E{ new Polynomial{{0,1}} } {

	// samma sak som Logarithm(0, 0, 2, new Polynomial{ {0,1} }); 



}



Logarithm::Logarithm(double arg1, double arg2, int arg3, const Expression& arg4) {

	c1 = arg1;

	c2 = arg2;

	//man kan inte skriva E = E eftersom vi inte har försett expression med en operator=  

	E = arg4.clone(); //skapar en ny logarithm  



	if (arg3 > 1) {

		b = arg3;

	}

	else {

		b = 2;

	}

}



//copy constructor 

Logarithm::Logarithm(const Logarithm& L) {

	c1 = L.c1;

	c2 = L.c2;

	b = L.b;

	E = (*L.E).clone(); //dereference 

}



//assignment opperator 

Logarithm& Logarithm::operator=(const Logarithm& rhs) {

	c1 = rhs.c1;

	c2 = rhs.c2;

	b = rhs.b;

	E = (*rhs.E).clone();

}



//set_base modifies the base b  

Logarithm& Logarithm::set_base(int b1) {

	if (b > 1) {

		b = b1;

	}

	else {

		b = 2;

	}



}



//clone virtual 

Logarithm* Logarithm::clone() const {

	return new Logarithm{ *this }; //returns pointer till det nya objektet. man kallar på den med en pointer också. :)  

}