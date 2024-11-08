class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            vector<vector<int>> buckets(nums.size() + 1);
            vector<int> bucket;
            vector<int> mostFrequent;
            map<int,int> frequency;
            unsigned int count;
    
            if (nums.size() == 0) {
                return mostFrequent;
            }
    
            if (nums.size() == 1) {
                mostFrequent.push_back(nums[0]);
                return mostFrequent;
            }
    
            for (int i = 0; i < (int)nums.size(); i++) {
                if (frequency.find(nums[i]) == frequency.end()) {
                    frequency.insert({nums[i], 1});
                } else {
                    count = frequency.at(nums[i]);
                    frequency.erase(nums[i]);
                    frequency.insert({nums[i], ++count});
                }
            }
    
            for (auto pair : frequency) {
                buckets[pair.second].push_back(pair.first);
            }
    
            for (int i = (int)buckets.size() - 1; i >= 0; i--) {
                if ((int)mostFrequent.size() == k) {
                    break;
                }
    
                if (buckets[i].size() > 0) {
                    for (int j = 0; j < (int)buckets[i].size(); j++) {
                        if ((int)mostFrequent.size() == k) {
                            break;
                        }
    
                        mostFrequent.push_back(buckets[i][j]);
                    }
                }
            }
    
            return mostFrequent;
        }
};