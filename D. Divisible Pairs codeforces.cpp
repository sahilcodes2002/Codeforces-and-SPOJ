// https://codeforces.com/contest/1931/problem/D

// D. Divisible Pairs
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes
// input
// standard input
// output
// standard output

// Polycarp has two favorite integers x
// and y (they can be equal), and he has found an array a of length n

// .

// Polycarp considers a pair of indices ⟨i,j⟩
// (1≤i<j≤n

// ) beautiful if:

//     ai+aj

// is divisible by x
// ;
// ai−aj
// is divisible by y

//     . 

// For example, if x=5
// , y=2, n=6, a=[1,2,7,4,9,6

// ], then the only beautiful pairs are:

//     ⟨1,5⟩

// : a1+a5=1+9=10 (10 is divisible by 5) and a1−a5=1−9=−8 (−8 is divisible by 2
// );
// ⟨4,6⟩
// : a4+a6=4+6=10 (10 is divisible by 5) and a4−a6=4−6=−2 (−2 is divisible by 2

//     ). 

// Find the number of beautiful pairs in the array a
// .
// Input

// The first line of the input contains a single integer t
// (1≤t≤104

// ) — the number of test cases. Then the descriptions of the test cases follow.

// The first line of each test case contains three integers n
// , x, and y (2≤n≤2⋅105, 1≤x,y≤109

// ) — the size of the array and Polycarp's favorite integers.

// The second line of each test case contains n
// integers a1,a2,…,an (1≤ai≤109

// ) — the elements of the array.

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output a single integer — the number of beautiful pairs in the array a

// .
// Example
// Input
// Copy

// 7
// 6 5 2
// 1 2 7 4 9 6
// 7 9 5
// 1 10 15 3 8 12 15
// 9 4 10
// 14 10 2 2 11 11 13 5 6
// 9 5 6
// 10 7 6 7 9 7 7 10 10
// 9 6 2
// 4 9 7 1 2 2 13 3 15
// 9 2 3
// 14 6 1 15 12 15 8 2 15
// 10 5 7
// 13 3 3 2 12 11 3 7 13 14

// Output
// Copy

// 2
// 0
// 1
// 3
// 5
// 7
// 0

    #include <bits/stdc++.h>
    #include <unordered_map>
    using namespace std;

    
     
    int main(){
        int t;
        cin>>t;

        while(t--){
            int n,x,y;
            cin>>n>>x>>y;
            map<pair<int,int>,int> mp;
            long long ans=0;
            for(int i=0;i<n;i++){
                int num;
                cin>>num;
                int xx=num%x;
                int yy=num%y;
                ans+=mp[{(x-xx)%x,yy}];
                mp[{xx,yy}]++;
            }
            cout<<ans<<endl;
        }
        return 0;
    }
