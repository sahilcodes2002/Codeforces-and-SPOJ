// https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/F

// F. Card Substrings
// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// Given a string s
//  and m
//  cards with letters. Your task is to count the number of substrings of the string s
//  that can be made from these cards.

// For example, if s=
//  «aaab», and there are three cards with the letters «a», «a», and «b», then you can make three substrings «a», substring «b», two substrings «aa», substrings «ab» and «aab». And you can not make the substrings «aaa» and «aaab», since there are only two cards with the letter «a».

// Input
// The first line of the input contains two integers n
//  and m
//  (1≤n,m≤105
// ), the length of the string and the number of cards.

// The second line of the input contains a string s
//  of length n
// .

// The third line of the input contains a string of length m
//  that specifies the letters written on the cards.

// Both strings consist of only lowercase letters of the English alphabet.

// Output
// Print one integer, the number of substrings in s
//  that can be made from these cards.

// Examples
// inputCopy
// 4 3
// aaab
// aba
// outputCopy
// 8
// inputCopy
// 7 3
// abacaba
// abc
// outputCopy
// 15



#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int m;
	cin>>n>>m;
	vector<char> str(n);
	vector<char> cards(m); 
	map<char, int> mp;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}

	for(int i=0;i<m;i++){
		cin>>cards[i];
		mp[cards[i]]++;
	}
	int j=0;
	int i=0;
	long long ans=0;
	while(i<n){
		
		mp[str[i]]--;
			
		while(j<i && mp[str[i]]<0){
			mp[str[j]]++;
			j++;
		}

		if(mp[str[i]]<0 && j==i){
			// therefore i==j and this character is not present in the cards.
			j++;//by doing j++ j is i+1 ( i-(i+1)+1)==0 and will not be added to the ans
		}
			
		ans+=((i-j)+1);
		i++;
	}

	cout<<ans<<endl;
	return 0;
}


