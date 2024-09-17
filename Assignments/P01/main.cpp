/*****************************************************************************
*
*  Author:           Victoria Heredia
*  Email:            vdheredia1128@my.msutexas.edu
*  Label:            P01
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
 *      void                simplify()                                  
 *
 * Usage:
 *      - Fraction f1(1, 2); 
 *      - Fraction f2(3, 4); 
 *      - Fraction result = f1 + f2; 
 *      - cout << result; 
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
    int gcd(int a, int b) const                 // 'a' and 'b' are the parameters passed to the function, these parameters 
                                                // represent the two integers for which the GCD is to be calculated
       {
            if (b == 0)                         //Base case: if b is 0, the GCD is a
            {
                return a;
            }
            else 
            { 
                return gcd(b, a % b);           //Recursive case: call gcd with b and the remainder of a divided by b
            }
       }

/**
 * Private : simplify()
 *
 * Description:
 *      Simplifies the fraction to its simplest form by dividing both the numerator
 *      and denominator by their greatest common divisor (GCD).
 *
 * Params:
 *      None
 *
 * Returns:
 *      None
 */ 
  Fraction simplify(Fraction frac) const          // 'frac' is the parameter passed to the function  
    {
        int gcd = frac.gcd(frac.num, frac.den);  // Calculate the greatest common divisor (GCD) of the numerator and denominator
        
        frac.num /= gcd;                         // Divide the numerator and denominator by the GCD to simplify the fraction
        frac.den /= gcd;
       
        return frac;                             // Return the simplified fraction
    }

public:
    Fraction() : num(1), den(1) {}               // Default constructor for the Fraction class, initializes the fraction to 1/1

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
        num = f[0] - 48;                                            // Convert the first character of the string to an integer for the numerator
        den = f[2] - 48;                                            // Convert the third character of the string to an integer for the denominator
         simplify(f);                                               // Simplify the fraction
     }

    friend ostream &operator<<(ostream &os, const Fraction &rhs)    //  Overload the << operator to print the fraction in the form "num/den"
    {
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
    Fraction operator+(const Fraction &rhs) const              // Overload the + operator to add two Fraction objects
    {
        Fraction temp = rhs;                                   // Create a temporary Fraction object initialized with the right-hand side fraction
       
        temp.num = temp.num * this->den;                       // Adjust the numerator and denominator of the temporary fraction to have a common denominator
        temp.den = temp.den * this->den;

        int newnum = this->num * rhs.den;                      // Calculate the new numerator and denominator for the result
        int newden = this->den * rhs.den;

        temp.num = temp.num + newnum;                          // Add the numerators and set the common denominator
        temp.den = newden;

        return simplify(temp);                                 // Simplify the resulting fraction before returning it
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
    Fraction operator-(const Fraction &rhs) const               // Overload the - operator to substract two Fraction objects
    {
        Fraction temp = rhs;                                    // Create a temporary Fraction object initialized with the right-hand side fraction

        temp.num = temp.num * this->den;                        // Adjust the numerator and denominator of the temporary fraction to have a common denominator
        temp.den = temp.den * this->den;

        int newnum = this->num * rhs.den;                       // Calculate the new numerator and denominator for the result
        int newden = this->den * rhs.den;

        temp.num = newnum - temp.num;                           // Subtract the numerators and set the common denominator
        temp.den = newden;

        
        return simplify(temp);                                  // Simplify the resulting fraction before returning it

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
    Fraction operator*(const Fraction &rhs) const              // Overload the * operator to multiply two Fraction objects
    {
        int num = this->num * rhs.num;                         // Multiply the numerators of both fractions
        int den = this->den * rhs.den;                         // Multiply the denominators of both fractions
        return simplify (Fraction(num, den));                  // Simplify the resulting fraction before returning it
        
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
    Fraction operator/(const Fraction &rhs) const         // Overload the / operator to divide two Fraction objects
    {
        int num = this->num * rhs.den;                    // Multiply the numerator of the first fraction by the denominator of the second fraction
        int den = this->den * rhs.num;                    // Multiply the denominator of the first fraction by the numerator of the second fraction
        return simplify (Fraction(num, den));             // Simplify the resulting fraction before returning it
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
    bool operator==(const Fraction &rhs) const                                // Overloaded equality operator to compare two Fraction objects
        {
            bool result = (this->num * rhs.den) == (this->den * rhs.num);     // Compare the cross products of the fractions to check for equality

            if (result)                                                       // Print the comparison result
            {
                cout << "Comparison result: Equal" << endl;
            } 
            else 
            {
                cout << "Comparison result: Not Equal" << endl;
            }
            return result;                                                    // Return the result of the comparison
        }

    void print() const 
    {
        cout << num << "/" << den << endl;                                   // Print the fraction in the form "num/den"
    }
};

int main() 
{
    
    string f1, op, f2;                           // Declare three string variables to store the input fractions and the operator

      while (cin >> f1 >> op >> f2)              // Continuously read input until end-of-file (EOF)
      {
        auto i = f1[0] - '0';                    // Extract numerator and denominator from the first fraction string
        auto j = f1[2] - '0';

        auto x = f2[0] - '0';                    // Extract numerator and denominator from the second fraction string
        auto y = f2[2] - '0';

        Fraction F1(i, j);                       // Create Fraction objects for the two fractions
        Fraction F2(x, y);

        if (op == "+")                           // Perform the operation based on the operator input
            cout << F1 + F2 << endl;
        else if (op == "-")
            cout << F1 - F2 << endl;
        else if (op == "*")
            cout << F1 * F2 << endl;
        else if (op == "/")
            cout << F1 / F2 << endl;
        else if (op == "==")
        {
             if (F1 == F2)                       // Check if the two fractions are equal
                cout << "true" << endl;
             else
                cout << "false" << endl;
        }
    }

    return 0;
}