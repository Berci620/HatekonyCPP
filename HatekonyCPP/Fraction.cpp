#include <stdexcept>
#include <cmath>
#include <iostream>
#include <numeric>

#include "Fraction.h"

//Static
//---------------------------------------------------------------------

Fraction Fraction::Parse(const std::string& value)
{
	int numerator = 0;
	int denominator = 0;
	int i = 0;
	int idx;
	bool is_negative = false;
	const auto pos = value.find('/');

	if (pos != value.npos)	// value.find('/') gives value.npos as result, if no character was found
	{
		if (value[i] == '-') { is_negative = true; i++; }

		idx = static_cast<int>(pos);
		while (i < idx)
		{
			numerator *= 10;
			numerator += (static_cast<int>(value[i]) - 48);
			i++;
		}
		i++;
		while (i < value.size())
		{
			denominator *= 10;
			denominator += (static_cast<int>(value[i]) - 48);
			i++;
		}

		if (is_negative) { numerator *= -1; }

		return Fraction(numerator, denominator);
	}

	throw std::invalid_argument("The input format was not correct! (numerator/denominator)");
}

// Constructors
//---------------------------------------------------------------------

Fraction::Fraction(const int numerator)	//_denominator constructor
	:_denominator(1)
	, _numerator(numerator)
{
}

Fraction::Fraction(const int numerator, const int denominator)	//_numerator, _denominator constructor
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

Fraction::Fraction(const double decimalFraction)
{
	FractionFromDouble(decimalFraction);
}

// I/O
//---------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
	os << static_cast<std::string>(fraction) << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction)
{
	std::string input;
	getline(is, input);
	input.erase(remove(input.begin(), input.end(), ' '), input.end());
	fraction = Fraction::Parse(input);
	return is;
}

// Basic arithmetic operations
//---------------------------------------------------------------------

Fraction& Fraction::operator+=(const Fraction& other)
{
	const int lcm = std::lcm(_denominator, other._denominator);
	const int aMult = lcm / _denominator;
	const int bMult = lcm / other._denominator;

	_numerator *= aMult;
	_denominator *= aMult;

	_numerator += (other._numerator * bMult);

	Simplify();

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
	const int lcm = std::lcm(_denominator, other._denominator);
	const int aMult = lcm / _denominator;
	const int bMult = lcm / other._denominator;

	_numerator *= aMult; _denominator *= aMult;

	_numerator -= (other._numerator * bMult);

	Simplify();

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
	Simplify();
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

	Simplify();

	return *this;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	Fraction result(*this);
	result /= other;
	return result;
}

// Comparisons
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
	if (!(*this >= other)) {
		return true;
	}
	return false;
}

bool Fraction::operator<=(const Fraction& other) const
{
	return (*this < other || *this == other);
}

// Converting
//---------------------------------------------------------------------

Fraction::operator int() const
{
	return static_cast<int>(std::round(static_cast<double>(_numerator) / _denominator));
}

Fraction::operator float() const
{
	return static_cast<float>(_numerator) / _denominator;
}

Fraction::operator bool() const
{
	return !(static_cast<int>(*this) == 0);
}

Fraction::operator std::string() const
{
	return std::to_string(_numerator) + "/" + std::to_string(_denominator);
}

// Others
//---------------------------------------------------------------------

void Fraction::Simplify()	//	Divide fractions numerator and denominator to get the most simple form
{
	const int gcd = std::gcd(_numerator, _denominator);
	_denominator /= gcd;
	_numerator /= gcd;
}

void Fraction::FractionFromDouble(double decimalFraction)	// Helps the double constructor   // const double decimalFraction
{
	int n = 0;
	int gcd;
	const double delt = 0.0001;

	while (std::abs(decimalFraction - std::round(decimalFraction)) > delt)
	{
		decimalFraction *= 10;
		n++;
	}

	_numerator = std::round(decimalFraction);
	_denominator = pow(10, n);

	gcd = std::gcd(_numerator, _denominator);

	_numerator /= gcd;
	_denominator /= gcd;
}
