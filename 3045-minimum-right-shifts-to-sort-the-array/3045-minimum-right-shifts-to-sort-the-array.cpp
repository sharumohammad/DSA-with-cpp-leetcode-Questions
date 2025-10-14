class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int count=0,ind=-1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                count++;
                ind=i;
            }
        }
        if(count==0) return 0;
        if(count>1) return -1;
        if(nums[n-1]>nums[0])return -1;
        return n-(ind+1);
    }
};