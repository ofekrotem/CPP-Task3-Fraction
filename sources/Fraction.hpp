#include <ostream>
#include <cmath>

using namespace std;
const int PERCISION = 1000; // set precision to 3 decimal places
namespace ariel 
{
class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(const int num, int den) : numerator(num) {
    // num: numerator
    // den: denominator
    if (den == 0) {
        __throw_invalid_argument("Denominator can't be zero!");
    }
        this->denominator = den;
        this->reduce();
    }


    Fraction() : numerator(0), denominator(1) {}
    Fraction(float flo){
        Fraction result;
        int gcd = __gcd(static_cast<int>(flo * PERCISION), PERCISION); // calculate greatest common divisor
        this->numerator = static_cast<int>(flo * PERCISION) / gcd;
        this->denominator = PERCISION / gcd;
    }
    int getNumerator () const{
        return this->numerator;
    }
    int getDenominator () const{
        return this->denominator;
    }
    void reduce();
    void checkAddOverflow(Fraction frac) const;
    void checkSubOverflow(Fraction frac) const;
    void checkDivOverflow(Fraction frac) const;
    void checkMulOverflow(Fraction frac) const;

    string toString() const{
        return to_string(this->numerator) + "/" + to_string(this->denominator);
    }
    
    Fraction operator+ (Fraction) const;
    Fraction operator- (Fraction) const; 
    Fraction operator* (Fraction) const;
    Fraction operator/ (Fraction) const;
    bool operator== (Fraction) const;
    bool operator!= (Fraction) const;
    bool operator< (Fraction) const;
    bool operator<= (Fraction) const;
    bool operator> (Fraction) const;
    bool operator>= (Fraction) const;

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

    Fraction operator++ () ;
    Fraction operator++ (int) ;
    Fraction operator--() ;
    Fraction operator--(int) ;

    friend istream& operator>> (istream &ist, Fraction &frac);
    friend ostream& operator<< (ostream& ost, const Fraction& frac);
};

}