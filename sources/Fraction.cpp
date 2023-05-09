#include "Fraction.hpp"
#include <iostream>
using namespace std;

namespace ariel {
    const int MAX = numeric_limits<int>::max();
    const int MIN = numeric_limits<int>::min();

    void Fraction::reduce() {
        if( this->numerator == 0){
            this->denominator = 1;
        }
        int gcd = __gcd(this->numerator, this->denominator);
        this->numerator /= gcd;
        this->denominator /= gcd;
         if( this->denominator < 0){
            this->numerator *=-1;
            this->denominator *= -1;
        }
    }
    void Fraction::checkAddOverflow(Fraction frac) const {
        if ((this->numerator == MAX ^ this->denominator == MAX) || (this->numerator <= MIN + 100 && frac.numerator <= MIN + 100)){
            throw overflow_error("overflow");
        }
    }

    void Fraction::checkSubOverflow(Fraction frac) const {
        if ((this->numerator <= MIN + 100 && frac.numerator <= MIN + 100) || (this-> numerator >= MAX - 100 && frac.numerator <= MIN + 100)){
            throw overflow_error("overflow");
        }
    }

    void Fraction::checkDivOverflow(Fraction frac) const {
        if ((this->denominator == MAX && this->numerator < MAX - 100) || (this->numerator == MAX && this-> denominator != MAX)){
            throw overflow_error("overflow");
        }
    }

    void Fraction::checkMulOverflow(Fraction frac) const {
        if ((this->numerator == MAX ^ this->denominator == MAX) || (frac.numerator == MAX && frac.denominator != MAX)){
            throw overflow_error("overflow");
        }
    }

    Fraction Fraction::operator+ (Fraction frac) const{
        this->checkAddOverflow(frac);
        int newNum = (this->numerator * frac.getDenominator()) + (frac.getNumerator() * this->denominator);
        int newDen = this->denominator * frac.getDenominator();
        Fraction result(newNum,newDen);
        result.reduce();
        return result;
    }
    Fraction Fraction::operator- (Fraction frac) const{
        this->checkSubOverflow(frac);
        int newNum = (this->numerator * frac.getDenominator()) - (frac.getNumerator() * this->denominator);
        int newDen = this->denominator * frac.getDenominator();
        Fraction result(newNum,newDen);
        result.reduce();
        return result;
    } 
    Fraction Fraction::operator* (Fraction frac) const{
        this->checkMulOverflow(frac);
        int newNum = this->numerator * frac.getNumerator();
        int newDen = this->denominator * frac.getDenominator();
        Fraction result(newNum,newDen);
        result.reduce();
        return result;
    }
    Fraction Fraction::operator/ (Fraction frac) const{
        this->checkDivOverflow(frac);
        if (frac == Fraction(0,1)){
           __throw_runtime_error("Trying to divide by zero!"); 
        }
        int newNum = this->numerator * frac.getDenominator();
        int newDen = this->denominator * frac.getNumerator();
        Fraction result(newNum,newDen);
        result.reduce();
        return result;
    }
    bool Fraction::operator== (Fraction frac) const{
        Fraction temp1 = *this;
        Fraction temp2 = frac;
        temp1.reduce();
        temp2.reduce();
        return temp1.getNumerator() == temp2.getNumerator() && temp1.getDenominator() == temp2.getDenominator();
    }
    bool Fraction::operator!= (Fraction frac) const{
        return this->numerator != frac.getNumerator() || this->denominator != frac.getDenominator();
    }
    bool Fraction::operator< (Fraction frac) const{
        return ((float)this->numerator/(float)this->denominator) < ((float)frac.getNumerator()/(float)frac.getDenominator());
    }
    bool Fraction::operator<= (Fraction frac) const{
        return ((float)this->numerator/(float)this->denominator) <= ((float)frac.getNumerator()/(float)frac.getDenominator());
    }
    bool Fraction::operator> (Fraction frac) const{
        return ((float)this->numerator/(float)this->denominator) > ((float)frac.getNumerator()/(float)frac.getDenominator());
    }
    bool Fraction::operator>= (Fraction frac) const{
        return ((float)this->numerator/(float)this->denominator) >= ((float)frac.getNumerator()/(float)frac.getDenominator());
    }

    Fraction operator+ (float fl,Fraction frac) {
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
           __throw_runtime_error("Trying to divide by zero!"); 
        }
        Fraction f(fl);
        return (f/frac);
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
            __throw_runtime_error("Trying to divide by zero!"); 
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

    Fraction Fraction::operator++ () {
        this->numerator+=this->denominator;
        this->reduce();
        return *this;
    }
    Fraction Fraction::operator++ (int) {
        Fraction old = *this;
        this->numerator+=this->denominator;
        this->reduce();
        return old;
    }
    Fraction Fraction::operator--() {
        this->numerator-=this->denominator;
        this->reduce();
        return *this;
    }
    Fraction Fraction::operator--(int) {
        Fraction old = *this;
        this->numerator-=this->denominator;
        this->reduce();
        return old;
    }

    istream& operator>> (istream &is, Fraction &frac) { 
        int num;
        int den = 0 ;
        is >> num >> den;
        if (den == 0 ){
            __throw_runtime_error("Denominator can't be zero!");
            return is;
        }
        frac = Fraction(num, den);
        return is;
    }

    ostream& operator<< (ostream& os, const Fraction& frac){
        os << frac.toString();
        return os;
    }


}