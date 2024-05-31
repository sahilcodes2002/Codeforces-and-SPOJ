//https://codeforces.com/contest/1981/problem/B

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007


int orInRange(int l, int r){
    int xr = l^r;
    int diffBit = 0;
    while(xr>0){
        xr=xr>>1;
        diffBit++;
    }

    int allOnes = (1<<diffBit)-1;

    return r|allOnes;

}


void solve(){
    int n,m;
    cin>>n>>m;

    int left = max(0ll,n-m);
    int right = n+m;

    cout<<orInRange(left,right)<<endl;
}

int32_t main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
