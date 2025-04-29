class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int c=0;
      int a=0;
        for(int n:nums){
            if(c==0) {
                a=n;
            }
            c+=(n==a)? 1:-1;
        }
        return a;
    }
};