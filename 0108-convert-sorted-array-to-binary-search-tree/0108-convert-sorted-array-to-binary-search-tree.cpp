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
    TreeNode* solve(vector<int>& nums,int left, int right){
            if(left>right){ //continue recussion may lead to the condition so we need to keep track of this
                return NULL;
            }

            // middle of the nums array make a new node and name it root for middle

            int mid = left +(right-left)/2;

            TreeNode* root= new TreeNode(nums[mid]);

            //recursively travel the whole left and  right think that array is sorted
            root->left=solve(nums,left, mid-1);
            root->right=solve(nums,mid+1,right);

            return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // if nums is empty then nums.size()-1 is -1 so left>right that condition is laready coverd 

        return solve(nums, 0, nums.size()-1);
    }
};