#include <bits/stdc++.h>
using namespace std;

// This function returns the value of f(x,y)
// Given differential equation:
// dy/dx = ln(1 + y^2) + x*cos(y)
float func(float x, float y)
{
    float f = log(1 + y * y) + x * cos(y);

    return f;
}

// RK4 function
void rungeKutta(float x, float y, float h, int n)
{
    // Repeat the calculation n times
    // Each repetition calculates the next y value
    for(int i = 0; i < n; i++)
    {
        // Calculate first slope
        // k1 = f(x, y)
        float k1 = func(x, y);

        // Calculate second slope
        // Here x and y are moved half of one step
        // k1 is used to estimate the new y
        float k2 = func(x + h / 2,
                        y + (h * k1) / 2);

        // Calculate third slope
        // Again we move half a step
        // But this time k2 is used
        float k3 = func(x + h / 2,
                        y + (h * k2) / 2);

        // Calculate fourth slope
        // Here we move one full step
        // k3 is used to estimate y at the end
        float k4 = func(x + h,
                        y + h * k3);

        // Calculate the new value of y
        // RK4 weighted average:
        // k1 + 2*k2 + 2*k3 + k4
        y = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);

        // Move x forward by one step
        x = x + h;

        // Display the result after each step
        cout << "Step " << i + 1 << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "------------------------" << endl;
    }
}

int main()
{
    // Initial value of x
    float x = 0;

    // Initial value of y
    // Given y(0) = 1
    float y = 1;

    // Step size
    float h = 0.1;

    // Number of steps
    int n = 2;

    // Call the RK4 function
    rungeKutta(x, y, h, n);

    return 0;
}