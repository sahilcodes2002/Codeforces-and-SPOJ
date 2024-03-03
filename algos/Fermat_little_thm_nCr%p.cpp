//https://www.codingninjas.com/studio/problems/fermat-little-theorem_1756184?leftPanelTabValue=PROBLEM

//  Problem statement

// You are given two integers 'n' and 'r' and a prime number 'p'. Your task is to find (nCr) % p where nCr can be calculated as n! / (r! * (n - r)!).

// Note :

// N!  =  1 * 2 * 3 *... N

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :

// 1 <= T <= 5 
// 1 <= n, r, p <= 5 * 10 ^ 2
// p is prime number.

// Time limit: 1 sec.

// Sample Input 1 :

// 2 
// 5 2 11
// 4 3 13

// Sample Output 1 :

// 10
// 4

// Explanation for Sample Output 1:

// In test case 1, 
// n = 5, r = 2, and p = 11
// n C r = 5 C 2 = (5 * 4) / (2!) = 10
// n C r % p = 10 % 11 = 10. 
// So the answer will be 10.

// In test case 2,
// n = 4, r = 3, and p = 13 
// n C r = 4 C 3 = 4 C 1 = 4 
// n C r % p = 4 % 13 = 4. 
// So the answer will be 4.

// Sample Input 2 :

// 2
// 5 2 17
// 10 2 13

// Sample Output 2 :

// 10
// 6






#include<bits/stdc++.h>
using namespace std;

int facto(int x,int p){
    if(x==0){
        return 1;
    }

    int y=facto(x-1,p);
    return (x*y)%p;
}

int power(int x,int y,int p){
    if(y==0){
        return 1;
    }
 
    int pw=power(x,y/2,p);
    pw=(pw*pw)%p;

    return (y%2==0) ? pw : (pw*x)%p;
}

int gcd(int x, int y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}

int moduloinverse(int x,int p){
    if(gcd(x,p)!=1){
        cout<<"modulo inverse is not possiblle"<<endl;
        return 0;
    }
    else{

        return power(x,p-2,p);
    }
}

unsigned long long fermatLittle(int n,int r, int p){
    if(r>n){
        return 0;
    }
    int fn=facto(n,p);
    int fr=facto(r,p);
    cout<<fr<<endl;

    int n_r=facto(n-r,p);
    cout<<n<<" - "<<r<<" "<<n_r<<endl;
    

    unsigned long long ans= (fn* moduloinverse(fr,p))%p;
    ans=(ans*moduloinverse(n_r,p))%p;

    return ans;
}


int main(){
    int n,r,p;
    cin>>n>>r>>p;
    cout<<fermatLittle(n,r,p)<<endl;
    return 0;
}
