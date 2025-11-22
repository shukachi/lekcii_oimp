
#ifndef COMMON_FRACTIONS_H
#define COMMON_FRACTIONS_H

class Common_fractions
{
    private:
    int numerator, denominator;
    void reduce();

    public:
    Common_fractions();
    Common_fractions(int n, int d);

    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(int n);
    void setDenominator(int d);

    Common_fractions operator+ (Common_fractions& other) const;
    Common_fractions operator- (Common_fractions& other) const;
    Common_fractions operator- () const;
    Common_fractions operator* (Common_fractions& other) const;
    Common_fractions operator/ (Common_fractions& other) const;
    Common_fractions operator= (Common_fractions& other);
    Common_fractions operator! () const;
    bool operator!= (Common_fractions& other) const;
    bool operator== (Common_fractions& other) const;
    bool operator> (Common_fractions& other) const;
    bool operator< (Common_fractions& other) const;
    Common_fractions& operator++();
    Common_fractions operator++(int);
    Common_fractions& operator--();
    Common_fractions operator--(int);

    void print() const;
    void to_Float() const;
};

#endif
