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

        //help function
        int gcd();
        void redues();


        // setters
        void setNumerator(int number);
        void setDenominator(int number);


        // Overloaded operators
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;
        bool operator==(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;
        bool operator>(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;
        Fraction &operator++();
        Fraction operator++(int);
        Fraction &operator--();
        Fraction operator--(int);
        friend Fraction operator+(float frac, Fraction &other);
        friend Fraction operator-(float frac, Fraction &other);
        friend Fraction operator*(float frac, Fraction &other);
        friend Fraction operator/(float frac, Fraction &other);
        friend ostream &operator<<(ostream &os, const Fraction &other);
        friend istream &operator>>(istream &is, const Fraction &other);
    };

}
#endif