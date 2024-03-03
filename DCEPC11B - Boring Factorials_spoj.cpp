// //https://www.spoj.com/problems/DCEPC11B/

// DCEPC11B - Boring Factorials
// #math

// Sameer and Arpit want to overcome their fear of Maths and so they have been recently practicing Maths problems a lot. Aman, their friend has been helping them out. But as it goes, Sameer and Arpit have got bored of problems involving factorials. Reason being, the factorials are too easy to calculate in problems as they only require the residue modulo some prime and that is easy to calculate in linear time. So to make things interesting for them, Aman - The Mathemagician, gives them an interesting task. He gives them a prime number P and an integer N close to P, and asks them to find N! modulo P. He asks T such queries.
// Input

// First line contains an integer T, the number of queries asked.

// Next T lines contains T queries of the form “N P”. (quotes for clarity)
// Output

// Output exactly T lines, containing N! modulo P.
// Example

// Input:
// 3
// 2 5
// 5 11
// 21 71

// Output:
// 2
// 10
// 6

// Constraints:

// 1 <= T <= 1000

// 1 < P <= 2*10^9

// 1 <= N <= 2*10^9
// Abs(N-P) <= 1000


#include<bits/stdc++.h>

using namespace std;

#define int long long

int power(int x, int y, int p){
    int res=1;
    while(y>0){
        if(y&1){
            res=(res*x)%p;
        }
        y=y>>1;
        x=(x*x)%p;
    }
    return res;
}

int moduloinverse(int x,int p){
    
    return power(x,p-2,p);
    
}

int factomodulo(int x,int p){
    if(p<=x){
        return 0;
    }
    
    int num=p-1;
    for(int i=x+1;i<p;i++){
        num=(num*moduloinverse(i,p))%p;
    }
    return num;
}

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        int x,p;
        cin>>x>>p;
        cout<<factomodulo(x,p)<<endl;
    }
    

    return 0;

}
