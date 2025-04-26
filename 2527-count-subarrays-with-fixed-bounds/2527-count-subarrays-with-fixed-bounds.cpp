class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int p1=-1;
        int p2=-1;
        int c1=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < minK || nums[i] > maxK){
                c1=i;
            }
            if(nums[i]==minK)
            p1=i;
            if(nums[i]==maxK) p2=i;
            long long small=min(p1,p2);
            long long temp=small-c1;
            ans+=(temp<=0) ? 0:temp;
        }
        return ans;
    }
};