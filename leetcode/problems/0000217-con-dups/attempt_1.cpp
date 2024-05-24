/* 
  April 2nd, 2024
  #include <map>
  #include <set>
  using namespace std;
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> count;

        for (int i = 0; i < nums.size(); i++) {
            if (count.find(nums[i]) == count.end()) {
                count.insert({nums[i], 0});
            } else {
                return true;
            }
        }

        return false;
    }
};
