class Solution {
public:
    void solve(int idx, vector<vector<int>>& ans,
               vector<int>& output, vector<int>& nums, int target) {

        if (target == 0) {
            ans.push_back(output);
            return;
        }

        if (idx == nums.size())
            return;

        // Include
        if (nums[idx] <= target) {
            output.push_back(nums[idx]);

            solve(idx, ans, output, nums, target - nums[idx]);

            output.pop_back();
        }

        // Exclude
        solve(idx + 1, ans, output, nums, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        vector<int> output;

        solve(0, ans, output, nums, target);

        return ans;
    }
};