class Solution {
   public:
    int maxNum(vector<int>& weights) {
        int num = INT_MIN;
        for (int i = 0; i < weights.size(); i++) {
            num = max(num, weights[i]);
        }
        return num;
    }
    int calcSum(vector<int>& weights) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }
        return sum;
    }

    int possible(vector<int>& weights, int cap) {
        int day = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > cap) {
                day++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = maxNum(weights);
        int maxCap = calcSum(weights);

        for (int i = minCap; i <= maxCap; i++) {
            int d = possible(weights, i);
            if (d <= days) {
                return i;
            }
        }
        return -1;
    }
};