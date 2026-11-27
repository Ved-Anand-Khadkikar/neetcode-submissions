class KthLargest {
   public:
    vector<int> arr;
    int K;

    KthLargest(int k, vector<int>& nums) {
        arr = nums;
        K = k;
        sort(arr.begin(), arr.end());
    }

    int add(int val) {
        int low = 0;
        int high = arr.size() - 1;
        int index = arr.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= val) {
                index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        arr.insert(arr.begin() + index, val);
        return arr[arr.size() - K];
    }
};
// 1,2,4,5  1,2,3,4,5  k=2