#include<bits/stdc++.h>
using namespace std;


#define E 0.01
#define N 3

// diagonal dominance check
bool isDiagonallyDominant(float A[N][N]) //accept 3by3 matrix
{
    for(int i=0; i<N; i++) //row-wise diagonal element e kaj kore
    {
        // diagonal element e row and column number same hobe
        float diagonal = fabs(A[i][i]);
        float sum = 0; //sum of non-diagonal elements

        for(int j=0; j<N; j++) //each column e kaj kore
        {
            if(i != j) //diagonal element bade baki elements, row and column not equal
                sum = sum + fabs(A[i][j]); //row-wise non-diagonal elements sum e add hobe
        }
        if(diagonal <= sum)
            return false; //diagonal sum theke choto hole, not diagonal matrix
    }
    return true;
}

// gauss-jacobi
void gaussJacobi(float A[N][N], float B[N])
{
    float x[N] = {0, 0, 0}; 
    float newX[N];

    int iteration =0;
    while(true)
    {
        iteration++;

        // calculate new values using old values 
        for(int i =0; i<N; i++)
        {
            float sum =0; 

            for(int j=0; j<N; j++){
                if(i != j){ //ignoring diagonal element, sheta formula onujayi equation er onno pashe e jabe 
                    sum = sum + A[i][j]* x[j]; //x er jonno y and z er co-efficient er sum, same for y adn z
                }
            }

            newX[i] = (B[i] - sum)/ A[i][i]; //{(1/A[i][i])*(B[i]-sum)};
        }

        cout<< "iteration: "<< iteration<< ": ";
        cout<< "x = "<< newX[0]
          << ", y = "<<newX[1]
          <<", z = "<< newX[2]<< endl<<endl;


        // tolerance check 
        if(fabs(newX[0]-x[0])< E && fabs(newX[1]-x[1])< E && fabs(newX[2]-x[2])< E)
        {
            break;
        }

        // update all values after calculating everything 
        for(int i=0; i<N; i++)
            x[i] = newX[i];
    }

    cout<<endl<< "solution: "<< "x: "<< newX[0]<< "y: "<< newX[1]<< "z: "<< newX[2]<<endl;
}

int main()
{
    /**
     * matrix
     * 4x+y-z = 6
     * x+6y-2z = 5
     * -3x-y+7z = 5
     */

    // matrix form e kora
    float A[N][N]={
        {4, 1, 1},
        {1, 6, -2},
        {-3, 1, 7}
    };

    float B[N]={6, 5, 5};

    if(!isDiagonallyDominant(A))
    {
        cout<<"matrix is not diagonally dominant."<<endl;
        return 0;
    }
    gaussJacobi(A, B);
    return 0;
}
