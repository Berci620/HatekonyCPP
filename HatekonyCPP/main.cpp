#include <iostream>
#include <exception>

#include "Fraction.h"

int main()
{
    try
    {
        
    }
    catch (std::invalid_argument a) {
        std::cout << a.what() << std::endl;
    }
}