// B. Ropes
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// There are n
//  ropes, you need to cut k
//  pieces of the same length from them. Find the maximum length of pieces you can get.

// Input
// The first line contains two integers n
//  and k
//  (1≤n,k≤10000
// ). Next n
//  lines contain one number each, the length of the rope ai
//  (1≤ai≤107
// ).

// Output
// Output one real number, maximum length of pieces you can get. The answer will be considered correct if the relative or absolute error does not exceed 10−6
// .

// Example
// inputCopy
// 4 11
// 802
// 743
// 457
// 539
// outputCopy
// 200.5



#include<bits/stdc++.h>
using namespace std;
 
bool ispossible(vector<double>&ropes,int k,int n,double mid){
	long long x=0;
 
	for(int i=0;i<n;i++){
		x += floor(ropes[i] / mid);
		if(x>=k){
		return true;
		}
	}
	
	return false;
}
 
int main(){
	long long n,k;
	cin>>n>>k;
 
	double ans=-1;
	vector<double>ropes(n);
	for(int i=0;i<n;i++){
		cin>>ropes[i];
	}
 
	
	double r = 1e7+1;
	double l=0.0;
	while(r-l>=1e-6){
		double mid=l+(r-l)/2;
 
		if(ispossible(ropes , k , n ,mid)){
			ans=mid;
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout << fixed << setprecision(20) << ans << endl;
}
