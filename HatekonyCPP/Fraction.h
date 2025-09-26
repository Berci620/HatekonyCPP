#pragma once
class Fraction
{
public:
	Fraction(int denominator);
	Fraction(int numerator, int denominator);
	Fraction(const double& decimalFraction);
	Fraction(const Fraction& fraction);
	float GetFraction();

private:
	int _numerator;
	int _denominator;
	int GCD(int a, int b);
	void Simplify();
	void FractionFromFloat(double decimalFraction);
};

