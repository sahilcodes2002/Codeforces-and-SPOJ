// D. Children Holiday
// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// The organizers of the children's holiday are planning to inflate m
//  balloons for it. They invited n
//  assistants, the i
// -th assistant inflates a balloon in ti
//  minutes, but every time after zi
//  balloons are inflated he gets tired and rests for yi
//  minutes. Now the organizers of the holiday want to know after what time all the balloons will be inflated with the most optimal work of the assistants, and how many balloons each of them will inflate. (If the assistant has inflated the balloon and needs to rest, but he will not have to inflate more balloons, then it is considered that he finished the work immediately after the end of the last balloon inflation, and not after the rest).

// Input
// The first line of the input contains integers m
//  and n
//  (0≤m≤15000,1≤n≤1000)
// . The next n
//  lines contain three integers each, ti
// , zi
// , and yi
// , respectively (1≤ti,yi≤100,1≤zi≤1000)
// .

// Output
// In the first line print the number T
// , the time it takes for all the balloons to be inflated. On the second line print n
//  numbers, the number of balloons inflated by each of the invited assistants. If there are several optimal answers, output any of them.

// Example
// inputCopy
// 1 2
// 2 1 1
// 1 1 2
// outputCopy
// 1
// 0 1 



#include<bits/stdc++.h>
using namespace std;

vector<int> final;

bool ispossible(int mid , vector<vector<int>> &arr, int m , int n){
	int total_b=0;
	vector<int> data(n,0);
	for(int i=0;i<n;i++){
		int left_balloons=m-total_b;
		int z=arr[i][0]*arr[i][1]+arr[i][2];
		int interval_balloons=mid/z*arr[i][1];
		int extra_balloons=min((mid%z)/arr[i][0],arr[i][1]);//here mid%z is time left and mid%z)/arr[i][0] will give the number of balloon he can inflate in the left time, but here it can be that no of balloons may be greater than what he can inflate in an interval as there is waiting time in interval too, for example (if the interval is of 10 min and 3 balloons can be inflated in that intervaol with 1 min time for inflating one balloon then, if the left time is 5 min then (mid%z)/arr[i][0] will give 5 ballons but he will  wait after 3 balloon as specified in a interval so we will take min of interval balloons and (mid%z)/arr[i][0] ;
		total_b+=interval_balloons+extra_balloons;
		data[i]=interval_balloons+extra_balloons;
		if(total_b>=m){
			data[i]=left_balloons;
			final=data;
			return true;
		}
	}
	return false;
}




int main(){
	int m ,n;
	cin>>m>>n;

	vector<vector<int>> arr(n);

	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){//time for each balloon , number of balloons , rest time.
			int x;
			cin>>x;
			arr[i].push_back(x);
		}
	}

	

	int mininterval=INT_MAX;
	int person=-1;
	for(int i=0;i<n;i++){
		int z=arr[i][0]*arr[i][1]+arr[i][2];
		if(z<mininterval){
			mininterval=z;
			person=i;
		}
		else if(z==mininterval){
			if(arr[person][0]>arr[i][0]){
				mininterval=z;
				person=i;
			}
		}
	}

	int intervals=m/arr[person][1]*mininterval;
	int leftouts=(m%arr[person][1])*arr[person][0];


	int l= -1;
	int r= intervals+leftouts;



	int ans=-1;
	while(l<=r){
		int mid=l+(r-l)/2;

		if(ispossible(mid,arr,m,n)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}

	cout<<ans<<endl;
	for(int i=0;i<n;i++){
		cout<<final[i]<<" ";
	}
	cout<<endl;
	return 0;

}
