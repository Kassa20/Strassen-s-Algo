#include <bits/stdc++.h>
#include <chrono>


using namespace std;

#define N 2048


int nextpowerof2(int k){
    return pow(2, int(ceil(log2(k))));
}

void fill(vector<vector<int> >&vector)
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            vector[i][j] = rand() % 10 + 1;
        }
    }
}

vector<vector<int>> brute(vector<vector<int> >&A, vector<vector<int> >&B)
{

    int test = N & (N - 1);
    int i, j, k;
    int sz;
    if(test != 0)
    {
        cout << "padding..." << endl;
        sz = nextpowerof2(N);

        vector<vector<int>> res(sz, vector<int>(sz, 0));
        vector<vector<int>> newA(sz, vector<int>(sz, 0));
        vector<vector<int>> newB(sz, vector<int>(sz, 0));

        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                newA[i][j] = A[i][j];
                newB[i][j] = B[i][j];
            }
        }

        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                for(k = 0; k < N; k++)
                {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return res;
    }


    vector<vector<int>> res(N, vector<int>(N, 0));

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            for(k = 0; k < N; k++)
            {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return res;
}

void print(string display, int C[][N])
{
    int i, j;
    cout << endl << display << " =>" << endl;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%2d ", C[i][j]);
        }
        cout << endl;
    }
}


int main()
{

   auto start = chrono::high_resolution_clock::now();

    vector<vector<int>> A(N, vector<int>(N, 0));
    vector<vector<int>> B(N, vector<int>(N, 0));
    vector<vector<int>> C(N, vector<int>(N, 0));


    srand(27);
    fill(A);
    srand(21);
    fill(B);


    C = brute(A, B);

    // // Calculate the duration in microseconds
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<std::chrono::minutes>(end - start);

    std::cout << "Execution time: " << duration.count() << " minutes" << std::endl;

    return 0;
}   