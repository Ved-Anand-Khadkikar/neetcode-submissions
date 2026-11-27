class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int i = 0; i < stones.size(); i++) {
            maxHeap.push(stones[i]);
        }
        while (maxHeap.size() > 1) {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if (x < y) {
                y = y - x;
                maxHeap.push(y);
            } else if (x == y) {
                continue;
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
