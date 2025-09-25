#include <stdexcept>


#include "Fraction.h"


Fraction::Fraction(const unsigned& denominator)	//nevezõs konstruktor
	:_denominator(denominator)
	, _numerator(1)
{

	if (denominator == 0) {
		throw std::invalid_argument("Denominator was zero!");
	}

}


Fraction::Fraction(const int& numerator, const unsigned& denominator)	//számlálós, nevezõs konstruktor
	:_denominator(denominator)
	, _numerator(numerator)
{

	if (denominator == 0) {
		throw std::invalid_argument("Denominator was zero!");
	}
	Simplify();

}


//Fraction::Fraction(const float& decimalFraction)
//{
//
//}
//Fraction::Fraction(const Fraction& fraction)
//{
//
//}

void Fraction::Simplify() // TODO: nem jó, nem mûködik negatív számokkal
{
	if (_numerator < _denominator)
	{
		if (_denominator % _numerator == 0)
		{
			_numerator /= _numerator;
			_denominator /= _numerator;
		}
		for (auto i = _numerator / 2; i > 0; i--)
		{
			if (_numerator % i == 0 && _denominator % i == 0)
			{
				_numerator /= i;
				_denominator /= i;
			}
		}
	}
	else
	{
		if (_numerator % _denominator == 0)
		{
			_numerator /= _denominator;
			_denominator /= _denominator;
		}
		for (auto i = _denominator / 2; i > 0; i--)
		{
			if (_denominator % i == 0 && _numerator % i == 0)
			{
				_numerator /= i;
				_denominator /= i;
			}
		}
	}
}