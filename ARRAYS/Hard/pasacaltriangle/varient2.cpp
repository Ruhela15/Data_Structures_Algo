#include<bits/stdc++.h>
using namespace std;
void pascaltrinangle(int n){
    long long ans = 1;
    cout<<ans<<" ";
    for(int i = 1;i<n; i++){
        ans = ans*(n-i);
        ans = ans/(i);
        cout<<ans<<" ";
    }
    cout<<endl;
}
int main(){
 int n = 6;   
 pascaltrinangle(n);
 return 0;
}