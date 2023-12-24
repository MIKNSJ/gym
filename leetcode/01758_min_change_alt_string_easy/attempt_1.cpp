// December 23, 2023

#include <string>

class Solution {
public:
    int minOperations(string s) {
        int minOp = 0;
        int minOpTwo = 1;
        string t = s;
        
        if (s[0] == '0') {
            t[0] = '1';
        } else {
            t[0] = '0';
        }

        if (s.length() == 1) {
            return 0;
        }

        for (int i = 1; i < s.length(); i++) {
            if (s[i - 1] == s[i]) {
                if (s[i] == '0') {
                    s[i] = '1';
                } else {
                    s[i] = '0';
                }
                minOp++;
            }
        }

        for (int i = 1; i < t.length(); i++) {
            if (t[i - 1] == t[i]) {
                if (t[i] == '0') {
                    t[i] = '1';
                } else {
                    t[i] = '0';
                }
                minOpTwo++;
            }
        }

        if (minOp < minOpTwo) {
            return minOp;
        }

        return minOpTwo;
    }
};
