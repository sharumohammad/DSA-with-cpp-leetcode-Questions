class Solution {
public:
int solve(int n){
    int sum=0;
    while(n>0){
         sum+=n%10;
        n/=10;
    }
    return sum;
}
    int countLargestGroup(int n) {
        unordered_map<int,int> digits;
        int m=0;
        for(int i=1;i<=n;i++){
            int sum=solve(i);
            digits[sum]++;
            m=max(m,digits[sum]);
        }
        int count=0;
        for(auto& pair:digits){
            if(pair.second==m)
            count++;
        }
        return count;
    }
};