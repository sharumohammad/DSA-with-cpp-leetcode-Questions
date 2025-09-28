class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxfreq=0;
        for(int i:nums){
            mp[i]++;
            maxfreq=max(maxfreq,mp[i]);
        }
        int res=0;
        for(auto i:mp){
            if(i.second==maxfreq) res+=i.second;
        }
        return res;

    }
};