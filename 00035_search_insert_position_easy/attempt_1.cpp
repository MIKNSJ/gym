class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { 
        if (nums[nums.size() - 1] < target) {
            return nums.size();
        }

        if (nums[0] > target) {
            return 0;
        }

        int idx = nums.size() / 2;
        int prev = nums[0]; 

        if (nums[idx] < target) {
            prev = nums[idx];

            for (int i = idx; i < nums.size(); i++) {
                if (nums[i] == target) {
                    return i;
                }

                if (prev < target && target < nums[i]) {
                    return i;
                }

                prev = nums[i];
            }
        } else if (nums[idx] > target) {
            for (int i = 0; i < idx; i++) {
                if (nums[i] == target) {
                    return i;
                }

                if (prev < target && target < nums[i]) {
                    return i;
                }

                prev = nums[i];
            }
        }

        return idx;
    }
};
