// https://codeforces.com/problemset/problem/1343/D

// D. Constant Palindrome Sum
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given an array a
//  consisting of n
//  integers (it is guaranteed that n
//  is even, i.e. divisible by 2
// ). All ai
//  does not exceed some integer k
// .

// Your task is to replace the minimum number of elements (replacement is the following operation: choose some index i
//  from 1
//  to n
//  and replace ai
//  with some integer in range [1;k]
// ) to satisfy the following conditions:

// after all replacements, all ai
//  are positive integers not greater than k
// ;
// for all i
//  from 1
//  to n2
//  the following equation is true: ai+an−i+1=x
// , where x
//  should be the same for all n2
//  pairs of elements.
// You have to answer t
//  independent test cases.

// Input
// The first line of the input contains one integer t
//  (1≤t≤104
// ) — the number of test cases. Then t
//  test cases follow.

// The first line of the test case contains two integers n
//  and k
//  (2≤n≤2⋅105,1≤k≤2⋅105
// ) — the length of a
//  and the maximum possible value of some ai
//  correspondingly. It is guratanteed that n
//  is even (i.e. divisible by 2
// ). The second line of the test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤k
// ), where ai
//  is the i
// -th element of a
// .

// It is guaranteed that the sum of n
//  (as well as the sum of k
// ) over all test cases does not exceed 2⋅105
//  (∑n≤2⋅105
// , ∑k≤2⋅105
// ).

// Output
// For each test case, print the answer — the minimum number of elements you have to replace in a
//  to satisfy the conditions from the problem statement.

// Example
// inputCopy
// 4
// 4 2
// 1 2 1 2
// 4 3
// 1 2 2 1
// 8 7
// 6 1 1 7 6 3 4 6
// 6 6
// 5 2 6 1 3 4
// outputCopy
// 0
// 1
// 4
// 2



#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
    	int n,k;
    	cin>>n>>k;
    	vector<int> arr(n+1,0);
    	for(int i=1;i<=n;i++){
    		cin>>arr[i];
    	}
    	vector<pair<int,int>> pairs;//this will store all the pairs 
    	for(int i=1;i<=n/2;i++){
    		pair<int,int> a;
    		a.first=arr[i];
    		a.second=arr[n-i+1];
    		pairs.push_back(a);
    	}
    	vector<int> prefix(2*k+2,0);//stores the pair sum with one or zero replacements
    	map<int,int> zero; //pair sum with zero replacements
    	for(auto it : pairs){
    		int l=it.first;
    		int r=it.second;
    		zero[l+r]++; // l+r is the sum without any changes in values of the pair , this sum will need zero chnages in the values of pair;
    		prefix[1 + min(l, r)] += 1; // to find the start of the range we (we can give values from 1 to k) , the start will have the minimum value so to find the start we find the min of the pairs and add one to it ( i.e. conveting the bigger val of pair to 1  so smaller is left unchanges and bigger is changes to 1) 
    		prefix[max(l, r) + k + 1] -= 1;// to find the largest possible sum we change the smaller val of the pair to k and the larger is left as it is. 
    		//above we are using the sclaline prefix trick to find the prefix sum which will help us calculate the number of single change pair of sum possible for each value from 2 to 2k;
    	}
    	for(int i=2;i<=2*k;i++){
    		prefix[i]+=prefix[i-1];// calculating the prefix sum from scaline prefix sum trick
    	}
    	//now we have a vector with indices 2 to 2*k containing number of pairs that will have that index as the sum with no change in value or one change of value in the pair.
    	int mn=INT_MAX;// now we iterate from 2 to 2k and find the indices with least number of change required to satisfy the condition in question.
    	for(int i=2;i<=2*k;i++){
    		int single_change=prefix[i];//single_change has count of pair with both o change required or 1 change required.
    		int double_change=n/2-single_change;//double_chage will store the number of pair with two change required (n/2 is the total number of pairs)
    		if(zero.find(i)!=zero.end()){
    			single_change-=zero[i]; //we remore the pairs with 0 changes required as they will not add up to the total changes as no chnages were made
    		}
    		int total_change=single_change+(double_change*2); //we will calculate the total_changes here (double_change will contribute to 2 changes as both values of the pair were changed )
    		mn=min(total_change,mn); //we have to return the min changes 
    	}
    	cout<<mn<<endl;
    }
  return 0;
}
