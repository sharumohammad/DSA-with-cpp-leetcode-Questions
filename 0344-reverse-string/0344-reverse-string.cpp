class Solution {
public:
    void reverseString(vector<char>& s) {
       // reverse(s.begin(),s.end());
       // two pointer approach
       int l=0,r=s.size()-1;
       while(l<r){
        swap(s[l],s[r]);
        l++;
        r--;
       }
    }
};