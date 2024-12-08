class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int slow = 0;
            int slow_two = 0;
            int fast = 0;
    
            while (true) {
                fast = nums[nums[fast]];
                slow = nums[slow];
    
                if (fast == slow) {
                    break;
                }
            }
    
            while (true) {
                slow_two = nums[slow_two];
                slow = nums[slow];
    
                if (slow == slow_two) {
                    break;
                }
            }
    
            return slow;
        }
    };