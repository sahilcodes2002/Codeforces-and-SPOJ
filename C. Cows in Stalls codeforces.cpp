C. Cows in Stalls
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Stalls are located on a straight line, your task is to arrange the cows to stalls so that the minimum distance between the cows is as large as possible.

Input
The first line contains numbers n
 (2≤n≤104
), the number of stalls and k
 (2≤k≤n
), the number of cows. The second line contains n
 integer numbers in ascending order, the coordinates of the stalls (coordinates are in the range from 0
 to 109
, inclusive).

Output
Print one number, the largest possible minimum distance between two cows.

Example
inputCopy
6 3
2 5 7 11 15 20
outputCopy
9




#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<long long>& arr, long long mid, int n, int k){
    int count=1;
    int  last_posi=0;
    for(int i=1;i<n;i++){
        if(arr[i]-mid>=arr[last_posi]){
            count++;
            last_posi=i;
        }
        if(count>=k){
            return true;
        }
    }
    return false;
}
int main(){
    int n,k;

    cin>> n>>k;

    vector<long long > arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    long long l=0;
    long long r=1e9+1;
    long long ans;

    while(l<=r){
        long long mid=l+(r-l)/2;
        if(ispossible(arr, mid, n,k)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    cout<<ans<<endl;
}
