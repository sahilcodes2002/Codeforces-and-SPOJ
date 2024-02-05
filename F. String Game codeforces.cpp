//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F

// F. String Game
// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// Petya has the word t
// , he wants to make the word p
//  from it. Petya begins to delete the letters in a certain order, which is described as a permutation of indices of the letters of the word t
// : a1…a|t|
// . Note that after deleting a letter, the numbering does not change.

// His brother Vasya is afraid that Petya may delete too many letters, so he will not get the word p
//  in the end. Vasya's task is to stop his brother at some point and finish deleting himself in such a way, that the resulting word will be p
// . Since Petya likes this activity, Vasya wants to stop him as late as possible. Your task is to tell how many letters Petya can delete out before Vasya stops him.

// It is guaranteed that the word p
//  can be obtained by deleting letters from t
// .

// Input
// The first and second lines of the input file contain the words t
//  and p
// , respectively. Words consist of lowercase letters of the Latin alphabet (1≤|p|<|t|≤200000
// ).

// The next line contains the permutation a1…a|t|
//  of letter indices, which specifies the order in which Petya deletes the letters of the word t
//  (1≤ai≤|t|
// , all ai
//  are different).

// Output
// Print one number, the maximum number of letters that Petya can delete.

// Example
// inputCopy
// ababcba
// abb
// 5 3 4 1 7 6 2
// outputCopy
// 3


#include<bits/stdc++.h>

using namespace std;
bool isfound(string s, string target, vector<int> &hash){
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==target[j] && hash[i+1]>0){
    
            j++;
        }
        if(j>=target.size()){

            return true;
        }
    }
    return false;
}
bool ispossible(string s, string target, vector<int> &arr,int mid,vector<int> hash){
    //cout<<mid<<" ";
    for(int i=0;i<mid;i++){
        hash[arr[i]]--;
    }
    
    if(isfound(s, target,hash)){
        
        return true;
    }
    
    return false;
}
int main(){
    string s;
    cin>>s;
    string target;
    cin>>target;
    vector<int> hash(s.size()+1,1);
    vector<int> arr(s.size());
    for(int i=0;i<s.size();i++){
        cin>>arr[i];
    }

    int l=-1;
    int r=s.size();
    int ans=-1;

    while(l<=r){
        int mid=l+(r-l)/2;

        if(ispossible(s,target,arr,mid,hash)){
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
