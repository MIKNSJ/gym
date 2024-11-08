class Solution {
    public:
        bool canAttendMeetings(vector<Interval>& intervals) {
            int prev_start_time = 0;
            int prev_end_time = 0;

            for (int i = 0; i < (int)intervals.size(); i++) {
                if (intervals[i].start >= prev_start_time &&
                    intervals[i].start < prev_end_time ||
                    intervals[i].end >= prev_start_time &&
                    intervals[i].end <= prev_end_time) {
                    return false;
                }
                prev_start_time = intervals[i].start;
                prev_end_time = intervals[i].end;
            }

            return true;
        }
};