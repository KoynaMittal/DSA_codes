// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#

class Solution{
  public:
    int cutRod(int a[], int n) {
        
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i<=j)
                {
                    dp[i][j]=max(a[i-1]+dp[i][j-i],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }
};