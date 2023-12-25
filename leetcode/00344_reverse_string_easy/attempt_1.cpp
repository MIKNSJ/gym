// December 25, 2023

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        char copy;

        while (left <= right) {
            copy = s[left];
            s[left] = s[right];
            s[right] = copy;
            left++;
            right--;
        }
    }
};
