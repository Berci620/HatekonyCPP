#include <stdexcept>
#include <cmath>

#include "Fraction.h"


Fraction::Fraction(const int& denominator)	//_denominator constructor
	:_denominator(denominator)
	, _numerator(1)
{

	if (denominator == 0) {
		throw std::invalid_argument("Denominator was zero!");
	}

}


Fraction::Fraction(const int& numerator, const int& denominator)	//_numerator, _denominator constructor
	:_denominator(denominator)
	, _numerator(numerator)
{

	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator was zero!");
	}
	Simplify();

}


//Fraction::Fraction(const float& decimalFraction)
//{
//
//}
Fraction::Fraction(const Fraction& fraction)
{
	_numerator = fraction._numerator;
	_denominator = fraction._denominator;
}

float Fraction::GetFraction() 
{
	float result = static_cast<float>(_numerator) / _denominator;
	return result;
}

void Fraction::Simplify()
{
	int numeratorAbs = std::abs(_numerator); //absolute value helper
	if (numeratorAbs < _denominator)
	{
		if (_denominator % _numerator == 0) //if _numerator is the greatest common divisor divide and return
		{
			_denominator /= numeratorAbs;
			_numerator /= numeratorAbs;
			return;
		}
		for (auto i = numeratorAbs / 2; i > 0; i--) //search for the greatest common divisor
		{
			if (_numerator % i == 0 && _denominator % i == 0)
			{
				_numerator /= i;
				_denominator /= i;
				return;
			}
		}
	}
	else
	{
		if (_numerator % _denominator == 0) //if _denominator is the greatest common divisor divide and return
		{
			_numerator /= _denominator;
			_denominator /= _denominator;
			return;
		}
		for (auto i = _denominator / 2; i > 0; i--) //search for the greatest common divisor
		{
			if (_denominator % i == 0 && _numerator % i == 0)
			{
				_numerator /= i;
				_denominator /= i;
				return;
			}
		}
	}
}