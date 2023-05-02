#ifndef Fraction
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace ariel
{

    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        // const
        Fraction();
        Fraction(int num, int deno);
        Fraction(float);

        // getters
        int getNumerator();
        int getDenominator();

        // help function
        int gcd();
        void redues();
        Fraction convert(float number);

        // setters
        void setNumerator(int number);
        void setDenominator(int number);

        // Overloaded operators
        Fraction operator+(const Fraction &other) const;
        friend Fraction operator+(const float& number,const Fraction &other);
        friend Fraction operator+(const Fraction &other, const float& number);

        friend Fraction operator-(const float& number, const Fraction &other);
        friend Fraction operator-(const Fraction &other, const float& number);
        Fraction operator-( const Fraction &other) const;

        friend Fraction operator*(const float& number, const Fraction &other);
        friend Fraction operator*(const Fraction &other, const float& number);
        Fraction operator*(const Fraction &other) const;

        friend Fraction operator/(const float& number, const Fraction &other);
        friend Fraction operator/(const Fraction &other, const float& number);
        Fraction operator/(const Fraction &other) const;

        bool operator==(const Fraction &other) const;
        friend bool operator==(const float& number, const Fraction &other);
        friend bool operator==(const Fraction &other, const float& number);

        bool operator<(const Fraction &other) const;
        friend bool operator<(const float& number, const Fraction &other);
        friend bool operator<(const Fraction &other, const float& number);

        bool operator<=(const Fraction &other) const;
        friend bool operator<=(const float& number, const Fraction &other);
        friend bool operator<=(const Fraction &other, const float& number);

        bool operator>(const Fraction &other) const;
        friend bool operator>(const float& number, const Fraction &other);
        friend bool operator>(const Fraction &other, const float& number);

        bool operator>=(const Fraction &other) const;
        friend bool operator>=(const float& number, const Fraction &other);
        friend bool operator>=(const Fraction &other, const float& number);

        friend bool checkOverflow(const Fraction &fraction1, const Fraction &fraction2, char sign);


        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);
        friend ostream &operator<<(ostream &os, const Fraction& other);
        friend istream &operator>>(istream &is,  Fraction &other);
    };

}
#endif