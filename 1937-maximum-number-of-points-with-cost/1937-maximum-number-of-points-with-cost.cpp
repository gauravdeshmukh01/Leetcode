class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> dp(points[0].begin(), points[0].end());

        for (int r = 1; r < m; ++r) {
            vector<long long> new_dp(n, 0);

            vector<long long> left_max(n, 0);
            left_max[0] = dp[0];
            for (int c = 1; c < n; ++c) {
                left_max[c] = max(left_max[c - 1] - 1, dp[c]);
            }

            vector<long long> right_max(n, 0);
            right_max[n - 1] = dp[n - 1];
            for (int c = n - 2; c >= 0; --c) {
                right_max[c] = max(right_max[c + 1] - 1, dp[c]);
            }

            for (int c = 0; c < n; ++c) {
                new_dp[c] = points[r][c] + max(left_max[c], right_max[c]);
            }

            dp = new_dp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
