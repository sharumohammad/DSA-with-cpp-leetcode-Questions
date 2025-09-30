class Solution {
public:
    bool check(vector<int>& nums) {
       int n=nums.size();
        if(n<=1) return true;
        
        int d=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) d++;
            if(d>1) return false;
        }
        if(nums[n-1]>nums[0]) d++;
        return d<=1;
    }
};