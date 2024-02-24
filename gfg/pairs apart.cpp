you have an array of numbers , you can form a pair of identical numbers if they are k indices apart there fore a[i]=5 ans a[j]=5 ans j-i>=k;
1<=n<=1e5;
1<=k<=1e5;
1<=a[i]<=1e6;


example :
n=5   k=2
a={1,2,2,1,2}

pairs : [0,3] [1,4] [2,4];
output: 3


    #include <bits/stdc++.h>
    using namespace std;

    
     
    int main(){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        map<int,int>mp;
        long long ans=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=k;i<n;i++){
            mp[arr[i-k]]++;
            ans+=mp[arr[i]];
        }
        cout<<ans<<endl;
        return 0;
    }
