class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
       int s=0;
       long long sum=0;
       long long count=0;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        while(sum*(i-s+1)>=k){
            sum-=nums[s];
            s++;
        }
        count+=(i-s+1);
       } 
       return count;
    }
};