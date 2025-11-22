#include "common_fractions.h"
#include "fraction_exception.h" 
#include <iostream>
#include <numeric>
using namespace std;

Common_fractions :: Common_fractions() : numerator(0), denominator(1) {}
Common_fractions :: Common_fractions(int n, int d) : numerator(n), denominator(d) 
{
    if (denominator == 0) 
    {
        throw FractionException("Denominator cannot be zero.");
    }
    reduce();
}

int Common_fractions :: getNumerator() const
{
    return numerator;
}

int Common_fractions :: getDenominator() const
{
    return denominator;
}

void Common_fractions :: setNumerator(int n)
{
    cout << "Введите числитель" << endl;
    cin >> n;
    numerator = n;
}

void Common_fractions :: setDenominator(int d)
{
    cout << "Введите знаменатель" << endl;
    cin >> d;
    denominator = d;
}

void Common_fractions :: reduce()
{
    int nod = gcd(numerator,denominator);
    numerator /= nod;
    denominator /= nod;
    if(denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Common_fractions Common_fractions :: operator+ (Common_fractions& other) const
{
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Common_fractions(num, denom);
}

Common_fractions Common_fractions :: operator- (Common_fractions& other) const
{
    int num = numerator * other.denominator - other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Common_fractions(num, denom);
}

Common_fractions Common_fractions :: operator- () const 
{
    return Common_fractions(-numerator, denominator);
}

Common_fractions Common_fractions :: operator* (Common_fractions& other) const
{
    int num = numerator * other.numerator;
    int denom = denominator * other.denominator;
    return Common_fractions(num, denom);
}

Common_fractions Common_fractions :: operator/ (Common_fractions& other) const
{
    if (other.numerator == 0)
    {
        throw FractionException("Division by zero fraction.");
    }
    int num = numerator * other.denominator;
    int denom = denominator * other.numerator;
    return Common_fractions(num, denom);
}

bool Common_fractions :: operator== (Common_fractions& other) const
{
    if(numerator * other.denominator == other.numerator * denominator)
    {
        return true;
    }
    return false;
}

bool Common_fractions :: operator!= (Common_fractions& other) const
{
    if(numerator * other.denominator != other.numerator * denominator)
    {
        return true;
    }
    return false;
}

bool Common_fractions :: operator> (Common_fractions& other) const
{
    if(numerator * other.denominator > other.numerator * denominator)
    {
        return true;
    }
    return false;
}

bool Common_fractions :: operator< (Common_fractions& other) const
{
    if(numerator * other.denominator < other.numerator * denominator)
    {
        return true;
    }
    return false;
}

Common_fractions Common_fractions :: operator! () const
{
    return Common_fractions(denominator, numerator);
}

Common_fractions Common_fractions :: operator= (Common_fractions& other)
{
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

Common_fractions& Common_fractions :: operator++ ()
{
    this -> numerator += this -> denominator;
    this->reduce();
    return *this;
}

Common_fractions Common_fractions :: operator++ (int)
{
    Common_fractions temp = *this;
    ++(*this);
    return temp;
}

Common_fractions& Common_fractions :: operator-- ()
{
    this -> numerator -= this -> denominator;
    return *this;
}

Common_fractions Common_fractions :: operator-- (int)
{
    Common_fractions temp = *this;
    --(*this);
    return temp;
}


void Common_fractions :: print() const
{
    cout << numerator << "/" << denominator << endl;
}

void Common_fractions :: to_Float() const
{
    double drob = (double)numerator / denominator;
    cout << drob << endl;
}
