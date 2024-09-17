/*****************************************************************************
*
*  Author:           Victoria Heredia
*  Email:            vdheredia1128@my.msutexas.edu
*  Label:            06-P01
*  Title:            Program 1 - Fraction Class
*  Course:           2143-Object-Oriented-Programming
*  Semester:         Fall 2024
*
*  Description:      This program defines a Fraction class that supports basic arithmetic operations 
(addition, subtraction, multiplication, and division) and equality comparison for fractions. 
The program reads fraction operations from a file named data.txt and outputs the results of these operations.
*
*  Usage:
*        how to use the program if necessary
*
*  Files:            main.cpp    : driver program            
*****************************************************************************/ 


#include <iostream>
#include <fstream>
using namespace std;
/**
 * Fraction
 *
 * Description:
 *      This class represents a fraction and supports basic arithmetic operations
 *      such as addition, subtraction, multiplication, and division. It also supports
 *      equality comparison and can reduce fractions to their simplest form.
 *
 * Public Methods:
 *                          Fraction()                                
 *                          Fraction(int n, int d)                    
 *                          Fraction(string f)                        
 *      Fraction            operator+(const Fraction& rhs) const      
 *      Fraction            operator-(const Fraction& rhs) const      
 *      Fraction            operator*(const Fraction& rhs) const      
 *      Fraction            operator/(const Fraction& rhs) const      
 *      bool                operator==(const Fraction& rhs) const    
 *      void                print() const                             
 *
 * Private Methods:
 *      int                 gcd(int a, int b) const                   
 *      int                 lcm(int a, int b) const                   
 *      void                reduce()                                  
 *
 * Usage:
 *      - Fraction f1(1, 2); // Creates a fraction 1/2
 *      - Fraction f2(3, 4); // Creates a fraction 3/4
 *      - Fraction result = f1 + f2; // Adds two fractions
 *      - cout << result; // Outputs the result
 *      - if (f1 == f2) { cout << "Equal"; } 
 */

class Fraction {
private:
    int num;
    int den;

/**
 * Private : gcd(int a, int b)
 *
 * Description:
 *      Helper function to compute the greatest common divisor (GCD) of two integers.
 *      The GCD is used to reduce fractions to their simplest form.
 *
 * Params:
 *      int  : first integer
 *      int  : second integer
 *
 * Returns:
 *      int   : the greatest common divisor of the two integers
 */
    int gcd(int a, int b) const
       {
            if (b == 0) 
            {
                return a;
            }
            else 
            {
                return gcd(b, a % b);
            }
       }

/**
 * Private : reduce()
 *
 * Description:
 *      Reduces the fraction to its simplest form by dividing both the numerator
 *      and denominator by their greatest common divisor (GCD).
 *
 * Params:
 *      None
 *
 * Returns:
 *      None
 */
    Fraction simplify(Fraction frac) const
    {
        int gcd = frac.gcd(frac.num, frac.den);
        frac.num /= gcd;
        frac.den /= gcd;
        return frac; // Return the simplified fraction
    }

public:
    Fraction() : num(1), den(1) {}

    /**
     * Public : Fraction (int n, int d)
     *
     * Description:
     *      Constructor to initialize a Fraction object with a numerator and denominator.
     *      The fraction is automatically reduced to its simplest form.
     *
     * Params:
     *      int     :  numerator
     *      int     :  denominator
     *
     * Returns:
     *      None
     */
    Fraction(int n, int d)
     {
       num = n;
       den = d;
     }

    /**
     * Public : Fraction (string f)
     *
     * Description:
     *      Constructor to initialize a Fraction object from a string in the format "n/d".
     *      It extracts the numerator and denominator from the string and reduces the fraction.
     *
     * Params:
     *      string  :  string representation of a fraction (e.g., "3/4")
     *
     * Returns:
     *      None
     */
    Fraction(string f) 
     {
        num = f[0] - 48;
        den = f[2] - 48;
         simplify(f);
     }

    friend ostream &operator<<(ostream &os, const Fraction &rhs) {
        return os << rhs.num << "/" << rhs.den;
    }

/**
 * Public : operator+(const Fraction& rhs)
 *
 * Description:
 *      Overloads the + operator to add two fractions.
 *      It finds a common denominator, adds the numerators, and returns the resulting fraction.
 *
 * Params:
 *      const Fraction&  :  right-hand side fraction to add
 *
 * Returns:
 *      Fraction   : the result of adding two fractions
 */
    Fraction operator+(const Fraction &rhs) const {
        Fraction temp = rhs;
        temp.num = temp.num * this->den;
        temp.den = temp.den * this->den;

        int newnum = this->num * rhs.den;
        int newden = this->den * rhs.den;

        temp.num = temp.num + newnum;
        temp.den = newden;

        return simplify(temp);
    }


/**
 * Public : operator-(const Fraction& rhs)
 *
 * Description:
 *      Overloads the - operator to subtract two fractions.
 *      It finds a common denominator, subtracts the numerators, and returns the resulting fraction.
 *
 * Params:
 *      const Fraction&  :  right-hand side fraction to subtract
 *
 * Returns:
 *      Fraction   : the result of subtracting two fractions
 */
    Fraction operator-(const Fraction &rhs) const {
        Fraction temp = rhs;
        temp.num = temp.num * this->den;
        temp.den = temp.den * this->den;

        int newnum = this->num * rhs.den;
        int newden = this->den * rhs.den;

        temp.num = newnum - temp.num;
        temp.den = newden;

        
        return simplify(temp);
    }

/**
 * Public : operator*(const Fraction& rhs)
 *
 * Description:
 *      Overloads the * operator to multiply two fractions.
 *      It multiplies the numerators and denominators and returns the resulting fraction.
 *
 * Params:
 *      const Fraction&  :  right-hand side fraction to multiply
 *
 * Returns:
 *      Fraction   : the result of multiplying two fractions
 */
    Fraction operator*(const Fraction &rhs) const {
        int num = this->num * rhs.num;
        int den = this->den * rhs.den;
        return simplify (Fraction(num, den));
        
    }

/**
 * Public : operator/(const Fraction& rhs)
 *
 * Description:
 *      Overloads the / operator to divide two fractions.
 *      It multiplies the numerator of the first fraction with the denominator of the second,
 *      and vice versa, to perform the division.
 *
 * Params:
 *      const Fraction&  :  right-hand side fraction to divide by
 *
 * Returns:
 *      Fraction   : the result of dividing two fractions
 */
    Fraction operator/(const Fraction &rhs) const {
        int num = this->num * rhs.den;
        int den = this->den * rhs.num;
        return simplify (Fraction(num, den));
    }

/**
 * Public : operator==(const Fraction& rhs)
 *
 * Description:
 *      Overloads the == operator to compare two fractions for equality.
 *      It checks if the cross-multiplied values of the numerators and denominators are equal.
 *
 * Params:
 *      const Fraction&  :  right-hand side fraction to compare
 *
 * Returns:
 *      bool   : true if fractions are equal, false otherwise
 */
    bool operator==(const Fraction &rhs) const 
        {
            bool result = (this->num * rhs.den) == (this->den * rhs.num);
            if (result) 
            {
                cout << "Comparison result: Equal" << endl;
            } 
            else 
            {
                cout << "Comparison result: Not Equal" << endl;
            }
            return result;
        }

    void print() const 
    {
        cout << num << "/" << den << endl;
    }
};

int main() 
{
    
    string f1, op, f2;

      while (cin >> f1 >> op >> f2) {
        auto i = f1[0] - '0';
        auto j = f1[2] - '0';
        auto x = f2[0] - '0';
        auto y = f2[2] - '0';

        Fraction F1(i, j);
        Fraction F2(x, y);

        if (op == "+")
            cout << F1 + F2 << endl;
        else if (op == "-")
            cout << F1 - F2 << endl;
        else if (op == "*")
            cout << F1 * F2 << endl;
        else if (op == "/")
            cout << F1 / F2 << endl;
        else if (op == "==")
        {
             if (F1 == F2)
                cout << "true" << endl;
             else
                cout << "false" << endl;
        }
    }

    return 0;
}