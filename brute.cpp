#include <bits/stdc++.h>
using namespace std;

#define N 4

void fill(int array[][N])
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            array[i][j] = rand() % 10 + 1;
        }
    }
}

void brute(int A[][N], int B[][N], int C[][N])
{
    int i, j, k;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for(k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print(int C[][N])
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int A[N][N];
    int B[N][N];
    int C[N][N];
    srand(27);
    fill(A);
    srand(21);
    fill(B);

    printf("-------A------\n");
    print(A);

    printf("\n------B-----\n");
    print(B);


    brute(A, B, C);

    printf("\n---------C-------\n");
    print(C);

}   