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

    //E.display(os); //os �r v�r output stream. << betyder att vi skriver till v�r iytput stream  

    os << E.toString();



    return os;



    //f�r att skriva ut i konsollen s� kallar man p� den std::cout << S 

}



bool Expression::isRoot(double x) const {

    //Man ska kolla om x �r en reell rot till en function y = f(x) .  

    //y=f(x)=0 



    double Epsilon = 10 ^ (-6); //mycket litet tal, typ 0 

    if (abs(operator()(x)) <= Epsilon) { //vi anv�nder en egen funktion som r�knar ut y v�rde av ett x-v�rde  

        return true;

    }

    return false;

}



//Expression* Expression::clone() const { 

//    return new Expression{ *this }; 

//} 