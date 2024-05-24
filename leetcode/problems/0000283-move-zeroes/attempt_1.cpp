// January 6, 2024

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int copy;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == 0 and nums[j] != 0) {
                    copy = nums[i];
                    nums[i] = nums[j];
                    nums[j] = copy;
                }
            }
        }
    }
};
