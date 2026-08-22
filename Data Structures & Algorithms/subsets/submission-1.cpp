class Solution {
public:
vector<vector<int>> ans;

    void solve(int i, vector<int> &subset, vector<vector<int>> &ans, vector<int>& nums) {
        if(i >= nums.size()) {
            ans.push_back(subset);
            
            return;
        }

        // include
        subset.push_back(nums[i]);
        solve(i + 1, subset, ans, nums);

        // exclude
        subset.pop_back(); // backtrack
    
        solve(i + 1, subset, ans, nums);
    }    

        
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> subset;

        solve(0, subset, ans, nums);

        return ans;
    }
};
