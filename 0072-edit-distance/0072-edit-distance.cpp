class Solution {
public:
    int minDistance(string word1, string word2) {

        int m = word1.length();
        int n = word2.length();

        // dp[i][j] = minimum operations to convert
        // first i characters of word1
        // into first j characters of word2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // word1 -> empty string
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }

        // empty string -> word2
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        // Traverse the DP table
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (word1[i] == word2[j]) {

                    dp[i + 1][j + 1] = dp[i][j];

                } else {

                    // Delete:
                    // dp[i][j + 1]
                    int deleteOp = dp[i][j + 1];

                    // Insert:
                    // dp[i + 1][j]
                    int insertOp = dp[i + 1][j];

                    // Replace:
                    // dp[i][j]
                    int replaceOp = dp[i][j];

                    dp[i + 1][j + 1] =
                        1 + min({deleteOp, insertOp, replaceOp});
                }
            }
        }

        return dp[m][n];
    }
};