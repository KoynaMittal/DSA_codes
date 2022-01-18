// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& a, int amount) {
        
        int n=a.size();
        int maxn=1000000009;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,maxn));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        
        if(amount==0){return 0;}
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(a[i-1]<=j)
                {
                    dp[i][j]=min(1+dp[i][j-a[i-1]],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        if(dp[n][amount]==maxn){return -1;}
        return dp[n][amount];
    }
};