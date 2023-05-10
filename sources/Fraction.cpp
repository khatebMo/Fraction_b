#define FRACTION
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdexcept>
#include "Fraction.hpp"
#include <cmath>
#include <limits>
#include <algorithm>

namespace ariel
{
    Fraction::Fraction()
    {
        this->setDenominator(1);
        this->setNumerator(0);
    }
    Fraction::Fraction(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw std::invalid_argument("Divide by zero! , The dennominator can't be 0!");
        }
        int nu = numerator;
        int de = denominator;
        if (de < 0)
        {
            nu *= -1;
            de *= -1;
        }

        this->numerator = nu;
        this->denominator = de;
        redues();
    }
    Fraction::Fraction(float n)
    {
        Fraction temp = convertToFraction(n);
        this->setDenominator(temp.getDenominator());
        this->setNumerator(temp.getNumerator());
        redues();
    }
    float convertToFloat(Fraction temp)
    {
        float number = temp.numerator / temp.denominator;
        number = (std::round(number * 1000)) / 1000;
        return number;
    }

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
        int gcd = std::__gcd(numerator, denominator);
        this->setDenominator(this->getDenominator() / gcd);
        this->setNumerator(this->getNumerator() / gcd);
        if (this->denominator < 0)
        {
            denominator *= -1;
            numerator *= -1;
        }
    }
    Fraction Fraction::convertToFraction(float number)
    {
        int num = roundf(number * 1000);

        int deno = 1000;
        Fraction franc(num, deno);
        return franc;
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
        if (checkOverflow(numerator, other.denominator, '*') || checkOverflow(other.numerator, denominator, '*') 
        || checkOverflow((numerator * other.denominator), (other.numerator * denominator), '+')) // if (checkOverflow(*this, other, '+'))
        {
            throw overflow_error("OVERFLOW!!");
        }
        int newNum = this->numerator * other.denominator + this->denominator * other.numerator;
        int newDen = this->denominator * other.denominator;

        Fraction fraction(newNum, newDen);
        return fraction;
    }
    Fraction operator+(const float &number, const Fraction &other)
    {
        Fraction temp(number);
        return temp + other;
    }
    Fraction operator+(const Fraction &other, const float &number)
    {
        Fraction temp(number);
        return temp + other;
    }

    Fraction operator-(const Fraction &other, const float &number)
    {
        Fraction temp(number);
        return other - temp;
    }
    Fraction operator-(const float &number, const Fraction &other)
    {
        Fraction temp(number);
        return temp - other;
    }
    Fraction Fraction::operator-(const Fraction &other) const
    {
        if (checkOverflow(numerator, other.denominator, '*') || checkOverflow(other.numerator, denominator, '*') 
        || checkOverflow(numerator * other.denominator, other.numerator * denominator, '-')) // if (checkOverflow(*this, other, '-'))
        {
            throw overflow_error("OVERFLOW!!");
        }
        int newNum = this->numerator * other.denominator - this->denominator * other.numerator;
        int newDen = this->denominator * other.denominator;

        Fraction fraction(newNum, newDen);
        return fraction;
    }

    Fraction operator*(const float &number, const Fraction &other)
    {
        Fraction temp(number);
        return temp * other;
    }
    Fraction operator*(const Fraction &other, const float &number)
    {
        Fraction temp(number);
        return other * temp;
    }
    Fraction Fraction::operator*(const Fraction &other) const
    {
        if (checkOverflow(numerator, other.numerator, '*') || checkOverflow(denominator, other.denominator, '*')) // if (checkOverflow(*this, other, '*'))
        {
            throw overflow_error("OVERFLOW!!");
        }
        int newNum = this->numerator * other.numerator;
        int newDen = this->denominator * other.denominator;

        Fraction fraction(newNum, newDen);
        return fraction;
    }

    Fraction operator/(const float &number, const Fraction &other)
    {
        Fraction temp(number);
        return temp / other;
    }
    Fraction operator/(const Fraction &other, const float &number)
    {
        Fraction temp(number);
        return other / temp;
    }
    Fraction Fraction::operator/(const Fraction &other) const
    {

        if (other.numerator == 0)
        {
            throw std::runtime_error("can't divide by zero");
        }
        if (checkOverflow(numerator, other.denominator, '*') || checkOverflow(denominator, other.numerator, '*')) // if (checkOverflow(*this, other, '/'))
        {
            throw overflow_error("OVERFLOW!!");
        }
        int newNum = this->numerator * other.denominator;
        int newDen = this->denominator * other.numerator;

        Fraction fraction(newNum, newDen);
        return fraction;
    }

    bool operator==(const float &number, const Fraction &other)
    {
        Fraction temp(number);
        return other == temp;
    }
    bool operator==(const Fraction &other, const float &number)
    {
        Fraction temp(number);
        return other == temp;
    }
    bool Fraction::operator==(const Fraction &other) const
    {
        if (this->numerator * other.denominator == other.numerator * this->denominator)
        {
            return true;
        }
        return false;
    }

    bool operator<=(const float &number, const Fraction &other)
    {
        Fraction temp(number);
        return temp <= other;
    }
    bool operator<=(const Fraction &other, const float &number)
    {
        Fraction temp(number);
        return other <= temp;
    }
    bool Fraction::operator<=(const Fraction &other) const
    {
        int first = this->numerator * other.denominator;
        int second = this->denominator * other.numerator;
        if (this->numerator * other.denominator == this->denominator * other.numerator ||
            first < second)
        {
            return true;
        }
        return false;
    }

    bool operator>=(const float &number, const Fraction &other)
    {
        Fraction temp(number);
        return temp >= other;
    }
    bool operator>=(const Fraction &other, const float &number)
    {
        Fraction temp(number);
        return other >= temp;
    }
    bool Fraction::operator>=(const Fraction &other) const
    {
        int first = this->numerator * other.denominator;
        int second = this->denominator * other.numerator;
        if (this->numerator * other.denominator == this->denominator * other.numerator ||
            second < first)
        {
            return true;
        }
        return false;
    }

    bool operator>(const float &number, const Fraction &other)
    {
        Fraction temp(number);
        return temp > other;
    }
    bool operator>(const Fraction &other, const float &number)
    {
        Fraction temp(number);
        return other > temp;
    }
    bool Fraction::operator>(const Fraction &other) const
    {
        int first = this->numerator * other.denominator;
        int second = this->denominator * other.numerator;
        if (first > second)
        {
            return true;
        }
        return false;
    }

    bool operator<(const float &number, const Fraction &other)
    {
        Fraction temp(number);
        return temp < other;
    }
    bool operator<(const Fraction &other, const float &number)
    {
        Fraction temp(number);
        return other < temp;
    }
    bool Fraction::operator<(const Fraction &other) const
    {
        int first = this->numerator * other.denominator;
        int second = this->denominator * other.numerator;
        if (first < second)
        {
            return true;
        }
        return false;
    }

    Fraction Fraction::operator++(int)
    {
        Fraction franc(*this);
        numerator += denominator;
        return franc;
    }
    Fraction Fraction::operator++()
    {
        this->setNumerator(this->numerator + this->denominator);
        return *this;
    }
    Fraction Fraction::operator--(int)
    {
        Fraction franc(*this);
        numerator -= denominator;
        return franc;
    }
    Fraction Fraction::operator--()
    {
        this->setNumerator(this->numerator - this->denominator);
        return *this;
    }
    ostream &operator<<(ostream &os, const Fraction &other)
    {
        os << other.numerator << "/" << other.denominator;
        return os;
    }

    istream &operator>>(istream &input, Fraction &other)
    {
        int num, den;
        input >> num >> den;
        if (input.fail())
        {
            throw runtime_error("Error Detected - There is one input");
        }
        if (den == 0)
        {
            throw runtime_error("Error Detected - Denominator can't be zero");
        }
        other = Fraction(num, den);
        return input;
    }


    bool Fraction::checkOverflow(int a, int b, char op) const
    {
        int maxInt = std::numeric_limits<int>::max();
        int minInt = std::numeric_limits<int>::min();
        if (op == '+')
        {
            if (a > 0 && b > 0 && (a + b) < 0)
            {
                return true;
            }
            if (a < 0 && b < 0 && (a + b) > 0)
            {
                return true;
            }
        }
        else if (op == '-')
        {
            if (a > 0 && b < 0 && (a - b) < 0)
            {
                return true;
            }
            if (a < 0 && b > 0 && (a - b) > 0)
            {
                return true;
            }
        }
        else if (op == '*')
        {
            if(a == 0 || b ==0) return false;
            int c = a * b;
            if (c / a != b)
                return true;
        }
        return false;
    }

}