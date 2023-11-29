/*********************************************************

* Class Expression member functions implementation       *

* TNG033: Lab 2                                          *

**********************************************************/



#include "expression.h" 

#include <vector> 

// Initialize the counter of the total number of existing Expressions 

std::size_t Expression::count_expressions = 0;



// Used only for debug purposes 

// Return number of existing Expressions 

std::size_t Expression::get_count_expressions() {

    return Expression::count_expressions;

}





/* ************************* */

std::ostream& operator<<(std::ostream& os, Expression& E) {

    //E.display(os); //os är vår output stream. << betyder att vi skriver till vår iytput stream  

    os << E.toString();



    return os;



    //för att skriva ut i konsollen så kallar man på den std::cout << S 

}



bool Expression::isRoot(double x) const {

    //Man ska kolla om x är en reell rot till en function y = f(x) .  

    //y=f(x)=0 



    double Epsilon = 10 ^ (-6); //mycket litet tal, typ 0 

    if (abs(operator()(x)) <= Epsilon) { //vi använder en egen funktion som räknar ut y värde av ett x-värde  

        return true;

    }

    return false;

}



//Expression* Expression::clone() const { 

//    return new Expression{ *this }; 

//} 