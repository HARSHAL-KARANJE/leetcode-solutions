class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while (!todo.empty()) {

            pair<TreeNode*, pair<int, int>> p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(node->val);

            if (node->left != NULL) {
                todo.push({node->left, {x - 1, y + 1}});
            }

            if (node->right != NULL) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (map<int, map<int, multiset<int>>>::iterator it = nodes.begin();
             it != nodes.end();
             it++) {

            vector<int> col;

            for (map<int, multiset<int>>::iterator itr = it->second.begin();
                 itr != it->second.end();
                 itr++) {

                col.insert(col.end(),
                           itr->second.begin(),
                           itr->second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};