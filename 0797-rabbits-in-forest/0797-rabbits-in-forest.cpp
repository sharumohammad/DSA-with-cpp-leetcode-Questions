class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        for(auto i: answers){
            m[i]++;
        }
        int ans=0;
        for(auto i=m.begin();i!=m.end();i++){
            int a=(*i).first;
            int b=(*i).second;
            int c=b/(a+1);
            int r=b%(a+1);
            ans+=c*(a+1);
            if(r!=0){
                ans+=(a+1);
            }
        }
        return ans;
    }
};