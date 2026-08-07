class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL)
            return 0;

        long long maxWidth = 0;

        queue<pair<TreeNode*, long long>> q;

        q.push({root,0});

        while(!q.empty()){

            int size = q.size();

            long long minIndex = q.front().second;

            long long first,last;

            for(int i=0;i<size;i++){

                TreeNode* node = q.front().first;

                long long idx = q.front().second - minIndex;

                q.pop();

                if(i==0)
                    first = idx;

                if(i==size-1)
                    last = idx;

                if(node->left)
                    q.push({node->left,2*idx+1});

                if(node->right)
                    q.push({node->right,2*idx+2});
            }

            maxWidth = max(maxWidth,last-first+1);
        }

        return maxWidth;
    }
};