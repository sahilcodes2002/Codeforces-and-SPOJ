// H. A-B Knapsack
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Given n
//  items of weight A
//  and costs a1,…,an
// , and m
//  items of weight B
//  and costs b1,…,bm
// .

// They fill a knapsack that can withstand a weight of no more than s
// . Determine what the maximum total cost of the items in the knapsack can be.

// Input
// The first line contains integers n
// , m
// , s
// , A
// , and B
//  (1≤n,m≤105
// , 1≤s,A,B≤109
// ).

// The second line contains n
//  integers ai
//  (1≤ai≤109
// ).

// The third line contains m
//  integers bi
//  (1≤bi≤109
// ).

// Output
// Print one number, the maximum total cost of items that can be put into a knapsack.

// Example
// inputCopy
// 6 7 23 3 5
// 7 4 3 1 5 8
// 10 12 7 3 8 9 7
// outputCopy
// 47



#include <bits/stdc++.h>
using namespace std;

bool sortfunction(int &a, int &b) {
    return a > b;
}

int main() {
    int n, m;
    long long s, a, b;
    cin >> n >> m >> s >> a >> b;

    vector<int> arr(n);
    vector<int> arr1(m);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    sort(arr.begin(), arr.end(), sortfunction);
    sort(arr1.begin(), arr1.end(), sortfunction);

    int numa=min(s/a,(long long)n);

    long long currw=a*numa;
    long long value=0;
    for(int i=0;i<numa;i++){
    	value+=arr[i];
    }

    long long ans=value;

    for(int i=0;i<m;i++){
    	currw+=b;
    	value+=arr1[i];
    	while(numa>0 && currw>s){
    		currw-=a;
    		value-=arr[--numa];
    	}
    	if(currw>s){
    		break;
    	}
    	ans=max(value,ans);

    }

    cout<<ans<<endl;

    return 0;
}
