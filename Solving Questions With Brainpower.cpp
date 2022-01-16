// https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution {
public:
    vector<long long>dp;
    
    long long cal(int i,int n, vector<vector<int>>& a)
    {
        if(i>=n){return 0;}
        
        if(dp[i]!=-1){return dp[i];}
        
        return dp[i]=max(a[i][0]+(long long)cal(i+a[i][1]+1,n,a),(long long)cal(i+1,n,a));
    }
    
    long long mostPoints(vector<vector<int>>& a) {
        
        int n=a.size();
        dp.resize(n+1,-1);
        return cal(0,n,a);
    }
};