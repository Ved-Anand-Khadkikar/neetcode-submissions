class Solution {
   public:
    int maxNum(vector<int>& x) {
        int num = INT_MIN;
        for (int i = 0; i < x.size(); i++) {
            num = max(num, x[i]);
        }
        return num;
    }
    int calcHours(vector<int>& x, int bananas) {
        int hours = 0;
        for (int i = 0; i < x.size(); i++) {
            hours += ceil(double(x[i]) / double(bananas));
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int ans = INT_MAX;
        int high = maxNum(piles);
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
