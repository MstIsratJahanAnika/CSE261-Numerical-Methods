#include<bits/stdc++.h>
using namespace std;

#define MAX_ITER 100000 // Maximum number of iterations
#define EPSILON 0.001 //tolerance

// The taken function:
// f(x) = -3*x^2 + 3*x + 22
double func(double x)
{
    return (-3*x*x + 3*x + 22);
}

// False Position Method
void false_position(double a, double b)
{
    double c;

    // if a and b in a valid interval, func(a)*func(b) < 0
    if(func(a) * func(b) >= 0)
    {
        cout << "You have not assumed the right a and b values\n";
        return;
    }

    for(int i = 0; i < MAX_ITER; i++)
    {
        // False Position, main formula
        c = (a*func(b) - b*func(a)) / (func(b) - func(a));

        // If c is sufficiently close to the root
        if(abs(func(c)) < EPSILON)
            break;

        // a and b calculated root er shathe koto ta agabe or pichabe 
        if(func(a) * func(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "The value of root is : " << c << endl;
}

// Main function
int main()
{
    double a, b;

    //calculated intervals are [-3, -2] and [3, 4]
    cout << "Enter two initial guesses: ";
    cin >> a >> b;

    false_position(a, b);

    return 0;
}