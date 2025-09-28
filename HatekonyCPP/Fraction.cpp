#include <stdexcept>
#include <cmath>
#include <iostream>

#include "Fraction.h"

//Constructors
//---------------------------------------------------------------------

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
	if (denominator < 0)
	{
		_denominator *= -1; _numerator *= -1;
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

//Output
//---------------------------------------------------------------------

float Fraction::GetFraction()
{
	float result = static_cast<float>(_numerator) / _denominator;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
	os << fraction._numerator << "/" << fraction._denominator << std::endl;
	return os;
}

//Basic arithmetic operations
//---------------------------------------------------------------------

Fraction& Fraction::operator=(const Fraction& other) = default;

Fraction& Fraction::operator+=(const Fraction& other)
{
	int lcm = LCM(_denominator, other._denominator);
	int aMult = lcm / _denominator;
	int bMult = lcm / other._denominator;

	_numerator *= aMult; _denominator *= aMult;

	_numerator += (other._numerator * bMult);

	this->Simplify();

	return *this;
}

Fraction Fraction::operator+(const Fraction& other) const
{
	Fraction result(*this);
	result += other;
	return result;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	int lcm = LCM(_denominator, other._denominator);
	int aMult = lcm / _denominator;
	int bMult = lcm / other._denominator;

	_numerator *= aMult; _denominator *= aMult;

	_numerator -= (other._numerator * bMult);

	this->Simplify();

	return *this;
}

Fraction Fraction::operator-(const Fraction& other) const
{
	Fraction result(*this);
	result -= other;
	return result;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	_numerator *= other._numerator;
	_denominator *= other._denominator;
	this->Simplify();
	return *this;
}

Fraction Fraction::operator*(const Fraction& other) const
{
	Fraction result(*this);
	result *= other;
	return result;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	_numerator *= other._denominator;
	_denominator *= other._numerator;

	if (_denominator == 0)
	{
		throw std::invalid_argument("Cannot divide with zero!");
	}
	if (_denominator < 0)
	{
		_denominator *= -1; _numerator *= -1;
	}

	this->Simplify();

	return *this;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	Fraction result(*this);
	result /= other;
	return result;
}

//Comparisons
//---------------------------------------------------------------------

bool Fraction::operator==(const Fraction& other) const
{
	return (_numerator == other._numerator && _denominator == other._denominator);
}

bool Fraction::operator!=(const Fraction& other) const
{
	return !(*this == other);
}

bool Fraction::operator>(const Fraction& other) const
{
	if (static_cast<double>(_numerator) / _denominator > static_cast<double>(other._numerator) / other._denominator) {
		return true;
	}
	return false;
}

bool Fraction::operator>=(const Fraction& other) const 
{
	return (*this == other || *this > other);
}

bool Fraction::operator<(const Fraction& other) const
{
	if (static_cast<double>(_numerator) / _denominator < static_cast<double>(other._numerator) / other._denominator) {
		return true;
	}
	return false;
}

bool Fraction::operator<=(const Fraction& other) const
{
	return (*this < other || *this == other);
}

//Others
//---------------------------------------------------------------------

int Fraction::GCD(int a, int b)		// Greatest Common Divisor
{
	int gcd = std::min(std::abs(a), std::abs(b));

	if (gcd == 0) { return 1; } // Handling exception->(if any is 0, it would divide with 0)

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

int Fraction::LCM(int a, int b)		// Least Common Multiple
{
	int result = (a * b) / GCD(a, b);
	return result;
}

void Fraction::Simplify()	//	Divide fractions numerator and denominator to get the most simple form
{
	int gcd = GCD(_numerator, _denominator);
	_denominator /= gcd;
	_numerator /= gcd;
}

void Fraction::FractionFromFloat(double decimalFraction)	// Helps the double constructor
{
	int n = 0, gcd;
	double delt = 0.0001;

	while (std::abs(decimalFraction - static_cast<int>(std::round(decimalFraction))) > delt)
	{
		decimalFraction *= 10;
		n++;
	}

	decimalFraction = std::round(decimalFraction);

	_numerator = decimalFraction;
	_denominator = pow(10, n);

	gcd = std::abs(GCD(_numerator, _denominator)); //std::abs because we store -/+ in _numerator

	_numerator /= gcd;
	_denominator /= gcd;
}