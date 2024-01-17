int n=100000000;
vector<bool> prime(n+1,true);
 

voide sieve(){
	for(int i=2;i<=n;i++){
		if(prime[i]){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=false;
			}
		}
	}
}
