//Problem: https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
//Solution: https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distan
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
 {
	int dp[51];
	int T;
	cin >>T;
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
    for(int i=3;i<=50; i++)
    {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
	while(T--)
	{
	    int N;
	    cin >> N;
	    cout << dp[N] << endl;
	}
	return 0;
}