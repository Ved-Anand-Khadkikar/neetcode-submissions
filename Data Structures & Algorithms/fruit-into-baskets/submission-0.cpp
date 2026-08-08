class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = INT_MIN;
        for (int i = 0; i < fruits.size(); i++) {
            unordered_set<int> st;
            for (int j = i; j < fruits.size(); j++) {
                st.insert(fruits[j]);
                if (st.size() > 2) {
                    break;
                }
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};