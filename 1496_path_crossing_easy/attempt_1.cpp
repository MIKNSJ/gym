#include <vector>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;
        vector<pair<int,int>> points;
        pair<int,int> point = make_pair(x,y);
        points.push_back(point);

        for (int i = 0; i < path.length(); i++) {
            if (path[i] == 'N') {
                y++;
            } else if (path[i] == 'S') {
                y--;
            } else if (path[i] == 'E') {
                x++;
            } else {
                x--;
            }

            pair<int,int> point = make_pair(x,y);
            points.push_back(point);
        }

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i] == points[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};
