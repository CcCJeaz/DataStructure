#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<deque>
#include<vector>
#include<string.h>
#include<map>
using namespace std;

struct ToReverse{
  deque<string> result;
private:
  deque<string> origin;
  stack<string> signStack;
  map<string, int> originTable;
  map<string, int> stackTable;
private:
  void setSignToResult(){//将一个字符加入结果
    result.emplace_back(signStack.top());
    signStack.pop();
  }
  void setNumToResult(){//将一整个数字加入结果
    string num = "";
    char current = origin.front()[0];
    while( isdigit(current) || current == '.'  ){
      num += origin.front();
      origin.pop_front();
      if( origin.empty() == true ){
        break;
      }else{
        current = origin.front()[0];
      }
    }
    result.emplace_back(num);
  }
  bool isSignStackShouldPop(){//是否应该弹出符号栈
    
    if( signStack.empty() == true ){
      return false;
    }
    int signInStack = stackTable[signStack.top()];
    int signInOrigin = originTable[origin.front()];
    if( signInOrigin <= signInStack ){
      return true;
    }else{
      return false;
    }
  }
  void popSignStack(){
    while( signStack.empty()==false && signStack.top() != "("){
      setSignToResult();
    }
    if(origin.empty() == true){
      return;
    }
    if( origin.front() == ")" ){
      signStack.pop();
    }else{
      signStack.emplace(origin.front());
    }
    origin.pop_front();
  }
  void getResult(){
    int judge = 0;
    while(origin.empty() != true){
      char current = origin.front()[0];
      if(isdigit(current)){
        setNumToResult();
      }else{
        if( origin.front() == "-" && result.empty()==true && judge == 0 ){
          origin.emplace_front("0");
          judge++;
          continue;
        }else if(origin.front() == "-" && signStack.empty()==false && signStack.top()=="(" && judge == 0){
          origin.emplace_front("0");
          judge++;
          continue;
        }
        if( origin.front() == "-" ){
          judge = 0;
        }
        if(isSignStackShouldPop()){
          popSignStack();
        }else{
          if(origin.front() != "0"){
            signStack.emplace(origin.front());
            origin.pop_front();
          }
        }
      }
    }
    if( signStack.empty() != true ){
      popSignStack();
    }
  }
public:
  ToReverse(string userInput){
    for( int i=0, len=userInput.length(); i<len; i++){
      origin.emplace_back(userInput.substr(i, 1));
    }
    map<string, int> tem1 { 
      {"-", 1},
      {"+", 1},
      {"*", 2},
      {"/", 2},
      {"(", 3},
      {")", 0}
    };
    map<string, int> tem2 { 
      {"-", 1},
      {"+", 1},
      {"*", 2},
      {"/", 2},
      {"(", 0},
      {")", 0}
    };
    originTable = tem1;
    stackTable = tem2;
    getResult();
  }

};

struct CalculateResult{
public:
  double result;
private:
  deque<string> origin;
  stack<double> numStack;
  void calculate(){
    double cresult = 0;
    double i = numStack.top();
    numStack.pop();
    double j = numStack.top();
    numStack.pop();
    switch ( origin.front()[0] ){
      case '+':
        cresult = i + j;
        break;
      case '-':
        cresult = j - i;
        break;
      case '*':
        cresult = j * i;
        break;
      case '/':
        cresult = j / i;
        break;
    }
    numStack.emplace(cresult);
  }
  void dealOrigin(){
    while( origin.empty()==false ){
      if( isdigit(origin.front()[0]) ){
        numStack.emplace(stod(origin.front()));
      }else{
        calculate();
      }
      origin.pop_front();
    }
    result = numStack.top();
    numStack.pop();
  }
public:
  CalculateResult(deque<string> target){
    origin = target;
    dealOrigin();
  }
};


int main (){
  string target;
  cin>>target;
  ToReverse getReverse(target);
  CalculateResult getResult(getReverse.result);
  cout<<getResult.result;
}