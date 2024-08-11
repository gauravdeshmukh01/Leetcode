class Solution {
public:
    vector<int> twoPtr(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size() - 1;
        while (high - low >= k) {
            if (x - arr[low] > arr[high] - x) {
                low++;
            } else {
                high--;
            }
        }
        vector<int> ans;
        for (int i = low; i <= high; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPtr(arr, k, x);
    }
};