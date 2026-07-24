class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0;
        int rightSum = 0;
        int r = n - 1;
        int maxSum;

        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        maxSum = leftSum;
        for (int i = k - 1; i >= 0; i--) {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[r];
            r--;
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};