// https://codeforces.com/contest/1343/problem/B

// B. Balanced Array
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given a positive integer n
// , it is guaranteed that n
//  is even (i.e. divisible by 2
// ).

// You want to construct the array a
//  of length n
//  such that:

// The first n2
//  elements of a
//  are even (divisible by 2
// );
// the second n2
//  elements of a
//  are odd (not divisible by 2
// );
// all elements of a
//  are distinct and positive;
// the sum of the first half equals to the sum of the second half (∑i=1n2ai=∑i=n2+1nai
// ).
// If there are multiple answers, you can print any. It is not guaranteed that the answer exists.

// You have to answer t
//  independent test cases.

// Input
// The first line of the input contains one integer t
//  (1≤t≤104
// ) — the number of test cases. Then t
//  test cases follow.

// The only line of the test case contains one integer n
//  (2≤n≤2⋅105
// ) — the length of the array. It is guaranteed that that n
//  is even (i.e. divisible by 2
// ).

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
//  (∑n≤2⋅105
// ).

// Output
// For each test case, print the answer — "NO" (without quotes), if there is no suitable answer for the given test case or "YES" in the first line and any suitable array a1,a2,…,an
//  (1≤ai≤109
// ) satisfying conditions from the problem statement on the second line.

// Example
// inputCopy
// 5
// 2
// 4
// 6
// 8
// 10
// outputCopy
// NO
// YES
// 2 4 1 5
// NO
// YES
// 2 4 6 8 1 3 5 11
// NO

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	n=n/2;
    	if(n%2==0){
    		cout<<"YES"<<endl;
    		int x=2;
    		for(int i=1;i<=n;i++){
    			cout<<x<<" ";
    			x+=2;
    		}
    		x=1;
    		for(int j=1;j<n;j++){
    			cout<<x<<" ";
    			x+=2;
    		}
    		cout<<x+n<<endl;

    	}
    	else{
    		cout<<"NO"<<endl;
    	}
    }

    return 0;
}
