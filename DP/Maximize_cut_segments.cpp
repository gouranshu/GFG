//Problem: https://practice.geeksforgeeks.org/problems/cutted-segments/0#ExpectOP
//Solution: https://www.geeksforgeeks.org/maximize-the-number-of-segments-of-length-p-q-and-r/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int len;
        cin >> len;
        int x,y,z;
        cin >> x >> y >> z;
        int dp[len + max(max(x,y),z)+1];
        dp[0] = 0;
        for(int i=1; i<=len;i++)
        {
            dp[i] = -1;
        }
        for(int i=0; i<=len; i++)
        {
            if(dp[i] == -1)
            {
                // cout << dp[i] << " ";
                continue;
            }
            dp[i+x] = max(dp[i+x],dp[i]+1);
            dp[i+y] = max(dp[i+y],dp[i]+1);
            dp[i+z] = max(dp[i+z],dp[i]+1);
            // cout << dp[i] << " ";
        }
        
        cout << dp[len] << endl;
    }
	return 0;
}