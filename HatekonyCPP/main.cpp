#include <iostream>
#include <exception>

#include "Fraction.h"

int main()
{
    try
    {
        Fraction f1 = Fraction(static_cast<unsigned>(1));
        Fraction f2 = Fraction(2, 8);
        std::cout << 
    }
    catch (std::invalid_argument a) {
        std::cout << a.what() << std::endl;
    }
}