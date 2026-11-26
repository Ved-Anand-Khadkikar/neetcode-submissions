class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        map<int, vector<vector<int>>> mp;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int distance = (x * x + y * y);
            mp[distance].push_back(points[i]);
        }
        for (auto &it : mp) {
            while (k > 0 && !it.second.empty()) {
                ans.push_back(it.second.back());
                it.second.pop_back();
                k--;
            }
            if (k == 0) {
                break;
            }
        }
        return ans;
    }
};
