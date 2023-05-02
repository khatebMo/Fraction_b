#ifndef FRACTION
#define FRACTION
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Fraction.hpp"

using namespace std;

namespace ariel
{
    Fraction::Fraction()
    {
    }
    Fraction::Fraction(int numerator, int denominator)
    {
    }
    Fraction::Fraction(float n) {}
    int Fraction::gcd()
    {
        int max;
        int gcd;
        int a = this->getDenominator();
        int b = this->getNumerator();
        if (a == 0)
        {
            return b;
        }
        if (b == 0)
        {
            return a;
        }
        if (a >= b)
        {
            max = a;
        }
        else
        {
            max = b;
        }
        for (int i = max; i > 0; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                gcd = i;
                break;
            }
        }

        return gcd;
    }
    void Fraction::redues()
    {
        int gcd = this->gcd();
        this->setDenominator(this->getDenominator() / gcd);
        this->setNumerator(this->getNumerator() / gcd);
    }
    int Fraction::getDenominator()
    {
        return this->denominator;
    }
    int Fraction::getNumerator()
    {
        return this->numerator;
    }
    void Fraction::setDenominator(int number)
    {
        this->denominator = number;
    }
    void Fraction::setNumerator(int number)
    {
        this->numerator = number;
    }
    Fraction Fraction::operator+(const Fraction &other) const
    {
        int newNum = this->numerator * other.denominator + this->denominator * other.numerator;
        int newDen = this->denominator * other.denominator;
        Fraction fraction(newNum, newDen);
        fraction.redues();
        return fraction;
    }
    Fraction Fraction::operator-(const Fraction &other) const
    {
        int newNum = this->numerator * other.denominator - this->denominator * other.numerator;
        int newDen = this->denominator * other.denominator;
        Fraction fraction(newNum, newDen);
        fraction.redues();
        return fraction;
    }
    Fraction Fraction::operator*(const Fraction &other) const { return other; }
    Fraction Fraction::operator/(const Fraction &other) const { return other; }
    bool Fraction::operator==(const Fraction &other) const { return true; }
    bool Fraction::operator<=(const Fraction &other) const { return true; }
    bool Fraction::operator>=(const Fraction &other) const { return true; }
    bool Fraction::operator>(const Fraction &other) const { return true; }
    Fraction Fraction::operator++(int n) { return *this; }
    Fraction &Fraction::operator++() { return *this; }
    Fraction Fraction::operator--(int n) { return *this; }
    Fraction &Fraction::operator--() { return *this; }

    Fraction operator+(float frac, Fraction &other) { return other; }
    Fraction operator-(float frac, Fraction &other) { return other; }
    Fraction operator*(float frac, Fraction &other) { return other; }
    Fraction operator/(float frac, Fraction &other) { return other; }
    ostream &operator<<(ostream &os, const Fraction &) { return os; }
    istream &operator>>(istream &in, const Fraction &) { return in; }
}
#endif