#include <stdexcept>
#include <cmath>

#include "Fraction.h"


Fraction::Fraction(int denominator)	//_denominator constructor
	:_denominator(denominator)
	, _numerator(1)
{

	if (denominator == 0) {
		throw std::invalid_argument("Denominator was zero!");
	}

}

Fraction::Fraction(int numerator, int denominator)	//_numerator, _denominator constructor
	:_denominator(denominator)
	, _numerator(numerator)
{

	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator was zero!");
	}
	Simplify();

}

Fraction::Fraction(const double& decimalFraction)
{
	FractionFromFloat(decimalFraction);
	;
}

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


int Fraction::GCD(int a, int b)
{
	int gcd = std::min(a, b);

	if (a % gcd == 0 && b % gcd == 0)
	{
		return gcd;
	}
	else
	{
		gcd /= 2;
	}

	while (gcd > 1)
	{
		if (a % gcd == 0 && b % gcd == 0)
		{
			return gcd;
		}
		gcd--;
	}
	return gcd;
}

void Fraction::Simplify()
{
	int gcd = GCD(_numerator, _denominator);
	_denominator /= gcd;
	_numerator /= gcd;
}

void Fraction::FractionFromFloat(double decimalFraction)
{
	int n = 0, gcd;
	//int numerator, denominator;

	while (decimalFraction != static_cast<int>(decimalFraction))
	{
		decimalFraction *= 10;
		n++;
	}

	_numerator = decimalFraction;
	_denominator = pow(10, n);

	gcd = GCD(_numerator, _denominator);

	_numerator /= gcd;
	_denominator /= gcd;
}