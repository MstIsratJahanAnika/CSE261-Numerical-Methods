#include<bits/stdc++.h>
using namespace std;

// taken function f(x) = sin(x)-2x+3
float f(float x)
{
    return sin(x) - 2*x + 3;
}

// function of x
float func_x(float x)
{
    return (sin(x) + 3)/2;
}

float initial_guess(float x_0, float x_1)
{
    if(f(x_0) * f(x_1) >= 0)
    {
        cout<<"Incorrect initial guesses"<<endl;
        return -1;
    }
    return (x_0 + x_1)/2;  
    
}


// iteration method
void iteration_method(float x_0, float E)
{
    float x_1;

    int n=0; //iteration number

    do{
        x_1 = func_x(x_0); // calculate next root

        if(fabs(x_1 -x_0)< E) //tolerance theke jeno kom hoy, iteration stop hoar condition eta, echara true thakbe
            break;
        
        // update x_0
        x_0 = x_1;
        n++; //next iteration

    } while(true);

    cout << "Root is: "<< x_1<< endl;
}

//main function 
int main()
{
    float x_0, x_1, E=0.0001;

    cout << "enter two initial guesses: ";

    // interval: [1, 2]
    cin >> x_0 >> x_1;

    // initial root guess
    float initial_root = initial_guess(x_0, x_1);

    if(initial_root == -1)
        return 0;   

    // initial root main function a pass
    iteration_method(initial_root, E);
    return 0;
}