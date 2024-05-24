// December 22, 2023

#include <string>

class Solution {
public:
    int maxScore(string s) {
        int leftScore = 0;
        int rightScore = 0;
        int score = 0;
        int max_score = 0;
        int split = 1;

        while (split < s.length()) {
            for (int i = 0; i < split; i++) {
                if (s[i] == '0') {
                    leftScore++;
                }
            }

            for (int j = split; j < s.length(); j++) {
                if (s[j] == '1') {
                    rightScore++;
                }
            }

            score = leftScore + rightScore;

            if (max_score < score) {
                max_score = score;
            }

            split++;
            leftScore = 0;
            rightScore = 0;
            score = 0;
        }

        return max_score;
    }
};
