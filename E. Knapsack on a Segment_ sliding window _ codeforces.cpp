// https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/E

// E. Knapsack on a Segment
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Given an array of n
//  items, for each of them its weight is wi
//  and cost is ci
// . You need to select a segment of this array, the total weight on which is not more than s
// , and the total cost is maximum.

// Input
// The first line contains integers n
//  and s
//  (1≤n≤105
// , 1≤s≤109
// ).

// The second line contains n
//  integers wi
//  (1≤wi≤109
// ).

// The third line contains n
//  integers ci
//  (1≤ci≤109
// ).

// Output
// Print one number, the maximum total cost of items that can be put into a knapsack.

// Example
// inputCopy
// 6 20
// 9 7 6 5 8 4
// 7 1 3 6 8 3
// outputCopy
// 17


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long long s;
	cin>>n>>s;
	vector<long long> w(n);
	vector<long long>c(n);

	for(int i=0;i<n;i++){
		cin>>w[i];
	}

	for(int i=0;i<n;i++){
		cin>>c[i];
	}

	long long mcost=-1;
	long long weight=0;
	long long cost=0;
	int j=0;

	for(int i=0;i<n;i++){
		weight+=w[i];
		cost+=c[i];

		while(weight>s){
			weight-=w[j];
			cost-=c[j];
			j++;
		}

		mcost=max(cost,mcost);
	}

	cout<<mcost<<endl;

	return 0;
}
