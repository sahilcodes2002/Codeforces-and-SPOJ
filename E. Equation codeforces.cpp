// E. Equation
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Find a number x
//  such that x2+x−−√=c
// .

// Input
// The input contains one real number C
//  (1.0≤c≤1010
// ).

// Output
// Print one number, the required x
// . The answer will be considered correct if the relative or absolute error is not more than 10−6
// .

// Examples
// inputCopy
// 2.0
// outputCopy
// 1.0
// inputCopy
// 15.6
// outputCopy
// 3.698232168829691


#include<bits/stdc++.h>

using namespace std;

bool ispossible(double c, double mid){
    double temp=(double)mid*mid+(double)sqrt(mid);
    if(temp<=c){
        return true;
    }
    return false;
}
int main(){
    double c;
    cin>>c;

    double l=0.0;
    double r=sqrt(c);

    while(r-l>=1e-6){
        double mid=l+(r-l)/2;
        if(ispossible(c,mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<fixed<<setprecision(20)<<l<<endl;
    return 0;
}
