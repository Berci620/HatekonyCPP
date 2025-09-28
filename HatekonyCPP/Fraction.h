#pragma once
class Fraction
{
public:
	Fraction(int denominator);
	Fraction(int numerator, int denominator);
	Fraction(const double& decimalFraction);
	Fraction(const Fraction& fraction);
	float GetFraction();

	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction operator+(const Fraction& other) const;
	Fraction& operator-=(const Fraction& other);
	Fraction operator-(const Fraction& other) const;
	Fraction& operator*=(const Fraction& other);
	Fraction operator*(const Fraction& other) const;

private:
	int _numerator;
	int _denominator;
	int GCD(int a, int b);
	int LCM(int a, int b);
	void Simplify();
	void FractionFromFloat(double decimalFraction);
};

