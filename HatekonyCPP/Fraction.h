#pragma once
class Fraction
{
public:
	Fraction(const unsigned& denominator);
	Fraction(const int& numerator, const unsigned& denominator);
	//Fraction(const float& decimalFraction);
	//Fraction(const Fraction& fraction);
	float GetFraction();

private:
	int _numerator;
	unsigned int _denominator;
	void Simplify();
};

