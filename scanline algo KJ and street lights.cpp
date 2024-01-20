//https://www.hackerrank.com/contests/ab-yeh-kar-ke-dikhao/challenges/kj-and-street-lights/problem


// KJ and street lightslocked



// Kartik Joshi (KJ) has a very beautiful girlfriend, Priyanka Sharma (PS). (hehe :P)

// She's very possesive and calls KJ and asks him to come tonight at her home to (most probably) meet.

// KJ and PS lives on x - axis. KJ's house is located on 0 and PS's house is located on p (a positive integer). There is only one road through which people can travel i.e. the x - axis. There are n street lights on the x - axis. The ith street light is situated at xi and has a characteristic ri so that it can spread light in the range [xi - ri, xi + ri]. The street lights emit rays which are self destructive in nature, which means that if there is some integer co-ordinate of road receiving light from more than one street lights, then the light on that co-ordinate vanishes, i.e. that co-ordinate remains dark.

// We all know that KJ is a kid and is afraid of dark. So he wishes to know before hand the maximum continuous number of integer co-ordinates he has to travel in the dark while going from his home to PS's home. Help him find the answer!

// Note: There may be more than one street light on the same integer co-ordinates. Also note that KJ always moves in the direction of PS's house.

// You don't need to care about the points whose co-ordinates lies outside the range [0, p].

// Input Format

// The first line contains two space seperated integers n and p, the number of street lights and the position of PS's house on x - axis.

// The next n lines contain two space seperated integers, xi and ri, the position of the ith street light and the characteristic of the ith street light.

// Constraints

// 1 <= p <= 2,00,000

// 0 <= n <= 2,00,000

// 0 <= xi <= p

// 0 <= ri <= 2,00,000

// Output Format

// Output a single integer, the maximum number of continuous integer co-ordinates KJ has to travel in the dark while going from his house on 0 to PS's house on p.

// Sample Input 0

// 4 4
// 1 2
// 3 0
// 0 2
// 3 0
// Sample Output 0

// 5
// Explanation 0

// The points lit by first street light are : {0, 1, 2, 3}

// The points lit by second street light are : {3}

// The points lit by third street light are : {0, 1, 2}

// The points lit by fourth street light are : {3}

// So, the points : {0, 1, 2, 3} will recieve light from more than one street light and hence will remain dark, also the point {4} doesn't receive light from any of the street lights, so it will also remain dark. Hence the maximum continuous integer points that will remain dark are {0, 1, 2, 3, 4}.So, the answer is 5.

// Sample Input 1

// 0 4
// Sample Output 1

// 5
// Explanation 1

// Since, there is no street light so all the points {0, 1, 2, 3, 4} will remain dark. So, the answer is 5.

// Sample Input 2

// 2 7
// 2 0
// 6 2
// Sample Output 2

// 2
// Explanation 2

// The points lit by first street light are : {2}

// The points lit by second street light are : {4, 5, 6, 7}

// So, the points : {0, 1}, {3} will remain dark.Hence the maximum continuous integer points that will remain dark are {0, 1}.So, the answer is 2






#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int lamps,desti;
    cin>>lamps>>desti;
    vector<int> arr(desti+2,0);  //we need index till desti + 1 as for scanline algo we do compution for each query as left(bigning of rnge) , right(end of range) + 1;

    while(lamps--){
    	int l,r;
    	cin>>l>>r;
    	arr[max(0,l-r)]+=1;  // left is index of street light - range of right ;
    	arr[min(desti+1,l+r+1)]+=-1; // right + 1 is index of street light + range of right +1;
    }

    for(int i=1;i<=desti;i++){
    	arr[i]+=arr[i-1];
    }

    int mx=0;
    int count=0;
    for(int i=0;i<=desti;i++){
    	if(arr[i]!=1){
    		count++;
    		mx=max(mx,count);
    	}
    	else{
    		count=0;
    	}
    }
    cout<<mx;
    return 0;
}
