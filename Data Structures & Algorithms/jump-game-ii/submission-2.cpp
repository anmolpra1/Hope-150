class Solution {
    int n;
    vector<int> dp;

public:
    int solve(int i, vector<int>& nums) {
        if (i >= n - 1)
            return 0;

        if (nums[i] == 0)
            return INT_MAX;

        if (dp[i] != -1)
            return dp[i];

        int miniJumps = INT_MAX;

        for (int jump = 1; jump <= nums[i] && i + jump < n; jump++) {
            int next = solve(i + jump, nums);

            if (next != INT_MAX) {
                miniJumps = min(miniJumps, 1 + next);
            }
        }

        return dp[i] = miniJumps;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);

        return solve(0, nums);
    }
};