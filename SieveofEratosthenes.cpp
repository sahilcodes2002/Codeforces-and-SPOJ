// https://www.codingninjas.com/studio/problems/prime-factorisation_1760849?leftPanelTabValue=PROBLEM

// Problem statement
// You are given an integer 'N'.


// https://www.codingninjas.com/studio/problems/prime-factorisation_1760849?leftPanelTabValue=PROBLEM
// You must return the unique prime factors of 'N' in increasing order.



// For Example:
// For ‘N’ = 10.

// Unique prime factors are 2 and 5.

// Hence we return {2, 5}.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 35
// Sample Output 1:
// 5 7
// Explanation For Sample Output 1:
// Unique prime factors are 5 and 7.

// Hence we return {5, 7}.
// Sample Input 2:
// 14
// Sample Output 2:
// 2 7
// Constraints:
// 1 <= 'N' <= 10^6

// Time Limit: 1 sec.


//1st way
//O(sqrt(N) log log sqrt(N)),

#include<bits/stdc++.h>
vector<int> countPrimes(int N)
{
    vector<int> primeFactors;


    vector<bool> isPrime(sqrt(N) + 1, true);
    for (int i = 2; i * i <= sqrt(N); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= sqrt(N); j += i) {
                isPrime[j] = false;
            }
        }
    }


    for (int i = 2; i <= sqrt(N); i++) {
        if (isPrime[i]) {
            while (N % i == 0) {
                primeFactors.push_back(i);
                while(N%i==0){
                    N /= i;
                }
                
            }
        }
    }

    if (N > 1) {
        primeFactors.push_back(N);
    }

    return primeFactors;
}


//2nd way 

/*
   Time Complexity: O(Nlog(log(N))).
   Space Complexity: O(N).

   where 'N' is the given number.
*/

vector<int> countPrimes(int n)
{
    vector<bool> isPrime(n, true);
    vector<int>ans;
    // Counting prime numbers less than 'N'.
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i] == true)
        {
            if (n % i == 0) {
                ans.push_back(i);
            }
            for (int j = i * 2; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return ans;
}


//3rd way 

vector<int> countPrimes(int n)
{
    vector<bool> check(n+1,true);

    vector<int> ans;

    for(int i=2;i<=n;i++){
        if(check[i]){
            if(n%i==0){
                ans.push_back(i);
            }
            for(int j=2*i;j<=n;j+=i){ //changes this ... marking the miltiples of all the primes so that we dont check for them on the way .
                check[j]=false;
            }
        }
    }
    return ans;
    
}
