//if the give number is prime or not .
//sum of factors can also be solves as we are checking the divisibility for every number <= sqrt(n) , similarly getting the other factor by deviding .






//when the test cases are not in queries . time complexity is O(sqrt(n));
#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;
	cin>>n;
	int count=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			count++;
			if(n/i!=i){
				count++;
			}
		}
	}
	if(count>2){
		cout<<"not prime"<<endl;
		return 0;
	}
	cout<<"prime"<<endl;
	return 0;
}


//if there are t queries where t <= 10^6 && n<=10^6 thenthe above time complexity will be 10^6* sqrt(10^6) ~ 10^6 * 10^3 ~10^9  
// there are 10^8 operations in 1 sec so 10^9=10^8*10 so 1sec *10 == there for 10 sec will be needed .
// to solve this we use sive method :


#include<bits/stdc++.h>
//for distinct values of a b c such that a*b*c=n
// intuition is that for a number n , either all a, b, c will be <= sqrt(n) or atleast a and b will be <= sqrt(n) because 2 factors cant be bigger than sqrt(n) .

using namespace std;
int N=1000000;
vector<bool> isprime(N+1,true);
void sieve(){
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
	while(t--){
		int n;
		cin>>n;
		if(isprime[n]){
			cout<<"prime"<<endl;
		}
		else{
			cout<<"Not Prime"<<endl;
		}
	}

		
	return 0;

}







