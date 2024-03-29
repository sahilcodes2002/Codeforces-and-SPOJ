// https://codeforces.com/contest/1950/problem/D

// D. Product of Binary Decimals
// time limit per test
// 3 seconds
// memory limit per test
// 256 megabytes
// input
// standard input
// output
// standard output

// Let's call a number a binary decimal if it is a positive integer and all digits in its decimal notation are either 0
// or 1. For example, 1010111 is a binary decimal, while 10201 and 787788

// are not.

// Given a number n
// , you are asked whether or not it is possible to represent n

// as a product of some (not necessarily distinct) binary decimals.
// Input

// The first line contains a single integer t
// (1≤t≤5⋅104

// ) — the number of test cases.

// The only line of each test case contains a single integer n
// (1≤n≤105

// ).
// Output

// For each test case, output "YES" (without quotes) if n

// can be represented as a product of binary decimals, and "NO" (without quotes) otherwise.

// You can output "YES" and "NO" in any case (for example, strings "yES", "yes", and "Yes" will be recognized as a positive response).
// Example
// Input
// Copy

// 11
// 121
// 1
// 14641
// 12221
// 10110
// 100000
// 99
// 112
// 2024
// 12421
// 1001

// Output
// Copy

// YES
// YES
// YES
// YES
// YES
// YES
// NO
// NO
// NO
// NO
// YES

// Note

// The first five test cases can be represented as a product of binary decimals as follows:

//     121=11×11

// .
// 1=1
// is already a binary decimal.
// 14641=11×11×11×11
// .
// 12221=11×11×101
// .
// 10110=10110

//     is already a binary decimal. 

#include <bits/stdc++.h>
using namespace std;
#define int long long
 

vector<int> bindec;

bool checkbd(int n){
	if(n==1){
		return true;
	}
	bool ans=false;
	for(int it : bindec){
		if(n%it==0){
			ans=(ans || checkbd(n/it));
		}
	}
	return ans;
}

void solve(){
	int n;
	cin>>n;
	if(checkbd(n)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}


bool isbd(int n){
	while(n){
		int k=n%10;
		if(k>1){
			return false;
		}
		n=n/10;
	}
	return true;
}


int32_t main(){
	int n=100001;
	for(int i=2;i<n;i++){
		if(isbd(i)){
			bindec.push_back(i);
		}
	}

	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

