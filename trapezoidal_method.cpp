#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    // taken function
    return 1/pow(1+x, 2); //limit is from 0 to 6
}

int main(){
    double a=0;
    double b=6;

    // intervals
    double n=6;

    // h(difference between each intervals)
    double h = (b-a)/n;

    double sum=0;

    //f(x) value for lower and upper limit 
    double lower = func(a);
    double upper = func(b);

    // upper and lower value ekbar kore e hobe, majher gula dui bar repeat hobe
    sum = sum+lower;
    sum= sum+upper;

    // majher value gular jonno
    for(int i=1; i<n; i++)
    {
        // je point e ase oi point er limit er jonno
        double xi = a+ i*h;

        // ei point er jonno y=f(x) er man,
        double f_xi = func(xi);

        sum = sum + 2*f_xi; //ei y gula dui bar kore ache 
    }

    // applying trapezoidal formula 
    double I = (h/2)*sum;

    // ek interval e trapezoidal formula te, I= 0.8571
    double I_exact =  0.8571;

    // absolute error
    double E_a = fabs(I_exact- I);

    

    // for showing output
    cout<< "calculated integral value in multiple intervals is: "<< I<< endl<< endl;

    cout<< "exact value of the integral in one interval is: "<< I_exact<< endl<<endl;

    cout<< "the absolute error is: "<< E_a<< endl<<endl;

    return 0;

}