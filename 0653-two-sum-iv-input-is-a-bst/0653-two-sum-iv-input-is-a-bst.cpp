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
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==NULL){
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
        
    }

    bool twoSum(vector<int>ans, int k){
        unordered_map<int, int>mp;

        for(int i= 0 ; i<ans.size();i++){
         int need = k-ans[i];
         if(mp.find(need)!= mp.end()){
            return true;//remember mp.need is basically the index is our value
         }
        mp[ans[i]]=i; //study this; key val ;;;key is our val and value is our index traverse alwasys a key
      
        }

       return false; 

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
      
     return twoSum(ans,k);
    }
};