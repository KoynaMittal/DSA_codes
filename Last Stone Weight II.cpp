// https://leetcode.com/problems/last-stone-weight-ii/

class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int n=a.size();
        int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=a[i];
	    }
	    
	    vector<vector<int>>dp(n+1,vector<int>(sum+1));
	    
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0]=1;
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(a[i-1]<=j)
	            {
	                dp[i][j]=dp[i-1][j]|dp[i-1][j-a[i-1]];
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    
	    for(int i=sum/2;i>=0;i--)
	    {
	        if(dp[n][i])
	        {
	            return sum-i*2;
	        }
	    }
	    
	    return sum;
    }
};