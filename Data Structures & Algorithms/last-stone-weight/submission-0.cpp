class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int x = stones[stones.size() - 2];
            int y = stones[stones.size() - 1];
            if (x == y) {
                stones.erase(stones.end() - 2, stones.end());
            } else if (x < y) {
                y = y - x;
                stones.erase(stones.end() - 2, stones.end());
                stones.push_back(y);
            }
        }
        return stones.size() == 1 ? stones[0] : 0;
    }
};
// 2,2,3,4,6
