#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    int len = 0;
    cin>>len;
    int tem = 0;
    int output = 0;
    for (int i = 0; i < len; i++)
    {
        /* code */
        srand(tem);
        output = rand()%10000;
        tem = rand();
        cout<<output<<' ';
    }
}