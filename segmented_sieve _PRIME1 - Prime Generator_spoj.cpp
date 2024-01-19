// https://www.spoj.com/problems/PRIME1/

// PRIME1 - Prime Generator
// #number-theory
// Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

// Input
// The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

// Output
// For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

// Example
// Input:
// 2
// 1 10
// 3 5

// Output:
// 2
// 3
// 5
// 7

// 3
// 5








//method-1

#include <bits/stdc++.h>

using namespace std;
 
const int N=1000000;
bool isprime[N+1];

void sieve(){
	for(int i=2;i<=N;i++){
		isprime[i]=true;
	}

	for(int i=2;i*i<=N;i++){
		if(isprime[i]==true){
			for(int j=i*i;j<=N;j+=i){
				isprime[j]=false;
			}
		}
	}
}


int main(){
	sieve();
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		if(l<2){
			l=2;
		}
		vector<int>primes;
		for(int i=2;i*i<=r;i++){   // its just like another sieve we will store the primes <=sqrt(r) and mark the multiples of these primes then the primes >sqrt(r) will be automatically left unmarked and we will have all the primes from l to r.
			if(isprime[i]==true){
				primes.push_back(i);
			}
		}


		int mark[r-l+1];
		for(int i=0;i<r-l+1;i++){
			mark[i]=1;
		}

		for(auto it : primes){
			int firstMul= (l/it)*it;
			if(firstMul<l){
				firstMul+=it;
			}

			for(int j=max(firstMul,it*it);j<=r;j+=it){
				mark[j-l]=0;
			}
		}
		for(int i=l;i<=r;i++){
			if(mark[i-l]==1){
				cout<<i<<endl;
			}
		}
		cout<<endl;
	}
}





//method 2


#include <bits/stdc++.h>

using namespace std;
 
bool isprime(int x){
	if(x<2){
		return false;
	}
	if(x==2){
		return true;
	}
	if(x%2==0){
		return false;
	}
	for(int i=3;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int a,b;
		cin>>a>>b;
		for(int i=a;i<=b;i++){
			if(isprime(i)){
				cout<<i<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
