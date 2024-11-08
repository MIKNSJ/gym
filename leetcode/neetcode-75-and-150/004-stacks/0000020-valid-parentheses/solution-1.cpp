class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            map<char, char> conv;
            conv.insert({'}', '{'});
            conv.insert({']', '['});
            conv.insert({')', '('});
    
            for (int i = 0; i < (int)s.size(); i++) {
                if (conv.find(s[i]) != conv.end() && st.size() > 0) {
                    if (conv.at(s[i]) == st.top()) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    st.push(s[i]);
                }
            }
    
            if (st.size() > 0) {
                return false;
            }
    
            return true;
        }
};