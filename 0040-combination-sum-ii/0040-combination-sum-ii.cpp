class Solution {
public:
    void findCombinations(int idx, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& ans) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);
            findCombinations(i + 1, candidates, target - candidates[i], current,ans);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        findCombinations(0, candidates, target, current, ans);
        return ans;
    } 
};
