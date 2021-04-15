
// 算法关键在于lowcost 表示各个顶点进入当前生成树的代价 （整体法）
//            ver 用来存储边
#include<iostream>
using namespace std;
#define N 100000
int main(){
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
    int lowcost[9] = {0,};
    int ver[9] = {0,};
    for (int i = 0; i < 9; i++)
    {
        lowcost[i] = map[0][i];
    }
    for (int i = 1; i < 9; i++)
    {
        int min = N;
        int newNode = 0;
        for (int j = 0; j < 9; j++)
        {
            if( lowcost[j] != 0 && lowcost[j] < min ){
                min = lowcost[j];
                newNode = j;
            }
        }
        lowcost[newNode] = 0;
        for (int j = 0; j < 9; j++)
        {
            if( map[newNode][j] !=0 && map[newNode][j] < lowcost[j] ){
                lowcost[j] = map[newNode][j];
                ver[j] = newNode;
            }
        }
    }
    for (int i = 1; i < 9; i++)
    {
        cout<<'<'<<i<<','<<ver[i]<<'>'<<endl;
    }
    
    
}