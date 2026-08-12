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
    TreeNode* insert(TreeNode* root, int val){
        if(root==NULL){
            return new TreeNode(val);// if after it reaches to our specific postion we need to crrate a node to place it there
        }

        //go left if we got like less than root at each level so it will be a recusiion 
        if(val<root->val){
            root->left = insert(root->left, val);
        }

        if(val>root->val){
            root->right= insert(root->right , val); // at each level we need to check that if less then left else write
        }

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root= NULL;//

       for(int val: preorder){// each  val from the preorder must pass through the insert function and search for its position and make a node and palce it their
           root= insert(root, val);
       }
       return root;
    }
};