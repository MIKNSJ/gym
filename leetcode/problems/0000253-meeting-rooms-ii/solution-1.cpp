// 2024-06-01

class Solution {
    public:
        static bool startCMP(Interval i, Interval j) {
            return i.start < j.start;
        }

        static bool endCMP(Interval i, Interval j) {
            return i.end < j.end;
        }

        int minMeetingRooms(vector<Interval>& intervals) {
            if (intervals.size() < 2) {
                return intervals.size();
            }

            unsigned int min_days = 0;
            unsigned int days = 0;
            unsigned int s_idx = 0;
            unsigned int e_idx = 0;
            vector<int> start_times;
            vector<int> end_times;
            sort(intervals.begin(), intervals.end(), startCMP);

            for (int i = 0; i < (int)intervals.size(); i++) {
                start_times.push_back(intervals[i].start);
            }
            sort(intervals.begin(), intervals.end(), endCMP);

            for (int i = 0; i < (int)intervals.size(); i++) {
                end_times.push_back(intervals[i].end);
            }

            while (s_idx != start_times.size()) {
                if (start_times[s_idx] < end_times[e_idx]) {
                    ++days;
                    ++s_idx;
                }

                if (days > min_days) {
                    min_days = days;
                }
                
                if (start_times[s_idx] >= end_times[e_idx]) {
                    --days;
                    ++e_idx;
                }
            }
            return min_days;
        }
};
