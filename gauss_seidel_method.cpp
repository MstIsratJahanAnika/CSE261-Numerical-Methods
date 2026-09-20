#include<bits/stdc++.h>
using namespace std;

#define N 3
#define E 0.001
// check if diagonal dominance
bool isDiagonallyDominant(float a[N][N])
{
    for(int i=0; i<N; i++) //row-wise 0,1,2
    {
        float diagonal = fabs(a[i][i]);
        float sum = 0; //diagonal element bade baki gular sum er jonno

        for(int j=0; j<N; j++) //column-wise 0, 1, 2
        {
            if(i!=j)//diagonal element bade
                sum = sum + fabs(a[i][j]);
        }

        if(diagonal <=sum)  
            return false; //diagonal dominance er condition mane nai

    }
    return true; //manse
}

// gauss-seidal method
void gaussSeidel(float a[N][N], float b[N])
{
    float x[N]={0,0,0};

    int iteration = 0;

    while(true)
    {
        iteration++;

        // old values for tolerance(E) check
        float oldx[N];

        for(int i=0; i<N; i++)
        {
            oldx[i] = x[i];
        }

        // x calculate
        // x = 1/4*(6-y-z)

        x[0] = (b[0] - a[0][1]*x[1] - a[0][2]*x[2]) / (a[0][0]);

        // new x er value diye y calculate
        x[1] = (b[1] - a[1][0]*x[0] - a[1][2]*x[2]) / (a[1][1]);

        // ager dui ta notun value ekhane boshiye 
        x[2] = (b[2] - a[2][0]*x[0] - a[2][1]*x[1]) / (a[2][2]);

        cout<< "iteration: "<< iteration<<"x: "<< x[0]<< ", y: "<<x[1]<<", z: "<< x[2]<< endl;

        // tolerance check
        if(fabs(x[0] - oldx[0])<E && fabs(x[1]-oldx[1])<E && fabs(x[2]-oldx[2])<E)
            break; //E er moddhe difference ashle oitai solution
    }

    cout<< endl<< "solution: "<< "x: "<<x[0]<<", y: "<< x[1]<< ", z: "<< x[2]<<endl;
}


int main()
{
    // Matrix
    // 4x + y + z = 6
    // x + 6y - 2z = 5
    // -3x + y + 7z = 5

    float A[N][N] =
    {
        {4, 1, 1},
        {1, 6, -2},
        {-3, 1, 7}
    };

    float B[N] = {6, 5, 5};

    if(!isDiagonallyDominant(A))
    {
        cout << "Matrix is not diagonally dominant.";
        return 0;
    }
    gaussSeidel(A, B);

    return 0;
}