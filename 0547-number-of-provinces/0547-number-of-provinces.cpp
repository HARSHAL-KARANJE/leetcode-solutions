class Solution {
public:
    void DSF(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                DSF(j, isConnected, visited);
            }
        }
    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provincess = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if(!visited[i]) {
                provincess++;
                DSF(i , isConnected , visited);
            }
        }

        return provincess;
    };
};