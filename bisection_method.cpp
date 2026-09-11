#include<bits/stdc++.h>
using namespace std;

#define EPSILON 0.01 //error tolerance in solution
/*
    using bisection method, solution of the function: f(x) = x*x + sin(x) - 3;
    calculated intervals: [-2, -1] and [1, 2] between -5 to 5
*/

// calculation function, bisection function e inplement hobe
double funct(double x){
    return (x*x + sin(x) - 3);
}


void bisection(double a, double b){
    if(funct(a)* funct(b)>=0) //condition invalid, 0 er boro hoa jabe na
    {
        cout << "You have not assumed right a and b\n";
        return;
    }


        double c = a; //initialize result
        while ((b - a) >= EPSILON)
        {
            // Find middle point
            c = (a + b) / 2;

            // Check if middle point is root
            if (funct(c) == 0.0)
                break;

            // Decide the side to repeat the steps
            else if (funct(c) * funct(a) < 0)
                b = c;
            else
                a = c;
        }
        cout << "The value of the root is : " << c << endl;
}


int main(){
    //give initail values 
    double a, b;
    // constant na rekhe, user input nibo
    // condition match kore input values nite hobe
    cout << "Enter two initial guesses: "<< endl;

    cin>>a>>b;
    bisection(a, b);
    return 0;
}