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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart,
                    int inEnd, int poStart, int poEnd) {

        if (inStart > inEnd || poStart > poEnd) {
            return NULL; // no elements
        }

        int rootValue = postorder[poEnd];

        int index = inStart;
        while (inorder[index] != rootValue) {
            index++;
        }
    
        // Create root
        TreeNode* root = new TreeNode(rootValue);


        // as of now we have the root index in the inorder

        // number of elements in the leftsubtree
        int leftSize = index - inStart;

        // build left subtree
        root->left = solve(inorder, postorder, inStart, index - 1, poStart,
                           poStart + leftSize - 1);

        // build right subtree
        root->right = solve(inorder, postorder, index + 1, inEnd,
                            poStart + leftSize, poEnd-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         return solve(inorder, postorder, 0, inorder.size() - 1, 0,
              postorder.size() - 1);
    }
};