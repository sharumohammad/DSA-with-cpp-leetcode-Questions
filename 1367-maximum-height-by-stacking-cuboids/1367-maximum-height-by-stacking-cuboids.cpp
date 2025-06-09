class Solution {
public:
bool check(vector<int> a,vector<int> b){
    if(b[0]<=a[0] && b[1]<=a[1] && b[2]<=a[2])
    return true;
    else return false;
}
int solveTab(int n,vector<vector<int>>& nums){
    vector<int> curRow(n+1,0);
    vector<int> nextRow(n+1,0);
    for(int cur=n-1;cur>=0;cur--){
        for(int prev=cur-1;prev>=-1;prev--){
            int incl=0;
            if(prev==-1||check(nums[cur],nums[prev])){
                incl = nums[cur][2]+nextRow[cur+1]; //height 
            }
                int excl=nextRow[prev+1];
                curRow[prev+1]=max(incl,excl);
            
            
        }
        nextRow=curRow;
    }
    return nextRow[0];
}  
    int maxHeight(vector<vector<int>>& cuboids) {
        //step1: sort all dimensions for every cuboid
        for(auto &a:cuboids){
            
            sort(a.begin(),a.end());
        }
        //step 2: sort all cuboids basis on width and length
        sort(cuboids.begin(),cuboids.end());
        //step3: use Longest increasing subsequence logic
    return solveTab(cuboids.size(),cuboids);

    }
};