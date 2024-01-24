// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/D

// D. Number of Segments with Big Sum
// time limit per test1 second
// memory limit per test1024 megabytes
// inputstandard input
// outputstandard output
// Given an array of n
//  integers ai
// . Let's say that the segment of this array a[l..r]
//  (1≤l≤r≤n
// ) is good if the sum of elements on this segment is at least s
// . Your task is to find the number of good segments.

// Input
// The first line contains integers n
//  and s
//  (1≤n≤105
// , 1≤s≤1018
// ). The second line contains integers ai
//  (1≤ai≤109
// ).

// Output
// Print one integer, the number of good segments.

// Example
// inputCopy
// 7 20
// 2 6 4 3 6 8 9
// outputCopy
// 9


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long long s;
	cin>>n>>s;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int j=0;
	long long count=0;
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		while(sum-arr[j]>=s){
			sum-=arr[j];
			j++;
		}
		if(sum>=s){
			count+=(j+1);
		}
	}
	cout<<count<<endl;
	return 0;
}
