#include<bits/stdc++.h>
using namespace std;
int gcdis(int a, int b){
    if(b==0){
        return a;
    }
    return gcdis(b,a%b);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcdis(a,b)<<endl;
}
