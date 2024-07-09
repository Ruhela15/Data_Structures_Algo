#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data ;
  Node*left;
  Node*right;
  Node(int data1){
    data = data1;
    left=right=nullptr;
  }
};

int main(){
  Node*root = new Node (1);
}