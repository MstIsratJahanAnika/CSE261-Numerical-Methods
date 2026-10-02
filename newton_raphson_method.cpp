#include<bits/stdc++.h>
using namespace std;

// error tolerance 
#define EPSILON 0.001

// function is: f(x) = sin(x) + e^(-x) - 1

double func(double x){
    return (sin(x) + exp(-x) - 1);
}

// finding derivative of the function 
double deriv_of_func(double x)
{
    return (cos(x) - exp(-x));
}

// function to initial guess of root 
double initial_guess(double a, double b)
{
    if(func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return -1; //error bujhate, invalid input
    }   
    double c = (a+b)/2; // initialize result
    return c;
}


// function to find the root of func. in newton raphson
void newton_raphson(double x)
{
    // initializing h with the value of function, old value of h
    double h = func(x) / deriv_of_func(x);

    while (abs(h)>= EPSILON) //absolute value (modulus value), tolerance theke boro or equal hole
    {
        // updating h with the value of function, next iteration er jonno, new value of h
        h = func(x) / deriv_of_func(x);

        // main formula: x(i+1) = x(i) - {f(x) / f'(x)}
        x = x - h;
    }

    cout << "The value of root is : " << x << endl;
}

// main function
int main()
{
    double a, b, c; // initial value

    cout << "Enter two initial guesses: " << endl;
    
    // possible intevals can be [1, 3] and [2, 4]
    cin >> a >> b;

    c = initial_guess(a, b); // assuming a simple interval for initial guess

    if(c != -1)
    {
        newton_raphson(c);
    }
    return 0;
}