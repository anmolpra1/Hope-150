class Solution {
public:
void getSubset(vector<vector<int>> & ansfin, vector<int>& nums, int i, vector<int> &ans, int n){
    
    if(i == n){
        ansfin.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);

    getSubset(ansfin, nums, i+1, ans, n);

    ans.pop_back();
//used to check and remove the duplicate elements

    int idx = i+1;
    while(idx<n && nums[idx] == nums[idx-1]){
        idx++;
        }

        getSubset(ansfin, nums, idx, ans, n);
     
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ansfin; 
        vector<int> ans;
        int n = nums.size();
        getSubset(ansfin, nums, 0, ans, n);
        return ansfin;
    }
};