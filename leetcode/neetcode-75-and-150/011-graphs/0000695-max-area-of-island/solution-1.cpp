class Solution {
    public:
        void visitNeighbors(vector<vector<int>> &grid, int x, int y,
            set<pair<int,int>> &visited, unsigned int &area) {
            if (x < 0 || x >= (int)grid.size() || y < 0 ||
                    y >= (int)grid[x].size()) {
                return;
            }

            if (grid[x][y] == 1 && 
                    visited.find(pair<int,int>(x,y)) == visited.end()) {
                visited.insert(pair<int,int>(x,y));
                ++area;
                visitNeighbors(grid, x, y - 1, visited, area);
                visitNeighbors(grid, x, y + 1, visited, area);
                visitNeighbors(grid, x - 1, y, visited, area);
                visitNeighbors(grid, x + 1, y, visited, area);
            }
                }



            int maxAreaOfIsland(vector<vector<int>>& grid) {
                unsigned int area = 0;
                unsigned int max_area = 0;
                set<pair<int, int>> visited;

                for (int i = 0; i < (int)grid.size(); i++) {
                    for (int j = 0; j < (int)grid[i].size(); j++) {
                        if (grid[i][j] == 1 &&
                                visited.find(pair<int,int>(i,j)) ==
                                visited.end()) {
                            visitNeighbors(grid, i, j, visited, area);
                        }

                        if (area > max_area) {
                            max_area = area;
                        }

                        area = 0;
                    }
                }
                return max_area;
        }
};