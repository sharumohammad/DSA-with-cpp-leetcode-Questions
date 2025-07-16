class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int eCount=0,oCount=0;
        int altEven=0,altOdd=0;
        for(int n:nums){
            int a=n%2;
            if(a==0){
                eCount++;
                altEven=altOdd+1;

            }
            else{
                oCount++;
                altOdd=altEven+1;
            }
        }
        return max({eCount,oCount,altEven,altOdd});
    }
};