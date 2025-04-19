class Solution {
public:
 long long solve(vector<int>& v,int target){
    int l=0,r=v.size()-1;
    long long ans=0;
    while(l<r){
        int sum=v[l]+v[r];
        if(sum<target){
            ans+=(r-l);
            l++;
        }
        else
        r--;
    }
    return ans;
 }
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        sort(v.begin(),v.end());
       return solve(v,upper+1)-solve(v,lower);
    }
};