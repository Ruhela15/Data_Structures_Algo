#include<iostream>
#include<queue>
#include<stack>
using namespace std;
bool valid (string s){
  stack<int>st;
  for(auto it:s){
    if(it=='('||it=='{'||it=='[') st.push(it);
    else{
        if(st.size()==0) return false;
        char ch = st.top();
        st.pop();
        if((it==')' && ch=='(') || (it==']' && ch=='[' )||(it=='}'&& ch=='{'))continue;
        else return false;
    }
  }return st.empty();
}
int main(){

    string s="()[{}()]";
    if( valid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}