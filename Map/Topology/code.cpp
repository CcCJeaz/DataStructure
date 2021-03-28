#include<iostream>
#include<vector>
#include<deque>
#include<forward_list>
#include<stack>
using namespace std;

class adjver{
  private:
    int in;
    forward_list<int> pointed;
  public:
    adjver(){
        this->in = 0;
    }
    void edgeInsert(int i){
        this->pointed.push_front(i);
    }
};
int main(){
    vector<adjver> myMap;
    int point = 0;
    int pointed = 0;
    int i = myMap.capacity();
    cout<<i;
}