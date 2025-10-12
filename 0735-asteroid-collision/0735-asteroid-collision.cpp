class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int a:asteroids){
            bool dest=false;
            while(!st.empty() && a<0 && st.top()>0){
                if(abs(st.top())<abs(a)){
                    st.pop();
                    continue;
                }
                else if(abs(st.top())==abs(a)){
                   st.pop();
                    dest=true;
                    break;
                }
                else{
                    dest=true;
                    break;
                }
            }
            if(!dest) st.push(a);
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};