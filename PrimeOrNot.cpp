//if the give number is prime or not .

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