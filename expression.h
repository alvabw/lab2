/*************************

* Class Expression       *

* TNG033: Lab 2          *

**************************/



#pragma once 



#include <iostream> 

#include <vector> 

#include <sstream> 

constexpr double Epsilon = 1.0e-5;



class Expression {

public:

    // Destructor 

    virtual ~Expression() {

        --count_expressions;

    }



    // ADD OTHER MEMBER FUNCTIONS 

    bool isRoot(double x) const;

    //convert an expression to a string, explicit not allow implicit conversions 

    virtual std::string toString() = 0;

    //virtual std::string() toString() const = 0; 



    //an overloaded function call operstor() to evaulate expression e at x 

    virtual double operator()(double d) const = 0;





    friend std::ostream& operator<<(std::ostream& os, Expression& E);



    //function returns a pointer to a copy of the expression 

    virtual Expression* clone() const = 0;





    // Return number of existing instances of class Expression 

    // Used only for debug purposes 

    static std::size_t get_count_expressions();



protected:

    // Default constructor 

    Expression() {

        ++count_expressions;

    }



    // Copy constructor 

    Expression(const Expression&) {

        ++count_expressions;

    }



    // total number of existing expressions -- only to help to detect bugs in the code 

    static std::size_t count_expressions;



    //virtual void display(std::ostream& os = std::cout) const = 0;  

};

