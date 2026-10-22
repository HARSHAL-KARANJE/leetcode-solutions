class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> inMST(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        int mstCost = 0;
        int count = 0;
        pq.push({0, 0});

        while (!pq.empty() && count < n) {
            auto [wt, u] = pq.top();
            pq.pop();
            if (inMST[u]) {
                continue;
            }
            mstCost += wt;
            inMST[u] = 1;
            count++;

            // neigh points
            for (int i = 0; i < n; i++) {
                if (!inMST[i]) {
                    int cost = abs(points[u][0] - points[i][0]) +
                               abs(points[u][1] - points[i][1]);

                    pq.push({cost, i});
                }
            }
        }
        return mstCost;
    }
};