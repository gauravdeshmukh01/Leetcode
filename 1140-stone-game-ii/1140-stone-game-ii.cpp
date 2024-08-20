class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> suffixSum(n);

        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }

        return helper(0, 1, piles, dp, suffixSum);
    }

private:
    int helper(int i, int M, vector<int>& piles, vector<vector<int>>& dp, vector<int>& suffixSum) {
        if (i >= piles.size()) return 0;
        if (2 * M >= piles.size() - i) return suffixSum[i];
        if (dp[i][M] != -1) return dp[i][M];

        int minOpponentStones = INT_MAX;
        for (int X = 1; X <= 2 * M; ++X) {
            minOpponentStones = min(minOpponentStones, helper(i + X, max(M, X), piles, dp, suffixSum));
        }

        dp[i][M] = suffixSum[i] - minOpponentStones;
        return dp[i][M];
    }
};
