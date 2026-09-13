#include<bits/stdc++.h>
using namespace std;

// to return f(x), when x is given
float func( float x)
{
    // taken function is 2*x^3 - 7*x + 3

    float f = pow(x, 3)*2 - 7*x + 3;
    return f;
}

void secant(float x_1, float x_2, float E)
{
    float n=0, xm, x_0, c;

    // starting points x_1 and x_2
    if(func(x_1)* func(x_2)< 0)
    {
        do{
            // to calculate intermediate value, current root
            x_0 = (x_1*func(x_2) - x_2*func(x_1)) / (func(x_2) - func(x_1));

            // if f(x_0) is zero, then x_0 is the root
            c = func(x_1)*func(x_0);

            // calculated root onujayi x_1 and x_2 er value update kora
            x_1 = x_2;
            x_2 = x_0;

            // update iteration
            n++;

            // if c is zero, then x_0 is the root
            if(c == 0)
                break;
            
            // next root, updated x_1 and x_2 er value niye
            xm = (x_1*func(x_2) - x_2*func(x_1)) / (func(x_2) - func(x_1));
        }
        while(fabs(xm - x_0) >= E); //floating point absolute value

        cout<< "the value of root is: "<< x_0 << endl;
        cout<< "number of iterations: "<< n << endl;
    }
    else 
        cout<< "Cannot find root in given interval\n";  
}

// main function
int main()
{
    float x_1, x_2, E=0.0001;

    cout<< "Enter two initial guesses: ";

    // intervals can be [-3, -2], [0, 1], [1, 2]
    cin>> x_1 >> x_2;

    secant(x_1, x_2, E);
    return 0;
}