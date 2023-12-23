// December 21, 2023

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        unsigned int nonElements = 0;
        std::vector<int>::iterator itr = nums.begin();

            while (itr != nums.end()) {
                if (*itr == val) {
                    nums.erase(itr);
                } else {
                    nonElements++;
                    itr++;
                }
            }

        return nonElements;
    }
};
