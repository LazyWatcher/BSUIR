#include <iostream>
#include "NaturalFraction.h"
using namespace std;




void NaturalFraction::putAwayIntPart(NaturalFraction& th) {
    if (intPart < 0)  th.numerator *= -1;
        th.numerator += th.intPart * th.denominator;
        th.intPart = 0;
}

void NaturalFraction::checkMinus() {
    if ((numerator < 0 && denominator < 0 && intPart < 0) || (numerator < 0 && intPart > 0 && denominator > 0) || (numerator > 0 && intPart > 0 && denominator < 0)) {
        intPart *= -1;
        denominator = abs(denominator);
        numerator = abs(numerator);
    }
    if ((denominator < 0 && numerator > 0 && intPart < 0) || (numerator < 0 && denominator < 0 && intPart > 0) || (numerator > 0 && denominator < 0 && intPart < 0)) {
        intPart = abs(intPart);
        denominator = abs(denominator);
        numerator = abs(numerator);
    }  
}


void NaturalFraction::setNumerator(int  numerator_)
{
    numerator = numerator_;
}
void NaturalFraction::setIntPart(int  intPart_)
{
    intPart = intPart_;
}

void NaturalFraction::setDenominator(int  denominator_)
{
    do {
        if (denominator_ == 0) {
            cout << "Error" << endl;
            cin >> denominator_;
        }
        else {
            denominator = denominator_;
        }
    } while (denominator_ == 0);
}


int NaturalFraction::calculateGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return calculateGCD(b, a % b);
}

void NaturalFraction::reduce() {
    checkMinus();
    countIntPart(*this);


    int gcd = calculateGCD(numerator, denominator);

    numerator /= abs(gcd);
    denominator /= abs(gcd);
   

}

void NaturalFraction::countIntPart(NaturalFraction& th) {
    if (th.numerator >= th.denominator) {
        if (th.intPart < 0) {
            th.intPart -= th.numerator / th.denominator;
            numerator %= denominator;
        }
        else {
            th.intPart += th.numerator / th.denominator;
            numerator %= denominator;
        }
    }
}

NaturalFraction::NaturalFraction(int intPart_, int numerator_, int denominator_) : intPart(intPart_), numerator(numerator_), denominator(denominator_) {
    reduce();
}

NaturalFraction::NaturalFraction() : intPart(0), numerator(0), denominator(1) {}

int NaturalFraction::getIntPart() {
    return intPart;
}

int NaturalFraction::getNumerator() {
    return numerator;
}

int NaturalFraction::getDenominator() {
    return denominator;
}


void NaturalFraction::setNaturalFraction(int intPart_, int numerator_, int denominator_) {
    setIntPart(intPart_);
    setNumerator(numerator_);
    setDenominator(denominator_);
    reduce();


}

NaturalFraction NaturalFraction::operator +(NaturalFraction& other) {
     putAwayIntPart(*this);
    putAwayIntPart(other);
    int newDenom = denominator * other.denominator;
    int newNum = (numerator * other.denominator) + (other.numerator * denominator);
    int newIntPart = intPart + other.intPart;

    if (abs(newNum) >= abs(newDenom)) {
        if (newIntPart < 0) {
            newIntPart -= newNum / newDenom;
            newNum %= newDenom;
        }
        else {
            newIntPart += newNum / newDenom;
            newNum %= newDenom;
        }
    }

    return NaturalFraction(newIntPart, newNum, newDenom);
}

NaturalFraction NaturalFraction::operator +(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this + fraction;
}

NaturalFraction NaturalFraction::operator +=(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    int newDenom = denominator * other.denominator;
    int newNum = (numerator * other.denominator) + (other.numerator * denominator);
    int newIntPart = intPart + other.intPart;

    if (abs(newNum) >= abs(newDenom)) {
        if (newIntPart < 0) {
            newIntPart -= newNum / newDenom;
            newNum %= newDenom;
        }
        else {
            newIntPart += newNum / newDenom;
            newNum %= newDenom;
        }
    }
    setNaturalFraction(newIntPart, newNum, newDenom);
    return *this;
}

NaturalFraction NaturalFraction::operator +=(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this += fraction;
}

NaturalFraction NaturalFraction::operator -(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);

    int newDenom = denominator * other.denominator;
    int newIntPart = 0;
    int newNum = (numerator * other.denominator) - (other.numerator * denominator);

    if (abs(newNum) >= abs(newDenom)) {
        if (newIntPart < 0) {
            newIntPart -= newNum / newDenom;
            newNum %= newDenom;
        }
        else {
            newIntPart += newNum / newDenom;
            newNum %= newDenom;
        }
    }

    return NaturalFraction(newIntPart, newNum, newDenom);
}

NaturalFraction NaturalFraction::operator -(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this - fraction;
}

NaturalFraction NaturalFraction::operator -=(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    int newDenom = denominator * other.denominator;
    int newNum = (numerator * other.denominator) - (other.numerator * denominator);
    int newIntPart = 0;

    if (abs(newNum) >= abs(newDenom)) {
        if (newIntPart < 0) {
            newIntPart -= newNum / newDenom;
            newNum %= newDenom;
        }
        else {
            newIntPart += newNum / newDenom;
            newNum %= newDenom;
        }
    }
    setNaturalFraction(newIntPart, newNum, newDenom);

    return *this;
}

NaturalFraction NaturalFraction::operator -=(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this -= fraction;
}

NaturalFraction NaturalFraction::operator *(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    int newDenom = denominator * other.denominator;
    int newNum = numerator * other.numerator;
    int newIntPart = 0;
    if (abs(newNum) >= abs(newDenom)) {
        if (newIntPart < 0) {
            newIntPart -= newNum / newDenom;
            newNum %= newDenom;
        }
        else {
            newIntPart += newNum / newDenom;
            newNum %= newDenom;
        }
    }

    return NaturalFraction(newIntPart, newNum, newDenom);
}

NaturalFraction NaturalFraction::operator *(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this * fraction;
}

NaturalFraction NaturalFraction::operator *=(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    denominator *= other.denominator;
    numerator *= other.numerator;
    int newIntPart = 0;
    if (abs(numerator) >= abs(denominator)) {
        if (newIntPart < 0) {
            newIntPart -= numerator / denominator;
            numerator %= denominator;
        }
        else {
            newIntPart += numerator / denominator;
            numerator %= denominator;
        }
    }

    setNaturalFraction(newIntPart, numerator, denominator);
    return *this;
}

NaturalFraction NaturalFraction::operator *=(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this *= fraction;
}

NaturalFraction NaturalFraction::operator /(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    int newDenom = denominator * other.numerator;
    int newNum = numerator * other.denominator;
    int newIntPart = 0;
    if (abs(newNum) >= abs(newDenom)) {
        if (newIntPart < 0) {
            newIntPart -= newNum / newDenom;
            newNum %= newDenom;
        }
        else {
            newIntPart += newNum / newDenom;
            newNum %= newDenom;
        }
    }

    return NaturalFraction(newIntPart, newNum, newDenom);
}

NaturalFraction NaturalFraction::operator /(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this / fraction;
}

NaturalFraction NaturalFraction::operator /=(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    numerator *= other.denominator;
    denominator *= other.numerator;
    int newIntPart = 0;

    if (abs(numerator) >= abs(denominator)) {
        if (newIntPart < 0) {
            newIntPart -= numerator / denominator;
            numerator %= denominator;
        }
        else {
            newIntPart += numerator / denominator;
            numerator %= denominator;
        }
    }

    setNaturalFraction(newIntPart, numerator, denominator);
    return *this;
}

NaturalFraction NaturalFraction::operator /=(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this /= fraction;
}

NaturalFraction NaturalFraction::operator ++() {
    putAwayIntPart(*this);
    return *this + 1;
}

NaturalFraction NaturalFraction::operator ++(int) {
    putAwayIntPart(*this);
    NaturalFraction th = *this;
    *this += 1;
    return th;
}

NaturalFraction NaturalFraction::operator --() {
    putAwayIntPart(*this);
    return *this - 1;

}

NaturalFraction NaturalFraction::operator --(int) {
    putAwayIntPart(*this);
    NaturalFraction th = *this;
    *this -= 1;
    return th;
}

bool NaturalFraction::operator <(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool NaturalFraction::operator <(int number) {
    putAwayIntPart(*this);
    NaturalFraction fraction(0, number, 1);
    return *this < fraction;
}

bool NaturalFraction::operator >(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool NaturalFraction::operator >(int number) {
    putAwayIntPart(*this);
    NaturalFraction fraction(0, number, 1);
    return *this > fraction;
}

bool NaturalFraction::operator <=(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    return (numerator * other.denominator) <= (other.numerator * denominator);
}

bool NaturalFraction::operator <=(int number) {
    putAwayIntPart(*this);
    NaturalFraction fraction(0, number, 1);
    return *this <= fraction;
}

bool NaturalFraction::operator >=(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    return (numerator * other.denominator) >= (other.numerator * denominator);
}

bool NaturalFraction::operator >=(int number) {
    putAwayIntPart(*this);
    NaturalFraction fraction(0, number, 1);
    return *this >= fraction;
}

bool NaturalFraction::operator ==(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    return (numerator * other.denominator) == (other.numerator * denominator);
}

bool NaturalFraction::operator ==(int number) {
    putAwayIntPart(*this);
    NaturalFraction fraction(0, number, 1);
    return *this == fraction;
}

bool NaturalFraction::operator !=(NaturalFraction& other) {
    putAwayIntPart(*this);
    putAwayIntPart(other);
    return (numerator * other.denominator) != (other.numerator * denominator);
}

bool NaturalFraction::operator !=(int number) {
    putAwayIntPart(*this);
    NaturalFraction fraction(0, number, 1);
    return *this != fraction;
}

double NaturalFraction::toDouble() {
    putAwayIntPart(*this);
    return static_cast<double>(numerator) / denominator;
}

void NaturalFraction::print()
{
    reduce();
    cout << "Int part: " << intPart << " Numerator: " << numerator << " Denominator: " << denominator << endl;
}
