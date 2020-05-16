//Problem: https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
//Solution: https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
 {
	int T;
	cin >>T;
	while(T--)
	{
	    int N;
	    cin >> N;
	    
	    int arr[N];
	    int sum = 0;
	    for(int i=0;i<N;i++)
	    {
	        cin >> arr[i];
	        sum+=arr[i];
	    }
	    if(sum%2 == 1)
	    {
	        cout << "NO" <<endl;
	    }
	    else
	    {
	        int target = sum/2;
	        bool dp[N+1][target + 1];
    	    
    	    
    	    dp[0][0] = true;
    	    
    	    for(int i=1; i<=target; i++ )
    	    {
    	        dp[0][i] = false;
    	    }
    	    
    	    for(int i=1; i<=N; i++)
    	    {
    	       
    	        for(int j=0; j<=target; j++)
    	        {
    	            if(arr[i-1] > j)
    	            {
    	                dp[i][j] = dp[i-1][j];
    	            }
    	            else
    	            {
    	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
    	            }
    	        }
    	    }
    	    
    	    bool ans = false;
    	    for(int k=0;k<=N; k++)
    	    {
    	        if(dp[k][target] == true)
    	        {
    	            ans = true;
    	            break;
    	        }
    	    }
    	    if(ans)
    	    {
    	        cout << "YES" << endl;
    	    }
    	    else
    	    {
    	        cout << "NO" <<endl;
    	    }
	    }
	}
	return 0;
}