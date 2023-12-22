#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str_rev = "";
        string str_x = to_string(x);

        for (int i = str_x.length() - 1; i >= 0; i--) {
            str_rev+=str_x[i];
        }

        if (str_x == str_rev) {
            return true;
        }

        return false;
    }
};
