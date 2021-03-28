
// 整体向量法


#include<iostream>
#define N 1000000
using namespace std;

int main() {
    int map[9][9] = {
        { 0,10, N, N, N,11, N, N, N},
        {10, 0,18, N, N, N,16, N,12},
        { N,18, 0,22, N, N, N, N, 8},
        { N, N,22, 0,20, N, N,16,21},
        { N, N, N,20, 0,26, N, 7, N},
        {11, N, N, N,26, 0,17, N, N},
        { N,16, N, N, N,17, 0,19, N},
        { N, N, N,16, 7, N,19, 0, N},
        { N,12, 8,21, N, N, N, N, 0}
    };
    int D[9][9];
    int P[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            P[i][j] = j;
            D[i][j] = map[i][j];
        }
    }
    for (int i = 0; i < 9; i++){
        for(int j=0; j<9; j++){
            for (int m = 0; m < 9; m++){
                if(D[i][j] > D[i][m]+D[m][j]){
                    D[i][j] = D[j][i] = D[i][m]+D[m][j];
                    P[i][j] = P[j][i] = m;
                }
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<D[i][j]<<' ';
        }
        cout<<endl;
    }
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         cout<<P[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
}