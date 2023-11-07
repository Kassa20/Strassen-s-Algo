#include <bits/stdc++.h>
#include <chrono>


using namespace std;

#define N 256

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

void print(string display, int C[][N])
{
    int i, j;
    cout << endl << display << " =>" << endl;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
           	cout << setw(5);
            cout << C[i][j];
        }
        cout << endl;
    }
}


int main()
{

   auto start = chrono::high_resolution_clock::now();

    int A[N][N];
    int B[N][N];
    int C[N][N];
    srand(27);
    fill(A);
    srand(21);
    fill(B);

    //print("Array A", A);

    // print("Array B", B);

    brute(A, B, C);

    //print("Result Array", C);


    // // Calculate the duration in microseconds
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
     auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;


    return 0;
    printf("\n---------C-------\n");
    print(C);

    return 0;
}   