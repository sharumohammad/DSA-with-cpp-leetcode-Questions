class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min_val=0;
        long long max_val=0;
        long long cur=0;
        for(int i:differences){
            cur+=i;
            min_val=min(min_val,cur);
            max_val=max(max_val,cur);

        }
        int count=(upper-lower)-(max_val-min_val)+1;
        return count>0? count:0;
    }
};