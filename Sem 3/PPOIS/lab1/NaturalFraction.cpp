#include <iostream>
#include "NaturalFraction.h"
using namespace std;




void NaturalFraction::putAwayIntPart() {
    if (intPart < 0)  numerator *= -1;
        numerator += intPart * denominator;
        intPart = 0;
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
    countIntPart();


    int gcd = calculateGCD(numerator, denominator);

    numerator /= abs(gcd);
    denominator /= abs(gcd);
   

}

void NaturalFraction::countIntPart() {
    if (numerator >= denominator) {
        if (intPart < 0) {
            intPart -= numerator / denominator;
            numerator %= denominator;
        }
        else {
            intPart += numerator / denominator;
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
    putAwayIntPart();
    other.putAwayIntPart();
    int newDenominator = denominator * other.denominator;
    int newNuminator = (numerator * other.denominator) + (other.numerator * denominator);
    int newIntPart = intPart + other.intPart;

    if (abs(newNuminator) >= abs(newDenominator)) {
        if (newIntPart < 0) {
            newIntPart -= newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
        else {
            newIntPart += newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
    }

    return NaturalFraction(newIntPart, newNuminator, newDenominator);
}

NaturalFraction NaturalFraction::operator +(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this + fraction;
}

NaturalFraction NaturalFraction::operator +=(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
    int newDenominator = denominator * other.denominator;
    int newNuminator = (numerator * other.denominator) + (other.numerator * denominator);
    int newIntPart = intPart + other.intPart;

    if (abs(newNuminator) >= abs(newDenominator)) {
        if (newIntPart < 0) {
            newIntPart -= newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
        else {
            newIntPart += newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
    }
    setNaturalFraction(newIntPart, newNuminator, newDenominator);
    return *this;
}

NaturalFraction NaturalFraction::operator +=(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this += fraction;
}

NaturalFraction NaturalFraction::operator -(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();

    int newDenominator = denominator * other.denominator;
    int newIntPart = 0;
    int newNuminator = (numerator * other.denominator) - (other.numerator * denominator);

    if (abs(newNuminator) >= abs(newDenominator)) {
        if (newIntPart < 0) {
            newIntPart -= newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
        else {
            newIntPart += newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
    }

    return NaturalFraction(newIntPart, newNuminator, newDenominator);
}

NaturalFraction NaturalFraction::operator -(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this - fraction;
}

NaturalFraction NaturalFraction::operator -=(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
    int newDenominator = denominator * other.denominator;
    int newNuminator = (numerator * other.denominator) - (other.numerator * denominator);
    int newIntPart = 0;

    if (abs(newNuminator) >= abs(newDenominator)) {
        if (newIntPart < 0) {
            newIntPart -= newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
        else {
            newIntPart += newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
    }
    setNaturalFraction(newIntPart, newNuminator, newDenominator);

    return *this;
}

NaturalFraction NaturalFraction::operator -=(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this -= fraction;
}

NaturalFraction NaturalFraction::operator *(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
    int newDenominator = denominator * other.denominator;
    int newNuminator = numerator * other.numerator;
    int newIntPart = 0;
    if (abs(newNuminator) >= abs(newDenominator)) {
        if (newIntPart < 0) {
            newIntPart -= newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
        else {
            newIntPart += newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
    }

    return NaturalFraction(newIntPart, newNuminator, newDenominator);
}

NaturalFraction NaturalFraction::operator *(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this * fraction;
}

NaturalFraction NaturalFraction::operator *=(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
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
    putAwayIntPart();
    other.putAwayIntPart();
    int newDenominator = denominator * other.numerator;
    int newNuminator = numerator * other.denominator;
    int newIntPart = 0;
    if (abs(newNuminator) >= abs(newDenominator)) {
        if (newIntPart < 0) {
            newIntPart -= newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
        else {
            newIntPart += newNuminator / newDenominator;
            newNuminator %= newDenominator;
        }
    }

    return NaturalFraction(newIntPart, newNuminator, newDenominator);
}

NaturalFraction NaturalFraction::operator /(int number) {
    NaturalFraction fraction(0, number, 1);
    return *this / fraction;
}

NaturalFraction NaturalFraction::operator /=(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
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
    putAwayIntPart();
    return *this + 1;
}

NaturalFraction NaturalFraction::operator ++(int) {
    putAwayIntPart();
    NaturalFraction th = *this;
    *this += 1;
    return th;
}

NaturalFraction NaturalFraction::operator --() {
    putAwayIntPart();
    return *this - 1;

}

NaturalFraction NaturalFraction::operator --(int) {
    putAwayIntPart();
    NaturalFraction th = *this;
    *this -= 1;
    return th;
}

bool NaturalFraction::operator <(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool NaturalFraction::operator <(int number) {
    putAwayIntPart();
    NaturalFraction fraction(0, number, 1);
    return *this < fraction;
}

bool NaturalFraction::operator >(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool NaturalFraction::operator >(int number) {
    putAwayIntPart();
    NaturalFraction fraction(0, number, 1);
    return *this > fraction;
}

bool NaturalFraction::operator <=(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
    return (numerator * other.denominator) <= (other.numerator * denominator);
}

bool NaturalFraction::operator <=(int number) {
    putAwayIntPart();
    NaturalFraction fraction(0, number, 1);
    return *this <= fraction;
}

bool NaturalFraction::operator >=(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
    return (numerator * other.denominator) >= (other.numerator * denominator);
}

bool NaturalFraction::operator >=(int number) {
    putAwayIntPart();
    NaturalFraction fraction(0, number, 1);
    return *this >= fraction;
}

bool NaturalFraction::operator ==(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
    return (numerator * other.denominator) == (other.numerator * denominator);
}

bool NaturalFraction::operator ==(int number) {
    putAwayIntPart();
    NaturalFraction fraction(0, number, 1);
    return *this == fraction;
}

bool NaturalFraction::operator !=(NaturalFraction& other) {
    putAwayIntPart();
    other.putAwayIntPart();
    return (numerator * other.denominator) != (other.numerator * denominator);
}

bool NaturalFraction::operator !=(int number) {
    putAwayIntPart();
    NaturalFraction fraction(0, number, 1);
    return *this != fraction;
}

double NaturalFraction::toDouble() {
    putAwayIntPart();
    return static_cast<double>(numerator) / denominator;
}

void NaturalFraction::print()
{
    reduce();
    cout << "Int part: " << intPart << " Numerator: " << numerator << " Denominator: " << denominator << endl;
}
