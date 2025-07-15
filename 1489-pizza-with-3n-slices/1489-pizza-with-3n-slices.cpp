class Solution {
public:
int solve(int index,int e,vector<int>& slices,int n,vector<vector<int>>& dp){
    if(n==0 || index > e){
        return 0;
    }
    if(dp[index][n]!=-1) return dp[index][n];
    int incl=slices[index]+solve(index+2,e,slices,n-1,dp);
    int excl=solve(index+1,e,slices,n,dp);
    return dp[index][n]= max(incl,excl);
    
}
    int maxSizeSlices(vector<int>& slices) {
        
        int k=slices.size();
        vector<vector<int>> dp(k,vector<int>(k,-1));
        int c1=solve(0,k-2,slices,k/3 ,dp);
         vector<vector<int>> dp2(k,vector<int>(k,-1));
        int c2=solve(1,k-1,slices,k/3,dp2);
        return max(c1,c2);
    }
};