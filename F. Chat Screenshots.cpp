// https://codeforces.com/contest/1931/problem/F

// F. Chat Screenshots
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes
// input
// standard input
// output
// standard output

// There are n

// people in the programming contest chat. Chat participants are ordered by activity, but each person sees himself at the top of the list.

// For example, there are 4
// participants in the chat, and their order is [2,3,1,4]

// . Then

//     1

// -st user sees the order [1,2,3,4]
// .
// 2
// -nd user sees the order [2,3,1,4]
// .
// 3
// -rd user sees the order [3,2,1,4]
// .
// 4
// -th user sees the order [4,2,3,1]

//     . 

// k

// people posted screenshots in the chat, which show the order of participants shown to this user. The screenshots were taken within a short period of time, and the order of participants has not changed.

// Your task is to determine whether there is a certain order that all screenshots correspond to.
// Input

// The first line contains a single integer t
// (1≤t≤104

// ) — the number of input test cases. The descriptions of test cases follow.

// The first line of the description of each test case contains two integers n
// and k (1≤k≤n≤2⋅105,n⋅k≤2⋅105

// ) — the number of chat participants and the number of participants who posted screenshots.

// The following k

// lines contain descriptions of screenshots posted by the participants.

// The i
// -th row contains n integers aij each (1≤aij≤n, all aij are different) — the order of participants shown to the participant ai0, where ai0

// — the author of the screenshot. You can show that in the screenshot description it will always be at the top of the list.

// It is guaranteed that the sum of n⋅k
// for all test cases does not exceed 2⋅105

// . It is also guaranteed that all the authors of the screenshots are different.
// Output

// Output t
// lines, each of which is the answer to the corresponding test case. As an answer, output "YES" if there exists at least one order of participants, under which all k

// screenshots could have been obtained. Otherwise, output "NO".

// You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
// Example
// Input
// Copy

// 10
// 5 1
// 1 2 3 4 5
// 4 4
// 1 2 3 4
// 2 3 1 4
// 3 2 1 4
// 4 2 3 1
// 6 2
// 1 3 5 2 4 6
// 6 3 5 2 1 4
// 3 3
// 1 2 3
// 2 3 1
// 3 2 1
// 10 2
// 1 2 3 4 5 6 7 8 9 10
// 10 9 8 7 6 5 4 3 2 1
// 1 1
// 1
// 5 2
// 1 2 3 5 4
// 2 1 3 5 4
// 3 3
// 3 1 2
// 2 3 1
// 1 3 2
// 5 4
// 3 5 1 4 2
// 2 5 1 4 3
// 1 5 4 3 2
// 5 1 4 3 2
// 3 3
// 1 3 2
// 2 1 3
// 3 2 1

// Output
// Copy

// YES
// YES
// YES
// YES
// NO
// YES
// YES
// YES
// YES
// NO


    #include <bits/stdc++.h>
    using namespace std;


    bool is_cyclic(vector<vector<int>> &arr, vector<int>&vis, vector<int> &pathvis, int node){
        if(vis[node]==0){
            vis[node]=1;
            if(pathvis[node]==1){
                return false;
            }
            pathvis[node]=1;
            for(int i=0;i<arr[node].size();i++){
                //cout<<arr[node][i]<<endl;
                bool check =is_cyclic(arr,vis,pathvis,arr[node][i]);
                if(!check){
                    return false;
                }
            }
            pathvis[node] = 0;
            return true;
        }
        else {
            if(pathvis[node]==1){
                return false;
            }
            return true;
        }
    }
    

     
    int main(){
        int t;
        cin>>t;

        while(t--){
            int n,k;
            cin>>n>>k;
            vector<vector<int>> arr(n+1);
            vector<set<int>> hash(n+1);

            for(int i=0;i<k;i++){
                int prev=-1;
                for(int j=0;j<n;j++){
                    int y;
                    cin>>y;
                    if(j==1){
                        prev=y;
                    }
                    else if (j>1){
                        if(hash[prev].find(y)==hash[prev].end()){
                            arr[prev].push_back(y);
                            hash[prev].insert(y);
                        }
                        
                        prev=y;
                    }
                }
            }

            vector<int> vis(n+1,0);
            vector<int> pathvis(n+1,0); 

            bool valid;
            for(int i=1;i<=n;i++){
                valid=is_cyclic(arr,vis,pathvis,i);
                if(valid==false){
                    //cout<<"false"<<endl;
                    break;
                }
            }
            if(valid){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }


        }
        return 0;
    }
