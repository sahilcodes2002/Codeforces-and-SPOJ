// https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D

// D. Stylish clothes
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Gleb loves shopping. Once, he got the idea to choose a cap, a shirt, pants and shoes so that they look as stylish as possible. In Gleb's understanding clothes are more stylish when the difference in color of the elements of his clothes is small.

// There are n1 caps, n2 shirts, n3 pants and n4 shoes (1 ≤ ni ≤ 100, 000). Each clothes element has its color (an integer from 1 to 100, 000). A set of clothes is one cap, shirt, pants and one pair of boots. Each set is characterized by the maximum difference between any two of its elements. Help Gleb to choose the most stylish set, that is the set with the minimum color difference.

// Input
// For each clothes element i (i = 1, 2, 3, 4) given its count ni, and ni integers in next line which is their color. First clothes element in input is caps, second is shirts, third is pants and forth is shoes. All numbers in input are positive integers not bigger than 100, 000.

// Output
// Write 4 integers in output, color of cap, shirt, pants and shoes Gleb will choose. If there are several most stylish sets output any of them.

// Examples
// inputCopy
// 3
// 1 2 3
// 2
// 1 3
// 2
// 3 4
// 2
// 2 3
// outputCopy
// 3 3 3 3
// inputCopy
// 1
// 5
// 4
// 3 6 7 10
// 4
// 18 3 9 11
// 1
// 20
// outputCopy
// 5 6 9 20



#include<bits/stdc++.h>
using namespace std;




bool checkwindow(vector<queue<int>>&window){
    for(int i=0;i<4;i++){
        if(window[i].empty()){
            return true;
        }
    }
    return false;
}


vector<int> solve(vector<pair<int,int>> &all_clothes){

    

    const int n= all_clothes.size();

    vector<queue<int>>window(4);

    vector<int> ans(4);

    int j=0;
    int diff=1e5+1;

    for(int i=0;i<n;i++){

        while(j<n && checkwindow(window)){
            window[all_clothes[j].second].push(all_clothes[j].first);
            j++;
        }
        if(j>=n && checkwindow(window)){
            break;
        }
        int d=all_clothes[j-1].first-all_clothes[i].first;

        if(d<diff){
            diff=d;
            for(int i=0;i<4;i++){
                ans[i]=window[i].front();
            }

        }
        window[all_clothes[i].second].pop();
    }

    return ans;

}



int main(){
    vector<pair<int,int>> all_clothes;

    int n1,n2,n3,n4;

    cin>>n1;

    all_clothes.resize(n1);

    for(int i=0;i<n1;i++){
        cin>>all_clothes[i].first;
        all_clothes[i].second=0;
    }

    cin>>n2;

    all_clothes.resize(n1+n2);

    for(int i=0;i<n2;i++){
        cin>>all_clothes[n1+i].first;
        all_clothes[n1+i].second=1;
    }

    cin>>n3;

    all_clothes.resize(n1+n2+n3);

    for (int i = 0; i < n3; ++i){
        cin>>all_clothes[n1+n2+i].first;
        all_clothes[n1+n2+i].second=2;
    }

    cin>>n4;

    all_clothes.resize(n1+n2+n3+n4);
    for(int i=0;i<n4;i++){
        cin>>all_clothes[n1+n2+n3+i].first;
        all_clothes[n1+n2+n3+i].second=3;
    }
    sort(all_clothes.begin(),all_clothes.end());

    vector<int> ans=solve(all_clothes);
    for(int i=0;i<4;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
