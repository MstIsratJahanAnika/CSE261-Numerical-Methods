#include <iostream>
#include <cmath>

using namespace std;

// Function f(x) = sin(x) + 3*x^2
float func(float x)
{
    float f = sin(x) + 3 * x * x;

    return f;
}

int main()
{
    // Lower limit
    float a = 2;

    // Upper limit
    float b = 6;

    // Number of subintervals
    int n = 6;

    // Calculate step size
    float h = (b - a) / n;

    // This will store the final answer
    float sum = 0;

    // Display step size
    cout << "Step size h = " << h << endl;

    // Display x and f(x) values
    cout << "\n x\t\tf(x)" << endl;

    for(int i = 0; i <= n; i++)
    {
        // Calculate current x value
        float x = a + i * h;

        // Calculate f(x)
        float fx = func(x);

        cout << x << "\t\t" << fx << endl;
    }

    // Simpson's 3/8 calculation

    // First endpoint: f(x0)
    sum = func(a);

    // Last endpoint: f(xn)
    sum = sum + func(b);

    // Calculate the middle terms
    for(int i = 1; i < n; i++)
    {
        float x = a + i * h;

        // If i is NOT a multiple of 3,
        // its coefficient is 3
        if(i % 3 != 0)
        {
            sum = sum + 3 * func(x);
        }

        // If i is a multiple of 3,
        // its coefficient is 2
        else
        {
            sum = sum + 2 * func(x);
        }
    }

    // Final Simpson's 3/8 formula
    float result = (3 * h / 8) * sum;

    cout << "\nIntegral = " << result << endl;

    return 0;
}