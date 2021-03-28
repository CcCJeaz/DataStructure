//优化方案：
//三段取中轴 或 九段？
//尽可能使用迭代
//排较小数组时直接使用插入
//去除不必要的交换
#include<iostream>
using namespace std;
class Quicksort
{
private:
    int *arr;
    int originlen;

public:
    Quicksort( int len );
    ~Quicksort();
    void Print();
public:
    int partition(int l, int r);
    void swap( int l, int r );
    void areaSort( int low, int high);
};
Quicksort::Quicksort( int len ){
    this->originlen = len;
    this->arr = new int[len+1]{-10000, };
    for (int i = 1; i < len+1; i++)
    {
        cin>>this->arr[i];
    }
}
Quicksort::~Quicksort(){
    delete[] arr;
}
void Quicksort::Print(){
    for (int i = 1; i < this->originlen+1; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void Quicksort::swap( int l, int r ){
    int middle = (l + r)/2;
    int target = 0;
    if( (arr[l]-arr[r])*(arr[l]-arr[middle]) <= 0 ) target = l;
    if( (arr[r]-arr[l])*(arr[r]-arr[middle]) <= 0 ) target = r;
    if( (arr[middle]-arr[r])*(arr[middle]-arr[l]) <= 0 ) target = middle;
    int tem = arr[target];
    arr[target] = arr[l];
    arr[l] = tem;
}
int Quicksort::partition( int l, int r ){
    int axis = arr[l];
    int current = l;
    while (l < r)
    {
        if(current==l){
            if( arr[r] < axis ){
                arr[l] = arr[r];
                current = r;
                l++;
            }else{
                r--;
            }
        }else{
            if (arr[l] > axis)
            {
                arr[r] = arr[l];
                current = l;
                r--;
            }else{
                l++;
            }
        }
    }
    arr[current] = axis;
    return current;
}
void Quicksort::areaSort(int low, int high){
    if( high-low <= 7 ){
        //直接排
        int minid = 0;
        for (int i = 0; i < high-low+1; i++)
        {
            minid = i+low;
            for (int j = i; j < high-low+1; j++)
            {
                if( arr[minid]>arr[low+j] ){
                    minid = low+j;
                }
            }
            int tem = arr[minid];
            arr[minid] = arr[low+i];
            arr[low+i] = tem;
        }
        return;
    }
    int axis = 0;
    swap(low, high);
    axis = partition(low, high);
    areaSort(low, axis-1);
    areaSort(axis+1, high);
}
int main(){
    Quicksort contain(10000);
    contain.areaSort(1, 10000);
    contain.Print();
}