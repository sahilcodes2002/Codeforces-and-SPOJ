//https://www.spoj.com/problems/TDKPRIME/


// TDKPRIME - Finding the Kth Prime
// #sieve-of-eratosthenes
// The problem statement is really simple. There are some queries. You are to give the answers.

// Input
// An integer stating the number of queries Q(equal to 50000), and Q lines follow, each containing one integer K between 1 and 5000000 inclusive.

// Output
// Q lines with the answer of each query: the Kth prime number.

// Example
// Input:
// 7
// 1
// 10
// 100
// 1000
// 10000
// 100000
// 1000000

// Output:
// 2
// 29
// 541
// 7919
// 104729
// 1299709
// 15485863






#include<bits/stdc++.h>
using namespace std;


const int N=86028121;
bool isprime[N+1]; 
 

void sieve(){
	memset(isprime, true, sizeof(isprime));
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2;i*i<=N;i++){
		if(isprime[i]){
			for(int j=i*i;j<=N;j+=i){
				isprime[j]=false;
			}
		}
	}
}


int main(){

	int t;
	cin>>t;
	sieve();

	vector<int> primes;
	for(int i=2;i<=N;i++){
		if(isprime[i]){
			primes.push_back(i);
		}
	}
	while(t--){
		int n;
		cin>>n;
		cout<<primes[n-1]<<endl;
	}

		
	return 0;

}
