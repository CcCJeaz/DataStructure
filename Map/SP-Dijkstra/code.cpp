// weight 当前各元素离v0的距离
// 一步一步的找 每次找weight里面最小的边 然后每次找到一个边就马上重新更新weight
//              result用来记录是否被标记

#include<iostream>
#define N 1000000
using namespace std;

int main (){
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
    int result[9] = {0, };
    int weight[9] = {0, };
    int path[9] = {0, };
    result[0] = 1;
    for (int i = 1; i < 9; i++)
    {
        weight[i] = map[0][i];
    }
    for (int i = 1; i < 9; i++)
    {
        int min = N;
        int selected = 0;
        for(int j=0; j<9; j++){
            if (result[j] == 0 && weight[j] < min)
            {
                min = weight[j];
                selected = j;
            }
        }
        result[selected] = 1;
        for (int j = 0; j < 9; j++)
        {
            if( result[j]==0 && map[selected][j]+weight[selected] < weight[j]){
                weight[j] = map[selected][j]+weight[selected];
                path[j] = selected;
            } 
        }
    }
    for (int i = 0; i < 9; i++)
    {
        cout<<path[i]<<' ';
    }
    
}