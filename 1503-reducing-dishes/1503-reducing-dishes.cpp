class Solution {
public:
int solve(vector<int> & sat){
    int n=sat.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<int> cur(n+1,0);
    vector<int> next(n+1,0);
    for(int i=n-1;i>=0;i--){
        for(int t=i;t>=0;t--){
            int incl=sat[i]*(t+1)+next[t+1];
            int excl=next[t];
            cur[t]=max(incl,excl);
        }
        next=cur;
    }
    return next[0];
}
    int maxSatisfaction(vector<int>& satisfaction) {
      sort(satisfaction.begin(),satisfaction.end());
      return  solve(satisfaction);
    }
};