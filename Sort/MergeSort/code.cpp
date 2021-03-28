//拆解为小问题

#include<iostream>
using namespace std;


//currentlen arr leftindex
void Msort( int currentlen, int *&arr, int leftindex=0 ){
    if( currentlen == 1 ) return;
    int rightindex = leftindex + currentlen/2;
    Msort( currentlen/2, arr, leftindex );
    Msort( currentlen-currentlen/2, arr, currentlen/2+leftindex );
    int *cparr = new int[currentlen];
    int ci = leftindex;
    int cj = rightindex;
    for(int m=0; m<currentlen; m++) { 
        if( arr[ci] < arr[cj] ){
            cparr[m] = arr[ci];
            ci++;
        }else{
            cparr[m] = arr[cj];
            cj++;
        }
        if( ci==rightindex ){
            m++;
            int remain = currentlen-m;
            for (int i = 0; i < remain; i++)
            {
                cparr[m] = arr[cj+i];
                m++;
            }
        }else if( cj==currentlen+leftindex ){
            m++;
            int remain = currentlen-m;
            for (int i = 0; i < remain; i++)
            {
                cparr[m] = arr[ci+i];
                m++;
            }
            
        }
    }
    for (int i = 0; i < currentlen; i++)
    {
        arr[leftindex+i] = cparr[i];
    }
    delete[] cparr;
    return;
}

void Mergesort( int *&arr, int len ){
    Msort( len, arr );
}

int main(){
    int len = 0;
    cin>>len;
    int *arr = new int[len];
    for( int i=0; i<len; i++){
        cin>>arr[i];
    }
    Mergesort( arr, len );
    cout<<"Here is result:"<<endl;
    for(int i=0; i<len; i++){
        cout<<arr[i]<<' ';
    }
    delete[] arr;
}