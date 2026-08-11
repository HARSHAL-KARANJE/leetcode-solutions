/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // level order treversal only each level in oppsite order to store
        vector<vector<int>> ans; // each level all elements

        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        bool lefttoright =
            true; // in each loop we check this and insert to each level and at
                  // the end of loop we make it false

        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n); // eacjh level in the array and then at last
                                  // collect all the level
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = lefttoright ? i : n - 1 - i;
                level[index] = node->val; // Put node->val inside the array
                                          // level at position index.

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            // Entire current level is now complete
            ans.push_back(level);

            // Change direction for next level
            lefttoright = !lefttoright;
        }
        return ans;
    }
};