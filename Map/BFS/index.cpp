#include<iostream>
#include<deque>
#include<vector>
using namespace std;

struct Node {
  vector<Node> child;
  int data;
  Node(){
    child.clear();
    data = -1;
  }
};

struct Tree{
  Node head;
private:
  deque<Node> tool;
public:
  void createTree( Node &current ){
    Node left;
    Node right;
    cin>>current.data;
    if( current.data != -1 ){
      current.child.emplace_back(left);
      current.child.emplace_back(right);
      createTree( current.child[0] );
      createTree( current.child[1] );
    }
    return;
  }

  void BFS(){
    tool.emplace_back(head);
    while( tool.size() != 0 ){
      cout<<tool[0].data;
      if( tool[0].child[0].data != -1 ){
        tool.emplace_back( tool[0].child[0] );
      }
      if( tool[0].child[1].data != -1 ){
        tool.emplace_back( tool[0].child[1] );
      }
      tool.pop_front();
    }
  }
};

int main(){
  Tree test;
  test.createTree(test.head);
  test.BFS();
}