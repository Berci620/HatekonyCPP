#pragma once
class Fraction
{
public:
	Fraction(const int& denominator);
	Fraction(const int& numerator, const int& denominator);
	//Fraction(const float& decimalFraction);
	Fraction(const Fraction& fraction);
	float GetFraction();

private:
	int _numerator;
	int _denominator;
	void Simplify();
};

