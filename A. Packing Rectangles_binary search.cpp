// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

// A. Packing Rectangles
// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// There are n
//  rectangles of the same size: w
//  in width and h
//  in length. It is required to find a square of the smallest size into which these rectangles can be packed. Rectangles cannot be rotated.


// Input
// The input contains three integers w
// , h
// , n
//  (1≤w,h,n≤109
// ).

// Output
// Output the minimum length of a side of a square, into which the given rectangles can be packed.

// Example
// inputCopy
// 2 3 10
// outputCopy
// 9


#include<bits/stdc++.h>
using namespace std;
 
bool ispossible(long long mid,long long w,long long h,long long n){
	long long x=mid/w;
	long long y=mid/h;
 
	if(x*y>=n){
		return true;
	}
	return false;
}
 
int main(){
	long long w, h, n;
	cin>>w>>h>>n;
	long long ans=-1;
 
	long long l=0;
	long long r=max(max(w,h),n*(min(w,h)));
 
	while(l<=r){
		long long mid=l+(r-l)/2;
 
		if(ispossible(mid,w,h,n)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
}
