// A. Get together
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// There are n
//  people on a straight line, they need to gather at one point. Each person knows his current position xi
//  and his speed vi
// . Help them find out in what minimum time they can gather at one point.

// Input
// The first line contains integer n
//  (1≤n≤105
// ), next n
//  lines contain pairs of integers xi
//  and vi
//  (−109≤xi≤109
// , 1≤vi≤109
// ).

// Output
// Print one number, the minimum time it takes people to gather at one point. The answer will be considered correct if the relative or absolute error does not exceed 10−6
// .

// Example
// inputCopy
// 5
// -1 5
// 10 3
// 4 2
// 7 10
// 8 1
// outputCopy
// 1.5


#include<bits/stdc++.h>
using namespace std;
 
bool ispossible(vector<long long> &posi, vector<long long> &speed, double mid, int n) {
    double minright = 1e9;
    double maxleft = -1e9;  // Corrected initialization here
    for (int i = 0; i < n; i++) {
        double l = (double)(posi[i]) - mid * (double)(speed[i]);
        double r = (double)(posi[i]) + mid * (double)(speed[i]);
        if (l > minright || r < maxleft) {
            return false;
        }
        minright = min(minright, r);
        maxleft = max(maxleft, l);
    }
 
    return true;
}
 
int main(){
    int n;
    cin>>n;
 
    vector<long long> posi(n);
    vector<long long> speed(n);
    long long mini=LLONG_MAX;
    long long maxi=LLONG_MIN;
    long long minispeed=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>posi[i]>>speed[i];
        mini=min(posi[i],mini);
        maxi=max(posi[i],maxi);
        minispeed=min(speed[i],minispeed);
    }
 
    double l=-1;
    double r=(double)(maxi-mini)/(double)minispeed;
 
    
 
    while(r-l>10e-7){
        double mid=l+(r-l)/2;
        //cout<<mid<<endl;
        if(ispossible(posi,speed,mid,n)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
 
    cout<<setprecision(20)<<r<<endl;
 
    return 0;
}
