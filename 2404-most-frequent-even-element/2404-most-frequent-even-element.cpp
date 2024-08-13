class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        int mostFrequent = -1;
        int highestFrequency = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                mp[nums[i]]++;
            }
        }

        for (auto& pair : mp) {
            if (pair.second > highestFrequency) {
                highestFrequency = pair.second;
                mostFrequent = pair.first;
            }
        }

        return mostFrequent;
    }
};
