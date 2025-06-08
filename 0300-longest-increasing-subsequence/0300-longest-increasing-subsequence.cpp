class Solution {
public:
int solveMem(int n,vector<int>& nums,int cur,int prev,vector<vector<int>>& dp){
    if(cur==n) return 0;
    if(dp[cur][prev+1]!=-1) return dp[cur][prev+1];
    int incl=0;
    if(prev==-1||nums[cur]>nums[prev]){
        incl=1+solveMem(n,nums,cur+1,cur,dp);
    }
    int excl=solveMem(n,nums,cur+1,prev,dp);
    dp[cur][prev+1]=max(incl,excl);
    return dp[cur][prev+1];
}
//DP with Binary Search
int solveOpt(int n,vector<int>& nums){
    if(n==0) return 0;
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(nums[i]>ans.back()){
            ans.push_back(nums[i]);
        }
        else{
            int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            ans[index]=nums[i];
        }
    }
    return ans.size();
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solveMem(n,nums,0,-1,dp);
        return solveOpt(n,nums);
    }
};