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






#include <iostream>
#include <vector>
using namespace std;
 
const int n = 86028121;
vector<bool> prime(n + 1, true);

 
void sieve() {
    for (int i = 2; i*i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
	//this is to get 5000000th prime = 86028121
    // int pp = 0;
    // int limit=5000000;
    // for (int i = 2; i <= n; i++) {
    //     if (prime[i]) {
    //         pp++;
    //         if (pp  == limit) {
    //             cout << i << endl;
    //         }
    //     }
    // }
    
}
 
int main() {
    sieve();
    vector<int> primes;
    for(int i=2;i<=n;i++){
    	if(prime[i]){
    		primes.push_back(i);
    	}
    }

    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	cout<<primes[n-1]<<endl;
    }
    return 0;
}
