EULERS TOTIENT FUNCTION



#include<bits/stdc++.h>

using namespace std;

int n=1000001;
vector<long long> arr(n); 

void euler(){
    for(int i=0;i<=n;i++){
        arr[i]=i;
    }

    for(int i=2;i<=n;i++){
        if(arr[i]==i){
            for(int j=2*i;j<=n;j+=i){
                arr[j]*=(i-1);
                arr[j]/=i;
            }
            arr[i]=i-1;
        }
    }
}

int main(){
    euler();

    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        cout<<arr[x]<<endl;
    }


    return 0;
}



//for single digit 

#include<bits/stdc++.h>
using namespace std;


int euler(int n){
    int result=n;
  //let there be n numbers of coprimes from 1 top n
    for(int i=2;i*i<=n;i++){
        if(result%i==0){
            while(result%i==0){
                result/=i; //remove that prime (n is no longer divisible by any multiple of the prime p)
            }
            n-=(n/i);   //subtracing the number of numbers which are multiples of the prime i
        }
    }

    if(result>1){ // there for result is a prime itself consider 34  (17 * 2)  we will devide it by all primes from 1 to 5(if its divisible) (i*i <=n ) , still result will be 17.
        n-=(n/result);
    }
    return n;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int x;
        cin>>x;
        cout<<euler(x)<<endl;
    }

    return 0;
}
