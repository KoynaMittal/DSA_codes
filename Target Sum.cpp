class Solution {
public:
    int findTargetSumWays(vector<int>&a, int t) {
        
        int sum=0;
        int n=a.size();
        
        for(auto i:a)
        {
            sum+=i;
        }
        
        if((sum+t)%2!=0){return 0;}
        int fnl=(sum+abs(t))/2;
        // cout<<fnl<<endl;
        
        vector<vector<int>>dp(n+1,vector<int>(fnl+1));
        int zero=0;
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=pow(2,zero);
            
            if(i<n && a[i]==0){zero++;}
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=fnl;j++)
            {
                if(a[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][fnl];
    }
};