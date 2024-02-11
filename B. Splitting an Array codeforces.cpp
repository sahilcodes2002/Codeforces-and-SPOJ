// B. Splitting an Array
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Given an array of n
//  positive integers. Your task is to divide it into k
//  segments so that the maximum sum on the segment is the minimum possible.

// Input
// The first line contains integers n
//  and k
//  (1≤k≤n≤105
// ). The second line contains the elements of the array ai
//  (1≤ai≤109
// ).

// Output
// Print one number, the minimum possible maximum sum on the segment.

// Example
// inputCopy
// 10 4
// 1 3 2 4 10 8 4 2 5 3
// outputCopy
// 12

#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<long long>& arr, long long mid, int n, int k){
    int sgt=1;
    long long s=0;

    for(int i=0;i<n;i++){
        if(s+arr[i]>mid){
            s=0;
            sgt++;
        }
        if(sgt>k || arr[i]>mid){
            return false;
        }
        s+=arr[i];
    }
    return true;
}
int main(){
    int n,k;

    cin>> n>>k;

    vector<long long > arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long long l=0;
    long long r=1e9*n;
    long long ans;

    while(l<=r){
        long long mid=l+(r-l)/2;
        if(ispossible(arr, mid, n,k)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    cout<<ans<<endl;
}
