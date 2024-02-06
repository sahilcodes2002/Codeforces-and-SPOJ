// G. Student Councils
// time limit per test0.5 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Given the number k
// . Each student council must consist of k
//  students. Important rule: each council should be composed of students from different groups. That is, no two students from the same group can be in the same council.

// Of course, each student should be in no more than one council (it is possible that some students are not included in any).

// An array a[1..n]
//  is given, where a[i]
//  is the number of students in the i
// -th group. What is the maximum number of councils can be formed?

// Input
// The first line contains integer k
//  (2≤k≤20
// ). The second line contains integer n
//  (k≤n≤50
// ). Next lines contain elements a[1],a[2],…,a[n]
//  (1≤a[i]≤109
// ).

// Output
// Print the required value.

// Examples
// inputCopy
// 3
// 5
// 4
// 4
// 4
// 4
// 4
// outputCopy
// 6
// inputCopy
// 4
// 6
// 1
// 2
// 3
// 4
// 5
// 6
// outputCopy
// 5


// G. Student Councils
// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G

#include <bits/stdc++.h>

using namespace std;

bool ispossible(long long mid, vector<long long> &arr,int k){
    int filled=0;
    long long last=0;
    for(auto it : arr){
        if(it+last <mid){
            last+=it;
        }
        else if(it>=mid){
            filled ++;
        }
        else{
            filled ++;
            last=(it+last)%mid;
        }
    }
    if(filled >= k){
        return true;
    }
    return false;
}

int main(){
    int k,n;
    cin>>k>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long long l=0;
    long long r=(long long)*max_element(arr.begin(),arr.end())*n/k+1;
    long long ans=-1;
    while(l<=r){
        auto mid=l+(r-l)/2;
        if(ispossible(mid,arr,k)){
            ans=mid;
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
