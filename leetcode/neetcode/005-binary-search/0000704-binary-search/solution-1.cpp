// 2024-05-27



class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int start = 0;
            int end = nums.size() - 1;
            int mid = floor(start + end / 2);
            cout << mid << endl;

            while (start <= end) {
                if (nums[mid] < target) {
                    start = mid + 1;
                } else if (nums[mid] > target) {
                    end = mid - 1;
                } else {
                    return mid;
                }
                mid = floor((start + end) / 2);
                cout << mid << endl;
            }

            return -1;
        }
};