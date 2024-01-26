// https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A
// A. Looped Playlist
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Misha listens to music on his player, his playlist consists of n songs that are played in a specific order. After the last song ends, the first one starts playing. Each song has its own characteristic, positivity ai, given by an integer. After listening to the i-h song, Misha's mood increases by ai.

// Misha can start listening to any of the songs and listen to any number of songs in a row, while he may listen to some songs more than once.

// Misha feels happy if his mood after listening to the songs has increased by at least p. He wants to feel happy listening to as few songs as possible. Help him choose the song to start listening to and the number of songs to listen to to be happy.

// Input
// The first line contains two integers n and p (1 ≤ n ≤ 1000, 1 ≤ p ≤ 1018), the number of songs in the playlist and the amount that Misha wants increase his mood.

// The second line contains n integers ai (1 ≤ ai ≤ 109), positivity of the songs.

// Output
// Print two numbers, the index of the song k, with which you should start listening, and the number of songs c, which you should listen to. If there are several possible answers, print any.

// Examples
// inputCopy
// 9 10
// 1 2 3 4 5 4 3 2 1
// outputCopy
// 3 3
// inputCopy
// 5 6
// 3 1 1 1 4
// outputCopy
// 5 2
// inputCopy
// 3 100
// 10 10 10
// outputCopy
// 1 10



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
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int idx=-1;
    long long numb=LLONG_MAX;
    long long iterations=k/sum;
    k=k%sum;
    
    int i=0;
    sum=0;
    while(i<2*n){
        //cout<<i<<endl;
        int j=i;
        while(sum<k){
            sum+=arr[j%n];
            j++;
        }
        sum=0;
        if(j-i<numb){
            numb=j-i;
            idx=(i%n)+1;
        }
        i++;
    }
    numb+=iterations*n;

    cout<<idx<<" "<<numb;

}
 
