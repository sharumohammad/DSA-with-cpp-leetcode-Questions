class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);
        stack<int> st;
        for(int i=0;i<2*n;i++){
            int ans=nums[i%n];
            while(!st.empty() && ans>nums[st.top()]){
                res[st.top()]=ans;
            st.pop();
            }

            if(i<n) st.push(i);
        }
        return res;
    }
};