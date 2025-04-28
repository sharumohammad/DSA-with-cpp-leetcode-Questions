class Solution {
public:
    int solve(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        int prev2=1;
        int prev1=2;
        for(int i=3;i<=n;i++){
            int ans=prev2+prev1;
            prev2=prev1;
            prev1=ans;
        }
      
        return prev1;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};