class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes,
                      vector<int>& runningCosts,
                      long long budget) {

        int n = chargeTimes.size();

        deque<int> dq;
        long long sum = 0;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            sum += runningCosts[right];

            while (!dq.empty() &&
                   chargeTimes[dq.back()] <= chargeTimes[right]) {
                dq.pop_back();
            }

            dq.push_back(right);

            while (!dq.empty() &&
                   chargeTimes[dq.front()]
                   + (right - left + 1) * sum > budget) {

                if (dq.front() == left) {
                    dq.pop_front();
                }

                sum -= runningCosts[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};