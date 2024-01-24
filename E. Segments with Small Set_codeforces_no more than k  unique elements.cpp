// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E

// E. Segments with Small Set
// time limit per test1 second
// memory limit per test1024 megabytes
// inputstandard input
// outputstandard output
// Given an array of n
//  integers ai
// . Let's say that a segment of this array a[l..r]
//  (1≤l≤r≤n
// ) is good if there are no more than k
//  unique elements on this segment. Your task is to find the number of different good segments.

// Input
// The first line contains integers n
//  and k
//  (1≤n≤105
// , 0≤k≤n
// ). The second line contains integers ai
//  (1≤ai≤105
// ).

// Output
// Print one integer, the number of good segments.

// Example
// inputCopy
// 7 3
// 2 6 4 3 6 8 3
// outputCopy
// 20


#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	int k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
 
	vector<int> hash(100001,0);
	int count=0;
	long long ans=0;
	int j=0;
	for(int i=0;i<n;i++){
		
		hash[arr[i]]++;
 
		if(hash[arr[i]]==1){
			count++;
		}
		
		while(count>k){
			hash[arr[j]]--;
			if(hash[arr[j]]==0){
				count--;
			}
			j++;
		}
		if(count<=k){
			
			ans+=(i-j+1);
		}
		
	}
 
	cout<<ans<<endl;
	return 0;
}
