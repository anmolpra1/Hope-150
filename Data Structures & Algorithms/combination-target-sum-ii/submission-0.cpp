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
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
        
            if (nums[i] > target) {
                break;
             }
        
        output.push_back(nums[i]);

        solve(i + 1, ans, output, nums, target - nums[i]);

        output.pop_back();

        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        vector<int> output;

        sort(nums.begin(), nums.end());

        solve(0, ans, output, nums, target);

        return ans;
    }
};