// https://codeforces.com/contest/1931/problem/E
// E. Anna and the Valentine's Day Gift
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes
// input
// standard input
// output
// standard output

// Sasha gave Anna a list a
// of n

// integers for Valentine's Day. Anna doesn't need this list, so she suggests destroying it by playing a game.

// Players take turns. Sasha is a gentleman, so he gives Anna the right to make the first move.

//     On her turn, Anna must choose an element ai

// from the list and reverse the sequence of its digits. For example, if Anna chose the element with a value of 42, it would become 24; if Anna chose the element with a value of 1580, it would become 851
// . Note that leading zeros are removed. After such a turn, the number of elements in the list does not change.
// On his turn, Sasha must extract two elements ai
// and aj (i≠j) from the list, concatenate them in any order and insert the result back into the list. For example, if Sasha chose the elements equal to 2007 and 19, he would remove these two elements from the list and add the integer 200719 or 192007. After such a turn, the number of elements in the list decreases by 1

//     .

// Players can't skip turns. The game ends when Sasha can't make a move, i.e. after Anna's move there is exactly one number left in the list. If this integer is not less than 10m
// (i.e., ≥10m

// ), Sasha wins. Otherwise, Anna wins.

// It can be shown that the game will always end. Determine who will win if both players play optimally.
// Input

// The first line contains an integer t
// (1≤t≤104

// ) — the number of test cases.

// Then follows the description of the test cases.

// The first line of each test case contains integers n
// , m (1≤n≤2⋅105, 0≤m≤2⋅106

// ) — the number of integers in the list and the parameter determining when Sasha wins.

// The second line of each test case contains n
// integers a1,a2,…,an (1≤ai≤109

// ) — the list that Sasha gave to Anna.

// It is guaranteed that the sum of n
// for all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output:

//     "Sasha", if Sasha wins with optimal play;
//     "Anna", if Anna wins with optimal play. 

// Example
// Input
// Copy

// 9
// 2 2
// 14 2
// 3 5
// 9 56 1
// 4 10
// 1 2007 800 1580
// 4 5
// 5000 123 30 4
// 10 10
// 6 4 6 2 3 1 10 9 10 7
// 1 1
// 6
// 1 1
// 10
// 8 9
// 1 2 9 10 10 2 10 2
// 4 5
// 10 10 10 10

// Output
// Copy

// Sasha
// Anna
// Anna
// Sasha
// Sasha
// Anna
// Anna
// Anna
// Sasha


    #include <bits/stdc++.h>
    using namespace std;

    
     
    int main(){
        int t;
        cin>>t;

        while(t--){
            int n;
            int m;
            cin>>n>>m;
            vector<string> arr(n);
            vector<int> len(n);
            vector<int> zer(n,0);
            for(int i=0;i<n;i++){
                cin>>arr[i];
                len[i]=arr[i].size();
                int x=len[i]-1;
                while(x>=0 && arr[i][x]=='0'){
                    zer[i]++;
                    x--;
                }
            }
            int digits=0;
            for(int i=0;i<n;i++){
                digits+=(len[i]-zer[i]);
            }
            sort(zer.begin(),zer.end());
            reverse(zer.begin(),zer.end());
            for(int i=0;i<n;i++){
                if(i&1){
                    digits+=zer[i];
                }
            }
            if(digits>=(m+1)){
                cout<<"Sasha"<<endl;
            }
            else{
                cout<<"Anna"<<endl;
            }

        }
        return 0;
    }
