class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] >= 'a' && s[i] <= 'z' && s[i + 1] >= 'a' &&
                s[i + 1] <= 'z') {
                sum += abs(s[i] - s[i + 1]);
            } else {
                return 0;
            }
        }

        return sum;
    }
};
