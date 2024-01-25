// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G
// G. Coprime Segment
// time limit per test1 second
// memory limit per test1024 megabytes
// inputstandard input
// outputstandard output
// Given an array of n
//  integers ai
// . Let's say that a segment of this array a[l..r]
//  (1≤l≤r≤n
// ) is good if the GCD of all numbers on this segment is 1
// . Your task is to find the shortest good segment.

// Input
// The first line contains an integer n
//  (1≤n≤105
// ). The second line contains integers ai
//  (1≤ai≤1018
// ).

// Output
// Print one number, the minimum length of a good segment. If there is no good segment, print −1
// .

// Example
// inputCopy
// 5
// 4 6 9 3 6
// outputCopy
// 3


#include<bits/stdc++.h>
using namespace std;

long long  gcd(long long a,long long b){
	while(b){
		a=a%b;
		swap(a,b);
	}
	return a;
} 

int main(){
	int n;
	cin>>n;

	std::vector<long long> arr(n);

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long d=0;
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		d=gcd(d,arr[i]);
		
		if(d==1){
			int j=i;
			long long x=0;
			while(x!=1){
				d=x;
				x=gcd(x,arr[j]);
				j--;
			}
			ans=min(ans,i-j);
		}
	}
	if(ans==INT_MAX){
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}
