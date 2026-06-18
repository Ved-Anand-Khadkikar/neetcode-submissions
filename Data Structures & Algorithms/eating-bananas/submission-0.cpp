class Solution {
   public:
    int maxNum(vector<int>& x, int n) {
        int num = INT_MIN;
        for (int i = 0; i < n; i++) {
            num = max(num, x[i]);
        }
        return num;
    }
    int calcHours(vector<int>& y, int bananas) {
        int n = y.size();
        int hours = 0;
        for (int i = 0; i < n; i++) {
            hours += ceil(double(y[i]) / double(bananas));
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int ans = INT_MAX;
        int high = maxNum(piles, n);
        while (low <= high) {
            int mid = (low + high) / 2;
            int totalHours = calcHours(piles, mid);
            if (totalHours <= h) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
