class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const long long MOD = 1e9 + 7;

        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;

        // 1. Find previous smaller element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // 2. Find next smaller element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        // 3. Calculate contribution of every element
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long leftChoices = i - left[i];
            long long rightChoices = right[i] - i;

            long long contribution =
                arr[i] * leftChoices * rightChoices;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};