class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        memo = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, s);
    }

private:
    vector<vector<int>> memo;

    bool dfs(int i, int open, const string& s) {
        if (open < 0) return false;
        if (i == s.size()) return open == 0;

        if (memo[i][open] != -1) return memo[i][open] == 1;

        bool result;
        if (s[i] == '(') {
            result = dfs(i + 1, open + 1, s);
        } else if (s[i] == ')') {
            result = dfs(i + 1, open - 1, s);
        } else {
            result = (dfs(i + 1, open, s) ||
                      dfs(i + 1, open + 1, s) ||
                      dfs(i + 1, open - 1, s));
        }

        memo[i][open] = result ? 1 : 0;
        return result;
    }
};