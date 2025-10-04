class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int> res;
       unordered_map<int,int> mp;
       stack<int> st;
       for(int n:nums2){
        while(!st.empty() && n>st.top()){
            mp[st.top()]=n;
            st.pop();
        }
        st.push(n);
       } 
       while(!st.empty()){
        mp[st.top()]=-1;
        st.pop();
       }
       for(int n:nums1){
        res.push_back(mp[n]);
       }
       return res;
    }
};