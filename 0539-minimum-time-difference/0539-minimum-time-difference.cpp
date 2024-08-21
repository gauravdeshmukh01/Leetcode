class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(int i = 0; i < timePoints.size(); i++){
            string curr = timePoints[i];

            int hour = stoi(curr.substr(0,2));   // string to integer
            int minute = stoi(curr.substr(3,2));
            int totalmin = hour*60 + minute;
            minutes.push_back(totalmin);
        }
        sort(minutes.begin(),minutes.end());
        int n = minutes.size();
        int mini = INT_MAX;
        for(int i = 0; i < n-1; i++){
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini, diff);
        }
      // very imp circular time 12:00 means 00:00 , hence compare first and last also
        int lastdiff = (minutes[0] + 1440) - minutes[n-1];
         mini = min(mini, lastdiff);
        return mini;
    }
};