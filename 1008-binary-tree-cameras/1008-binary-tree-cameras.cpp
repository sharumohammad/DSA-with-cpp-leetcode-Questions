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
class Solution {
public:
int camera=0;
    string minCamera(TreeNode* node){
     
       if(node==NULL) return "Covered";
        
        string lans=minCamera(node->left);
        string rans=minCamera(node->right);
        if(lans=="Need" || rans=="Need"){
            camera++;
            return "Camera";
        } 
        else if(lans=="Covered" && rans=="Covered"){
            return "Need";
        }
        return "Covered";
    }
    int minCameraCover(TreeNode* root) {
        
        string res=minCamera(root);
        if(res=="Need")camera++;
        return camera;
    }
};