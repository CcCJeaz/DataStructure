//堆顶总为最大

#include<iostream>
#include<cmath>
using namespace std;

class HeapSequence
{
private:
    /* data */
    int *arr;
    int originLen;
    int currentLen;
    int depth;
public:
    HeapSequence( int len );
    ~HeapSequence();
public:
    int HeapAdjust( int leftChild );
    void HeapSort();
    void Print(){
        for (int i = 1; i < this->originLen+1; i++)
        {
            cout<<arr[i]<<", ";
        }
    }
};

HeapSequence::HeapSequence( int len )
{
    this->originLen = this->currentLen = len;
    this->depth = (int)(log(len)/log(2))+1;
    this->arr = new int[len+1];
    for (int i = 1; i < len+1; i++)
    {
        cin>>this->arr[i];
    }
}

HeapSequence::~HeapSequence() {
    delete[] arr;
}
void HeapSequence::HeapSort() {
    //第一次堆处理
    for(int i=depth; i != 1; i--){
        int index = pow(2, i-1);
        int endI = 0;
        if( i==depth ){
            endI = this->originLen;
        }else{
            endI = pow(2, i)-1;
        }
        for( ; index <= endI; index += 2){
            this->HeapAdjust( index );
        }
    }
    //对堆重新调整
    int tem = 0;
    for (int i = 0; i < this->originLen; i++)
    {
        tem = arr[1];
        arr[1] = arr[this->currentLen];
        arr[this->currentLen] = tem;
        this->currentLen--;
        int parent = 1;
        //while直到符合堆
        while ((arr[parent] < arr[parent*2] || arr[parent] < arr[parent*2+1]) && parent*2 < currentLen)
        {
            parent = this->HeapAdjust( parent*2 );
        }
    }
    
}
int HeapSequence::HeapAdjust( int leftChild ) {//只处理一个三节点的二叉树
    int tem = 0;
    int maxid = 0;
    if( leftChild+1 > this->currentLen){//没有右孩子
        maxid = leftChild/2;
        if(arr[leftChild] > arr[leftChild/2]){
            maxid = leftChild;
            tem = arr[leftChild];
            arr[leftChild] = arr[leftChild/2];
            arr[leftChild/2] = tem;
        }
    }else{                              //有右孩子
        int rightChild = leftChild+1;
        maxid = leftChild/2;
        int parent = maxid;
        if(arr[maxid] < arr[leftChild]) 
            maxid = leftChild;
        if(arr[maxid] < arr[rightChild])
            maxid = rightChild;
        tem = arr[maxid];
        arr[maxid] = arr[parent];
        arr[parent] = tem;
    }
    return maxid;
}
int main(){
    HeapSequence contain( 10 );//len可调
    contain.HeapSort();
    contain.Print();
}