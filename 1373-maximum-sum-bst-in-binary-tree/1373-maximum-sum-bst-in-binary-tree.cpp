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

    int ans = 0;

    vector<int> dfs(TreeNode* root) {

        // Empty tree
        if (root == NULL) {
            return {1, INT_MAX, INT_MIN, 0};
        }

        // Get information from left and right
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        // Check whether current subtree is BST
        if (left[0] && right[0] &&
            root->val > left[2] &&
            root->val < right[1]) {

            // Calculate sum
            int sum = left[3] + right[3] + root->val;

            // Update maximum answer
            ans = max(ans, sum);

            // Calculate minimum and maximum
            int minimum = min(root->val, left[1]);
            int maximum = max(root->val, right[2]);

            // Return information about current subtree
            return {1, minimum, maximum, sum};
        }

        // Current subtree is NOT a BST
        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};