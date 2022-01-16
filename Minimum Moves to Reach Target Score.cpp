// https://leetcode.com/problems/minimum-moves-to-reach-target-score/

class Solution {
public:
    int minMoves(int t, int db) {
        
        int ans=0;
        int n=t;
        while(t>1)
        {
            if(t%2==1)
            {
                t--;
            }
            else if(db>0)
            {
                t/=2;
                db--;
            }
            else
            {
                ans+=(t-1);
                break;
            }
            ans++;
        }
        
        return ans;
    }
};