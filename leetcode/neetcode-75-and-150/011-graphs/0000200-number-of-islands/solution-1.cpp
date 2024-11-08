class Solution {
    public:
        void visitNeighbors(vector<vector<char>> &grid, int x, int y,
            set<pair<int,int>> &visited) {
            if (x < 0 || x >= (int)grid.size() || y < 0 ||
                    y >= (int)grid[x].size()) {
                return;
            }

            if (grid[x][y] == '1' && 
                    visited.find(pair<int,int>(x,y)) == visited.end()) {
                visited.insert(pair<int,int>(x,y));
                visitNeighbors(grid, x, y - 1, visited);
                visitNeighbors(grid, x, y + 1, visited);
                visitNeighbors(grid, x - 1, y, visited);
                visitNeighbors(grid, x + 1, y, visited);
            }
        }



        int numIslands(vector<vector<char>>& grid) {
            unsigned int num = 0;
            set<pair<int, int>> visited;

            for (int i = 0; i < (int)grid.size(); i++) {
                for (int j = 0; j < (int)grid[i].size(); j++) {
                    if (grid[i][j] == '1' &&
                            visited.find(pair<int,int>(i,j)) ==
                            visited.end()) {
                        visitNeighbors(grid, i, j, visited);
                        ++num;
                    }
                }
            }
            return num;
        }
};