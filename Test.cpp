#include "doctest.h"
#include <cstdlib>
#include <ctime>
#include "sources/Fraction.hpp"
using namespace ariel;

TEST_CASE("Throw for division by zero"){
    CHECK_THROWS(Fraction(1,0));
}

TEST_CASE("Test random fractions vs fractions not throwing"){
    int num1=0;
    int den1=0;
    int num2=0;
    int den2=0;
    bool result;

    for (int i = 0; i < 10; i++) {
        // Create two random fractions
        num1 = rand();
        while(den1 == 0){
            den1 = rand();
        }         
        Fraction a(num1, den1);

        num2 = rand();
        while(den2 == 0){
            den2 = rand();
        }         
        Fraction b(num2, den2);

        // Test operators
        CHECK_NOTHROW(a+b);
        CHECK_NOTHROW(a-b);
        CHECK_NOTHROW(a*b);
        CHECK_NOTHROW(a/b);
        CHECK_NOTHROW(result=(a>b));
        CHECK_NOTHROW(result=(a>=b));
        CHECK_NOTHROW(result=(a<b));
        CHECK_NOTHROW(result=(a<=b));
        CHECK_NOTHROW(result=(a==b));
        CHECK_NOTHROW(result=(a!=b));
    }
}



TEST_CASE("Test random fractions vs floats not throwing"){
    srand(time(NULL)); // Initialize the random number generator
    int num1=0;
    int den1=0;
    float random_float = 0;
    bool result = false;
    for (int i = 0; i < 5; i++) {
        num1 = rand();
        while(den1 == 0){
            den1 = rand();
        }         
        Fraction a(num1, den1);
        random_float = (((float) rand()) / ((float) RAND_MAX));

        // Test operators
        CHECK_NOTHROW(a+random_float);
        CHECK_NOTHROW(a-random_float);
        CHECK_NOTHROW(a*random_float);
        CHECK_NOTHROW(a/random_float);
        CHECK_NOTHROW(result=(a>random_float));
        CHECK_NOTHROW(result=(a>=random_float));
        CHECK_NOTHROW(result=(a<random_float));
        CHECK_NOTHROW(result=(a<=random_float));
        CHECK_NOTHROW(result=(a==random_float));
        CHECK_NOTHROW(result=(a!=random_float));
    }

}

TEST_CASE("Test random floats vs fractions not throwing"){
    srand(time(NULL)); // Initialize the random number generator
    int num1=0;
    int den1=0;
    float random_float = 0;
    bool result = false;
    for (int i = 0; i < 5; i++) {
        num1 = rand();
        while(den1 == 0){
            den1 = rand();
        }         
        Fraction a(num1, den1);
        random_float = (((float) rand()) / ((float) RAND_MAX));

        // Test operators
        CHECK_NOTHROW(random_float+a);
        CHECK_NOTHROW(random_float-a);
        CHECK_NOTHROW(random_float*a);
        CHECK_NOTHROW(random_float/a);
        CHECK_NOTHROW(result=(random_float>a));
        CHECK_NOTHROW(result=(random_float>=a));
        CHECK_NOTHROW(result=(random_float<a));
        CHECK_NOTHROW(result=(random_float<=a));
        CHECK_NOTHROW(result=(random_float==a));
        CHECK_NOTHROW(result=(random_float!=a));
    }
}