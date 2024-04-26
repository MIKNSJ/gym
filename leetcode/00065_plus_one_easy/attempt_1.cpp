// 2024-04-25

class Solution {
  public:
      vector<int> plusOne(vector<int>& digits) {
          int sum = 1;
  
          vector<int> result_rev(digits.size() + 1, 11);
          vector<int> result;
  
          for (int i = digits.size() - 1; i >= 0; i--) {
              sum += digits[i];
  
              if (sum >= 10) {
                  sum-=10;
                  result_rev[(digits.size() - 1) - i] = sum;
                  sum = 1;
              } else {
                  result_rev[(digits.size() - 1) - i] = sum;
                  sum = 0;
              }
              
          }
  
          if (sum == 1) {
              result_rev[(result_rev.size() - 1)] = sum;
          }
  
          if (result_rev[result_rev.size() - 1] == 11) {
              result_rev.erase(result_rev.cend() - 1);
          }
  
          for (int i = result_rev.size() - 1; i >= 0; i--) {
              result.push_back(result_rev[i]);
          }
  
          return result;
      }
};
