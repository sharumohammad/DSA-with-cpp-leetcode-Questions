/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Pair{
    public:
    int yes;
    int no;
    Pair(){
        yes=no=0;
    }
};
class Solution {
public:
     Pair maxVal(TreeNode* node){
        if(node==NULL)return Pair();
        Pair lpair = maxVal(node->left);
       Pair rpair = maxVal(node->right);
       Pair mpair;
       mpair.yes=node->val+lpair.no+rpair.no;
       mpair.no=0+max(lpair.yes,lpair.no)+max(rpair.yes,rpair.no);
       return mpair;
     }
    int rob(TreeNode* root) {
        Pair res=maxVal(root);
        return max(res.yes,res.no);
    }
};