// https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B

// B. Total Length
// time limit per test1 second
// memory limit per test1024 megabytes
// inputstandard input
// outputstandard output
// Given an array of n
//  integers ai
// . Let's say that the segment of this array a[l..r]
//  (1≤l≤r≤n
// ) is good if the sum of elements on this segment is at most s
// . Your task is to find sum of lengths of all good segments.

// Input
// The first line contains integers n
//  and s
//  (1≤n≤105
// , 1≤s≤1018
// ). The second line contains integers ai
//  (1≤ai≤109
// ).

// Output
// Print one integer, the sum of lengths of all good segments.

// Example
// inputCopy
// 7 20
// 2 6 4 3 6 8 9
// outputCopy
// 39





#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    
    long long sum=0;
    long long ans=0;

    int j=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        while(sum>k){
            sum-=arr[j];
            j++;
        }
        int x=i-j+1;
        int y=i-j+2;
        if(x%2==0){
            x/=2;
        }
        else{
            y/=2;
        }
        ans+=(long long)x*y;
    }
    cout<<ans<<endl;

    return 0;
}
 
