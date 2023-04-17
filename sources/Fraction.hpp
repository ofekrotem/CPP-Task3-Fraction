#include <ostream>
#include <cmath>

using namespace std;

namespace ariel 
{
class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int den){
        this->numerator = num;
        if (den == 0) {
            __throw_invalid_argument("Denominator can't be zero!");
        }
        this->denominator = den;
        this->reduce();
    }
    Fraction(){
        this->numerator = 0;
        this->denominator = 1;
    }
    Fraction(float f){
        this->numerator = static_cast<int>(f * 1000);
        this->denominator = 1000;
        this->reduce();
    }
    int getNumerator () {
        return this->numerator;
    }
    int getDenominator () {
        return this->denominator;
    }
    void reduce();

    string toString() const{
        return to_string(this->numerator) + "/" + to_string(this->denominator);
    }
    
    Fraction operator+ (Fraction);
    Fraction operator- (Fraction); 
    Fraction operator* (Fraction);
    Fraction operator/ (Fraction);
    bool operator== (Fraction);
    bool operator!= (Fraction);
    bool operator< (Fraction);
    bool operator<= (Fraction);
    bool operator> (Fraction);
    bool operator>= (Fraction);

    friend Fraction operator+ (float,Fraction);
    friend Fraction operator- (float,Fraction); 
    friend Fraction operator* (float,Fraction);
    friend Fraction operator/ (float,Fraction);
    friend bool operator== (float,Fraction);
    friend bool operator!= (float,Fraction);
    friend bool operator< (float,Fraction);
    friend bool operator<= (float,Fraction);
    friend bool operator> (float,Fraction);
    friend bool operator>= (float,Fraction);

    Fraction operator+ (float);
    Fraction operator- (float); 
    Fraction operator* (float);
    Fraction operator/ (float);
    bool operator== (float);
    bool operator!= (float);
    bool operator< (float);
    bool operator<= (float);
    bool operator> (float);
    bool operator>= (float);

    Fraction operator++ ();
    Fraction operator++ (int);
    Fraction operator--();
    Fraction operator--(int);

    friend istream& operator>> (istream &is, Fraction &f);
    friend ostream& operator<< (ostream& os, const Fraction& f);
};

}