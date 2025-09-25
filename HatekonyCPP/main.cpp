#include <iostream>
#include <exception>

#include "Fraction.h"

int main()
{
    try
    {
        Fraction f1 = Fraction(69);
        Fraction f2 = Fraction(-7, 24);
        std::cout << f1.GetFraction() << std::endl;
    }
    catch (std::invalid_argument a) {
        std::cout << a.what() << std::endl;
    }
}