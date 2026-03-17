class Solution {
public:
    void f(int idx,vector<vector<int>> &ans,vector<int> &curr,vector<int> &nums){
        ans.push_back(curr);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            f(i+1,ans,curr,nums);
            curr.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        f(0,ans,curr,nums);
        return ans;
    }
};