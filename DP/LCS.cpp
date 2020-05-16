//Problem: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
//Solution: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
 {
	int T;
	cin >> T;
    int dp[100][100];
    
	while(T--)
	{
	    int n1, n2;
	    cin >> n1 >> n2;
	    
	    string str1, str2;
	    cin >> str1;
	    cin >> str2;
        // vector<vector<int> > dp( n1 , vector<int> (n2, 0)); 
	    if(str1[0] == str2[0])
	    {
	        dp[0][0] = 1;
	    }
	    else
	    {
	        dp[0][0] = 0;
	    }
	    for(int i=1; i<n1; i++)
	    {
	        if(str1[i] == str2[0])
	        {
	            dp[i][0] = 1;
	        }
	        else
	        {
	            dp[i][0] = dp[i-1][0];
	        }
	    }
	    for(int j=1; j<n2; j++)
	    {
	        if(str1[0] == str2[j])
	        {
	            dp[0][j] = 1;
	        }
	        else
	        {
	            dp[0][j] = dp[0][j-1];
	        }
	    }
	    
	    for(int i=1; i<n1; i++)
	    {
	        for(int j=1; j<n2; j++)
	        {
	            if(str1[i] == str2[j])
	            {
	                dp[i][j] = dp[i-1][j-1] + 1;
	            }
	            else
	            {
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    for(int i=0; i<n1; i++)
	    {
	        for(int j=0; j<n2; j++)
	        {
	           // cout << dp[i][j] << " ";
	        }
	       // cout << endl;
	    }
	    cout << dp[n1-1][n2-1] << endl;
	}
	return 0;
}