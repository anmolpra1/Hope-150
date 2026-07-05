class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int curr = nums[0];
        int maxsum = nums[0];

        for (int i = 1; i < n; i++) {
            curr = max(nums[i], curr + nums[i]);
            maxsum = max(curr, maxsum);
        }

        return maxsum;
    }
};
