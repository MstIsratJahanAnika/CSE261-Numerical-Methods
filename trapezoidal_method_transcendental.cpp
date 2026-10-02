#include <bits/stdc++.h>
using namespace std;

// Function to calculate f(x)
double func(double x)
{
    // Given function: f(x) = sin^3(1 + x)
    return pow(sin(1 + x), 3);
}

int main()
{
    // Lower and upper limits
    double a = 0;
    double b = 6;

    // Number of intervals
    int n = 6;

    // Calculate the width of each interval
    double h = (b - a) / n;

    // Variable to store the summation
    double sum = 0;

    // Calculate f(a) and f(b)
    double lower = func(a);
    double upper = func(b);

    // Lower and upper values occur only once
    sum = sum + lower;
    sum = sum + upper;

    // Calculate the middle points
    // Middle values occur twice in the trapezoidal formula
    for(int i = 1; i < n; i++)
    {
        // Calculate the current x value
        double xi = a + i * h;

        // Calculate f(xi)
        double f_xi = func(xi);

        // Middle values are multiplied by 2
        sum = sum + 2 * f_xi;
    }

    // Apply Composite Trapezoidal Rule
    double I = (h / 2) * sum;

    // Calculate the exact value mathematically
    //
    // Integral of sin^3(1+x) dx
    // = -cos(1+x) + cos^3(1+x)/3
    //
    // Exact value = F(b) - F(a)

    double F_b = -cos(1 + b) + pow(cos(1 + b), 3) / 3;
    double F_a = -cos(1 + a) + pow(cos(1 + a), 3) / 3;

    double I_exact = F_b - F_a;

    // Calculate absolute error
    double E_a = fabs(I_exact - I);

    // Display the results
    cout << fixed << setprecision(6);

    cout << "Number of intervals: " << n << endl;

    cout << "Calculated integral using Trapezoidal Rule: "
         << I << endl;

    cout << "Exact value of the integral: "
         << I_exact << endl;

    cout << "Absolute error: "
         << E_a << endl;

    return 0;
}