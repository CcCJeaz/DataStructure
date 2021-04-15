
// 重点 parent记录每个节点所属的生成树
// 全局观进行取边
#include<iostream>
using namespace std;

struct Edge{
    int i;
    int j;
    int weight;
};
int Find(int *parent, int iver){
    while(parent[iver] != 0) {
        iver = parent[iver];
    }
    return iver;
}
int main (){
    Edge edges[15] = {
        {4,7, 7},
        {2,8, 8},
        {0,1,10},
        {0,5,11},
        {1,8,12},
        {3,7,16},
        {1,6,16},
        {5,6,17},
        {1,2,18},
        {6,7,19},
        {3,4,20},
        {3,8,21},
        {2,3,22},
        {3,6,24},
        {4,5,26}
    };
    int parent[9] = {0,};
    int path[9] = {0,};
    for (int i = 0; i < 9; i++)
    {
        path[i] = -1;
    }
    
    for (int i = 0; i < 15; i++)
    {
        int iJudge = Find( parent, edges[i].i );
        int jJudge = Find( parent, edges[i].j );
        if( iJudge != jJudge ){
            parent[iJudge] = jJudge;
            
            if(path[edges[i].i] == -1){
                path[edges[i].i] = edges[i].j;
            }else{
                path[edges[i].j] = edges[i].i;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        cout<<'<'<<i<<','<<path[i]<<'>'<<endl;
    }
}