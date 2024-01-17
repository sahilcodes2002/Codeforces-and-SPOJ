//if the give number is prime or not .
//sum of factors can also be solves as we are checking the divisibility for every number <= sqrt(n) , similarly getting the other factor by deviding .


#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;
	cin>>n;
	int count=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			count++;
			if(n/i!=i){
				count++;
			}
		}
	}
	if(count>2){
		cout<<"not prime"<<endl;
		return 0;
	}
	cout<<"prime"<<endl;
	return 0;
}
