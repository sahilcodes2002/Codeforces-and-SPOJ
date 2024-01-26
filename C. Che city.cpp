// https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C

// C. Che city
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// This is a problem from the Russia High School Team Programming Contest 2013


// In the center of Che city there is a pedestrian street, one of the most popular walking places for city residents. This street is very pleasant to walk, because along the street there are n
//  funny monuments.

// The girl Masha from the city of Che likes two boys from her school, and she cannot make a choice between them. To make the final decision, she decided to date both boys at the same time. Masha wants to choose two monuments on the pedestrian street, near which the boys will be waiting for her. At the same time, she wants to choose such monuments so that the boys do not see each other. Masha knows that because of the fog, the boys will see each other only if they are on distance not more than r
//  meters. Masha got interested in how many ways there are to choose two different monuments for organizing dates.

// Input
// The first line of the input file contains two integers n
//  and r
//  (2≤n≤300000
// , 1≤r≤109
// ), the number of monuments and the maximum distance at which boys can see each other.

// The second line contains n
//  positive numbers d1,…,dn
// , where di
//  is the distance from the i
// -th monument to the beginning of the street. All monuments are located at different distances from the beginning of the street. Monuments are listed in ascending order of distance from the beginning of the street (1≤d1<d2<…<dn≤109
// ).

// Output
// Print one number, the number of ways to choose two monuments for organizing dates.

// Example
// inputCopy
// 4 4
// 1 3 5 8
// outputCopy
// 2
// Note
// In the given example, Masha can choose monuments 1 and 4 or monuments 2 and 4.


#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int  n;
    long long dist;
    cin>>n>>dist;

    std::vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int j=0;
    long long count=0;
    for(int i=1;i<n;i++){
        while((long long)arr[i]-arr[j]>dist){
            count+=n-i;
            j++;
        }
    }
    cout<<count<<endl;

    return 0;
}
 
