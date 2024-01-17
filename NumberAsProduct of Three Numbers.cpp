//https://codeforces.com/problemset/problem/1294/C

// C. Product of Three Numbers
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given one integer number n
// . Find three distinct integers a,b,c
//  such that 2≤a,b,c
//  and a⋅b⋅c=n
//  or say that it is impossible to do it.

// If there are several answers, you can print any.

// You have to answer t
//  independent test cases.

// Input
// The first line of the input contains one integer t
//  (1≤t≤100
// ) — the number of test cases.

// The next n
//  lines describe test cases. The i
// -th test case is given on a new line as one integer n
//  (2≤n≤109
// ).

// Output
// For each test case, print the answer on it. Print "NO" if it is impossible to represent n
//  as a⋅b⋅c
//  for some distinct integers a,b,c
//  such that 2≤a,b,c
// .

// Otherwise, print "YES" and any possible such representation.

// Example
// inputCopy
// 5
// 64
// 32
// 97
// 2
// 12345
// outputCopy
// YES
// 2 4 8 
// NO
// NO
// NO
// YES
// 3 5 823 



#include<bits/stdc++.h>
//for distinct values of a b c such that a*b*c=n
// intuition is that for a number n , either all a, b, c will be <= sqrt(n) or atleast a and b will be <= sqrt(n) because 2 factors cant be bigger than sqrt(n) .
using namespace std;
int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int count=0;
		vector<int> ans(3,1);
		for(int i=2;i*i<=n&&count<2;i++){ //will find at max two factors if available .
			if(n%i==0){
				ans[count]=i;
				n=n/i;
				count++;
			}
		}
		if(n>ans[count-1]){ //if we got a and b from above we check for c (:c has to be bigger then a and b as we have already checked for all numbers from a to b ) if we got only a then n will become b and count will be only 2
			ans[count]=n;
			count++;

		}
		if(count==3){
			cout<<"YES"<<endl;
			cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;

}
