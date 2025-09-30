#pragma once

#include <string>

class Fraction
{
public:
	Fraction(int denominator);
	Fraction(int numerator, int denominator);
	Fraction(const double& decimalFraction);
	Fraction(const Fraction& fraction) = default;

	friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
	friend std::istream& operator>>(std::istream& is, Fraction& fraction);
	
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction operator+(const Fraction& other) const;
	Fraction& operator-=(const Fraction& other);
	Fraction operator-(const Fraction& other) const;
	Fraction& operator*=(const Fraction& other);
	Fraction operator*(const Fraction& other) const;
	Fraction& operator/=(const Fraction& other);
	Fraction operator/(const Fraction& other) const;

	bool operator==(const Fraction& other) const;
	bool operator!=(const Fraction& other) const;
	bool operator>(const Fraction& other) const;
	bool operator>=(const Fraction& other) const;
	bool operator<(const Fraction& other) const;
	bool operator<=(const Fraction& other) const;

	operator int() const;
	operator float() const;
	operator bool() const;
	operator std::string() const;

private:
	int _numerator;
	int _denominator;
	void Simplify();
	void FractionFromFloat(double decimalFraction);
};

Fraction Parse(const std::string& value);