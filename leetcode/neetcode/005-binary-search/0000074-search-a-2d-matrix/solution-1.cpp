class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int start_row = 0;
            int end_row = matrix.size() - 1;
            int mid_row;
            int start;
            int end;
            int mid;

            while (start_row <= end_row) {
                mid_row = floor((start_row + end_row) / 2);
                start = 0;
                end = matrix[mid_row].size() - 1;

                while (start <= end) {
                    mid = floor((start + end) / 2);
                    if (matrix[mid_row][mid] < target) {
                        start = mid + 1;
                    } else if (matrix[mid_row][mid] > target) {
                        end = mid - 1;
                    } else {
                        return true;
                    }
                }

                if (mid == start) {
                    end_row = mid_row - 1;
                } else {
                    start_row = mid_row + 1;
                }
            }

            return false;
        }
};