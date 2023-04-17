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

    Fraction operator+ (float fl,Fraction frac){return frac;}
    Fraction operator- (float fl,Fraction frac){return frac;} 
    Fraction operator* (float fl,Fraction frac){return frac;}
    Fraction operator/ (float fl,Fraction frac){return frac;}
    bool operator== (float fl,Fraction frac){return false;}
    bool operator!= (float fl,Fraction frac){return false;}
    bool operator< (float fl,Fraction frac){return false;}
    bool operator<= (float fl,Fraction frac){return false;}
    bool operator> (float fl,Fraction frac){return false;}
    bool operator>= (float fl,Fraction frac){return false;}

    Fraction Fraction::operator+ (float fl){
        Fraction a(1,1);
        return a;
    }
    Fraction Fraction::operator- (float fl){
        Fraction a(1,1);
        return a;
    }
    Fraction Fraction::operator* (float fl){
        Fraction a(1,1);
        return a;
    }
    Fraction Fraction::operator/ (float fl){
        Fraction a(1,1);
        return a;
    }
    bool Fraction::operator== (float fl){return false;}
    bool Fraction::operator!= (float fl){return false;}
    bool Fraction::operator< (float fl){return false;}
    bool Fraction::operator<= (float fl){return false;}
    bool Fraction::operator> (float fl){return false;}
    bool Fraction::operator>= (float fl){return false;}

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

    istream& operator>> (istream &is, Fraction &f){ return is;}
    ostream& operator<< (ostream& os, const Fraction& f){return os;}


}