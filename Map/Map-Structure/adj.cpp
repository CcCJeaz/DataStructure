#include<iostream>
using namespace std;
//十字链表
struct EdgeNode
{
    int start;
    int pointed;
    EdgeNode *slink;
    EdgeNode *plink;
    EdgeNode(){
        slink = nullptr;
        plink = nullptr;
        start = pointed = -1;
    }
};
struct AdjVertex
{
    /* data */
    int data;
    EdgeNode *firstout;
    EdgeNode *firstin;
    AdjVertex(){
        data = 0;
        firstin = nullptr;
        firstout = nullptr;
    }
};
struct AdjList
{
    int verNum;
    int *visit;
    AdjVertex *list;
    AdjList(int len);
    void Print(){
        for (int i = 0; i < verNum; i++)
        {
            EdgeNode *tem = list[i].firstout;
            while( tem ){
                cout<<'<'<<tem->start<<','<<tem->pointed<<'>'<<endl;
                tem = tem->slink;
            }
        }
    }
    void Print(int i){
        cout<<"ver:"<<i<<" date:"<<list[i].data;
    }
    void dfs(int current){
        if( visit[current] != 1){
            visit[current]=1;
            EdgeNode *tem = list[current].firstout;
        }
    }
};

AdjList::AdjList ( int len ) {
    verNum = len;
    list = new AdjVertex[len];
    visit = new int[len];
    for (int i = 0; i < len; i++)
    {
        cin>>list[i].data;
    }
    int l = 0;
    int r = 0;
    int tem = 0;
    cin>>l>>r;
    while (l >= 0 && r >= 0 && l-r != 0 && l<verNum && r<verNum)
    {

        EdgeNode *m = list[l].firstout;
        list[l].firstout = new EdgeNode;
        list[l].firstout->start = l;
        list[l].firstout->pointed = r;
        list[l].firstout->slink = m;
        m = list[r].firstin;
        list[r].firstin = list[l].firstout;
        list[r].firstin->plink = m;
        cin>>l>>r;
    }
}
int main(){
    AdjList map( 3 );
    map.Print();
}
