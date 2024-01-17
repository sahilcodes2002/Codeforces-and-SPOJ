//https://www.spoj.com/problems/FACTCG2/

// FACTCG2 - Medium Factorization
// no tags 
// The task in this problem is to write a number in a multiplication of prime numbers separated by “ x ”. You need to put the number 1 in this multiplication.

// Input
// The input consists of several lines.

// Each line consists of one integer N (1 <= N <= 10^7) .

// Output
// For each line you need to output the factorization separated by “ x ” and including 1.

// Sample
// Input
// 1
// 2
// 4
// 8

// Output
// 1
// 1 x 2
// 1 x 2 x 2
// 1 x 2 x 2 x 2

#include<bits/stdc++.h>
using namespace std;

int n=10000000;
vector<int> prime(n+1,0);

void sieve(){
	for(int i=2;i*i<=n;i++){
		if(prime[i]==0){
			for(int j=i*i;j<=n;j+=i){
				if(prime[j]==0){
					prime[j]=i;
				}
			}
		}
	}
}

int main(){
	sieve();
	int n;
	 while(scanf("%d", &n) != EOF){
	 	printf("%d" ,1);
	 	while(n>1){
	 		if(prime[n]==0){
	 			prime[n]=n;
	 		}
	 		printf(" x %d",prime[n]);
	 		n=n/prime[n];
	 	}
	 	printf("\n");
	 }
}
