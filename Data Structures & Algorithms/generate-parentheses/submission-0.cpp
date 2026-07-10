class Solution {
public:
    void solve(string s, int open, int close, vector<string> &ans, int n) {
        if (s.length() == n * 2) {
            ans.push_back(s);
            return;
        }

        if (open > close) {
            solve(s + ')', open, close + 1, ans, n);
        }

        if (open < n || s.empty()) {
            solve(s + '(', open + 1, close, ans, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(s, 0, 0, ans, n);
        return ans;
    }
};
