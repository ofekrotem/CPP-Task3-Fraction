#include "Fraction.hpp"
#include <iostream>
using namespace std;

namespace ariel {

    void Fraction::reduce() {
        if(this->numerator < 0 && this->denominator <0){
            this->numerator = abs(this->numerator);
            this->denominator = abs(this->denominator);
        }
        int gcd = __gcd(this->numerator, this->denominator);
        this->numerator /= gcd;
        this->denominator /= gcd;
    }

    Fraction Fraction::operator+ (Fraction frac){
        int newNum = (this->numerator * frac.getDenominator()) + (frac.getNumerator() * this->denominator);
        int newDen = this->denominator * frac.getDenominator();
        Fraction result(newNum,newDen);
        result.reduce();
        return result;
    }
    Fraction Fraction::operator- (Fraction frac){
        int newNum = (this->numerator * frac.getDenominator()) - (frac.getNumerator() * this->denominator);
        int newDen = this->denominator * frac.getDenominator();
        Fraction result(newNum,newDen);
        result.reduce();
        return result;
    } 
    Fraction Fraction::operator* (Fraction frac){
        int newNum = this->numerator * frac.getNumerator();
        int newDen = this->denominator * frac.getDenominator();
        Fraction result(newNum,newDen);
        result.reduce();
        return result;
    }
    Fraction Fraction::operator/ (Fraction frac){
        if (frac == Fraction(0,1)){
           __throw_invalid_argument("Trying to divide by zero!"); 
        }
        int newNum = this->numerator * frac.getDenominator();
        int newDen = this->denominator * frac.getNumerator();
        Fraction result(newNum,newDen);
        result.reduce();
        return result;
    }
    bool Fraction::operator== (Fraction frac){
        return this->numerator == frac.getNumerator() && this->denominator == frac.getDenominator();
    }
    bool Fraction::operator!= (Fraction frac){
        return this->numerator != frac.getNumerator() || this->denominator == frac.getDenominator();
    }
    bool Fraction::operator< (Fraction frac){
        return ((float)this->numerator/(float)this->denominator) < ((float)frac.getNumerator()/(float)frac.getDenominator());
    }
    bool Fraction::operator<= (Fraction frac){
        return ((float)this->numerator/(float)this->denominator) <= ((float)frac.getNumerator()/(float)frac.getDenominator());
    }
    bool Fraction::operator> (Fraction frac){
        return ((float)this->numerator/(float)this->denominator) > ((float)frac.getNumerator()/(float)frac.getDenominator());
    }
    bool Fraction::operator>= (Fraction frac){
        return ((float)this->numerator/(float)this->denominator) >= ((float)frac.getNumerator()/(float)frac.getDenominator());
    }

    Fraction operator+ (float fl,Fraction frac){
        Fraction f(fl);
        return (f+frac);
    }
    Fraction operator- (float fl,Fraction frac){
        Fraction f(fl);
        return (f-frac);
    } 
    Fraction operator* (float fl,Fraction frac){
        Fraction f(fl);
        return (f*frac);
    }
    Fraction operator/ (float fl,Fraction frac){
        if (frac == Fraction(0,1)){
           __throw_invalid_argument("Trying to divide by zero!"); 
        }
        Fraction f(fl);
        return (f+frac);
    }
    bool operator== (float fl,Fraction frac){
        Fraction f(fl);
        return f==frac;
    }
    bool operator!= (float fl,Fraction frac){
        Fraction f(fl);
        return f!=frac;
    }
    bool operator< (float fl,Fraction frac){
        Fraction f(fl);
        return f<frac;
    }
    bool operator<= (float fl,Fraction frac){
        Fraction f(fl);
        return f<=frac;
    }
    bool operator> (float fl,Fraction frac){
        Fraction f(fl);
        return f>frac;
    }
    bool operator>= (float fl,Fraction frac){
        Fraction f(fl);
        return f>=frac;
    }

    Fraction Fraction::operator+ (float fl){
        Fraction f(fl);
        return *this + f;
    }
    Fraction Fraction::operator- (float fl){
        Fraction f(fl);
        return *this - f;
    }
    Fraction Fraction::operator* (float fl){
        Fraction f(fl);
        return *this * f;
    }
    Fraction Fraction::operator/ (float fl){
        if (fl == 0.0) {
            __throw_invalid_argument("Trying to divide by zero!"); 
        }
        Fraction f(fl);
        return *this / f;
    }
    bool Fraction::operator== (float fl){
        Fraction f(fl);
        return *this == f;
    }
    bool Fraction::operator!= (float fl){
        Fraction f(fl);
        return *this != f;
    }
    bool Fraction::operator< (float fl){
        Fraction f(fl);
        return *this < f;
    }
    bool Fraction::operator<= (float fl){
        Fraction f(fl);
        return *this <= f;
    }
    bool Fraction::operator> (float fl){
        Fraction f(fl);
        return *this > f;
    }
    bool Fraction::operator>= (float fl){
        Fraction f(fl);
        return *this >= f;
    }

    Fraction Fraction::operator++ (){
        this->numerator+=this->denominator;
        this->reduce();
        return *this;
    }
    Fraction Fraction::operator++ (int){
        this->numerator+=this->denominator;
        this->reduce();
        return *this;
    }
    Fraction Fraction::operator--(){
        this->numerator-=this->denominator;
        this->reduce();
        return *this;
    }
    Fraction Fraction::operator--(int){
        this->numerator-=this->denominator;
        this->reduce();
        return *this;
    }

    istream& operator>> (istream &is, Fraction &frac){ 
        int num;
        int den;
        is >> num >> den;
        frac = Fraction(num, den);
        return is;
    }

    ostream& operator<< (ostream& os, const Fraction& frac){
        os << frac.toString() << endl;
        return os;
    }


}