// December 26, 2023

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        char copy;

        set<char> vowels;
        vowels.insert('a');
        vowels.insert('A');
        vowels.insert('e');
        vowels.insert('E');
        vowels.insert('i');
        vowels.insert('I');
        vowels.insert('o');
        vowels.insert('O');
        vowels.insert('u');
        vowels.insert('U');

        while (left <= right) {
            if (vowels.find(s[left]) != vowels.end() &&
                vowels.find(s[right]) != vowels.end()) {
                copy = s[left];
                s[left] = s[right];
                s[right] = copy;
                left++;
                right--;
            }
            
            else if (vowels.find(s[left]) == vowels.end() &&
                vowels.find(s[right]) != vowels.end()) {
                left++;
            }
            
            else if (vowels.find(s[left]) != vowels.end() &&
                vowels.find(s[right]) == vowels.end()) {
                right--;
            }
            
            else {
                left++;
                right--;
            }
        }

        return s;
    }
};
