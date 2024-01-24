https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F


F. Segments with Small Spread
time limit per test1 second
memory limit per test1024 megabytes
inputstandard input
outputstandard output
Given an array of n
 integers ai
. Let's say that a segment of this array a[l..r]
 (1≤l≤r≤n
) is good if the difference between the maximum and minimum elements on this segment is at most k
. Your task is to find the number of different good segments.

Input
The first line contains integers n
 and k
 (1≤n≤105
, 0≤k≤1018
). The second line contains integers ai
 (1≤ai≤1018
).

Example
inputCopy
7 3
2 6 4 3 6 8 9
outputCopy
16


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long long k;
	cin>>n>>k;
	vector<long long> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long ans=0;
	int j=0;
	multiset<long long> window;
	for(int i=0;i<n;i++){
		window.insert(arr[i]);

		while(*window.rbegin()-*window.begin()>k){
			window.erase(window.find(arr[j]));
			j++;
		}
		ans+=(i-j+1);
	}
	

	cout<<ans<<endl;
	return 0;
}
