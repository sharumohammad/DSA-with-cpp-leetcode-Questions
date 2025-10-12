class Solution {
public:
    string removeOuterParentheses(string s) {
        int openCount=0,closeCount=0,start=0;
        string res="";
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='('){
                openCount++;
            }
            else if(c==')') closeCount++;
            if(openCount==closeCount){
                res+=s.substr(start+1,i-start-1);
                start=i+1;
            }
        }
        return res;
    }
};