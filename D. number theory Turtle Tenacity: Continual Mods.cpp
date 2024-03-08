// https://codeforces.com/contest/1933/problem/D


// D. Turtle Tenacity: Continual Mods
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes
// input
// standard input
// output
// standard output

// Given an array a1,a2,…,an
// , determine whether it is possible to rearrange its elements into b1,b2,…,bn, such that b1modb2mod…modbn≠0

// .

// Here xmody
// denotes the remainder from dividing x by y. Also, the modulo operations are calculated from left to right. That is, xmodymodz=(xmody)modz. For example, 2024mod1000mod8=(2024mod1000)mod8=24mod8=0

// .
// Input

// The first line of the input contains a single integer t
// (1≤t≤104

// ) — the number of test cases.

// The first line of each test case contains a single integer n
// (2≤n≤105

// ).

// The second line of each test case contains n
// integers a1,a2,…,an (1≤ai≤109

// ).

// The sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output "YES" if it is possible, "NO" otherwise.

// You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
// Example
// Input
// Copy

// 8
// 6
// 1 2 3 4 5 6
// 5
// 3 3 3 3 3
// 3
// 2 2 3
// 5
// 1 1 2 3 7
// 3
// 1 2 2
// 3
// 1 1 2
// 6
// 5 2 10 10 10 2
// 4
// 3 6 9 3

// Output
// Copy

// YES
// NO
// YES
// NO
// YES
// NO
// YES
// NO

// Note

// In the first test case, rearranging the array into b=[1,2,3,4,5,6]
// (doing nothing) would result in 1mod2mod3mod4mod5mod6=1

// . Hence it is possible to achieve the goal.

// In the second test case, the array b
// must be equal to [3,3,3,3,3], which would result in 3mod3mod3mod3mod3=0

// . Hence it is impossible to achieve the goal.

// In the third test case, rearranging the array into b=[3,2,2]
// would result in 3mod2mod2=1. Hence it is possible to achieve the goal.










    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    int32_t main(){
    	int t;
    	cin>>t;
    	while(t--){
    		int n;
    		cin>>n;
    		vector<int> arr(n);
    		for(int i=0;i<n;i++){
    			cin>>arr[i];
    		}
    		sort(arr.begin(),arr.end());
    		bool gotit=false;
    		if(arr[0]==arr[1]){
    			for(int i=2;i<n;i++){
    				if(arr[i]%arr[0]!=0){
    					gotit=true;
    					break;
    				}
    			}
    			if(gotit) cout<<"YES"<<endl;
    			else{
    				cout<<"NO"<<endl;
    			}
    		}
    		else {
    			cout<<"YES"<<endl;
    		}
    	}
    	return 0;
    }
