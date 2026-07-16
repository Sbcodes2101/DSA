class Solution {
public:
    void f(vector<vector<int>> &ans,vector<int> &ans1,vector<int> &nums,int idx){
        if(idx==nums.size()){
            ans.push_back(ans1);
            return;
        }

        f(ans,ans1,nums,idx+1);
        ans1.push_back(nums[idx]);
        f(ans,ans1,nums,idx+1);
        ans1.pop_back();

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ans1;
        f(ans,ans1,nums,0);
        return ans;
    }
};