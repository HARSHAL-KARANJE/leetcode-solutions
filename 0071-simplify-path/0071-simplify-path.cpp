class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string current = "";

        for (int i = 0; i <= path.size(); i++) {

            if (i == path.size() || path[i] == '/') {

                if (current == "" || current == ".") {
                    // Ignore empty parts and "."
                }
                else if (current == "..") {
                    // Go one directory back
                    if (!st.empty())
                        st.pop();
                }
                else {
                    // Normal directory
                    st.push(current);
                }

                current = "";
            }
            else {
                current += path[i];
            }
        }

        string result = "";

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};