// how many numbers in range 1-10^6 have thier min prime factor as n ;
//there will be t queries 
// t lines of input with a prime number n and you have to print the count of numbers that have n as their min prime factor.



#include<bits/stdc++.h>
using namespace std;
 
int n=1000000;
vector<int> prime(n+1,1);
 
void sieve(){
	for(int i=2;i*i<=n;i++){
		if(prime[i]==1){
			for(int j=i*i;j<=n;j+=i){
				if(prime[j]==1){
					prime[i]=prime[i]+1;
					prime[j]=0;
				}
			}
		}
	}
}
 
int main(){
	sieve();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<prime[n]<<endl;
	}
	return 0;
}
