#include <iostream>
using namespace std;

class NaturalFraction {
private:

    int intPart; // целая часть

    int numerator; // числитель

    int denominator; // знаменатель

    void checkMinus();

    void setNumerator(int  numerator_);

    void setIntPart(int  intPart_);

    void setDenominator(int  denominator_);

    int calculateGCD(int a, int b);

    void reduce();

public:

    NaturalFraction(int intPart_, int numerator_, int denominator_);

    NaturalFraction();

    int getIntPart();

    int getNumerator();

    int getDenominator();

    void setNaturalFraction(int intPart_, int numerator_, int denominator_);

    void countIntPart();

    void putAwayIntPart();

    NaturalFraction operator +(NaturalFraction& other);

    NaturalFraction operator +(int number);

    NaturalFraction operator +=(NaturalFraction& other);

    NaturalFraction operator +=(int number);

    NaturalFraction operator -(NaturalFraction& other);

    NaturalFraction operator -(int number);

    NaturalFraction operator -=(NaturalFraction& other);

    NaturalFraction operator -=(int number);

    NaturalFraction operator *(NaturalFraction& other);

    NaturalFraction operator *(int number);

    NaturalFraction operator /(NaturalFraction& other);

    NaturalFraction operator /(int number);

    NaturalFraction operator *=(NaturalFraction& other);

    NaturalFraction operator *=(int number);

    NaturalFraction operator /=(NaturalFraction& other);

    NaturalFraction operator /=(int number);

    NaturalFraction operator++();

    NaturalFraction operator++(int);

    NaturalFraction operator--();

    NaturalFraction operator--(int);

    bool operator <(NaturalFraction& other);

    bool operator <(int number);

    bool operator <=(NaturalFraction& other);

    bool operator <=(int number);

    bool operator >(NaturalFraction& other);

    bool operator >(int number);

    bool operator >=(NaturalFraction& other);

    bool operator >=(int number);

    bool operator ==(NaturalFraction& other);

    bool operator ==(int number);

    bool operator !=(NaturalFraction& other);

    bool operator !=(int number);

    double toDouble();

    void print();
};

