// C. Very Easy Task
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// This morning the jury decided to add one more, Very Easy Problem to the problemset of the olympiad. The executive secretary of the Organizing Committee has printed its statement in one copy, and now they need to make n
//  more copies before the start of the olympiad. They have two copiers at his disposal, one of which copies a sheet in x
//  seconds, and the other in y
//  seconds. (It is allowed to use one copier or both at the same time. You can copy not only from the original, but also from the copy.) Help them find out what is the minimum time they need to make n
//  copies of the statement.

// Input
// The program receives three integers n
// , x
// , and y
//  (1≤n≤2⋅108
// , 1≤x,y≤10
// ).

// Output
// Print one integer, the minimum time in seconds required to get n
//  copies.

// Examples
// inputCopy
// 4 1 1
// outputCopy
// 3
// inputCopy
// 5 1 2
// outputCopy
// 4



#include<bits/stdc++.h>
using namespace std;
 
bool ispossible(int a,int b, long long n, long long mid){
	long long x=0;
 
	mid-=min(a,b);
	n--;
	if((mid/a)+(mid/b)>=n){
		return true;
	}
	
	return false;
}
 
int main(){
	long long n;
	int a,b;
	long long ans=-1;
	cin>>n>>a>>b;
	
	long long r = n*(min(a,b));
	long long l=min(a,b);
	while(l<=r){
		long long mid=l+(r-l)/2;
 
		if(ispossible(a,b,n,mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout << ans << endl;
}
