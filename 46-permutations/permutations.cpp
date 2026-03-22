class Solution {
public:
    void f(vector<int> &nums,vector<bool> &curr,vector<int> &ans1,vector<vector<int>> &ans){
        if(ans1.size()==nums.size()){
            ans.push_back(ans1);
            curr[nums.size()]=false;
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(curr[i]==true) {
            ans1.push_back(nums[i]);
            curr[i] = false;
            f(nums,curr,ans1,ans);
            ans1.pop_back();
            curr[i]=true;
            }
            else if(curr[i]==false) continue;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<bool> curr(n,true);
        vector<int> ans1;
        f(nums,curr,ans1,ans);
        return ans;
    }
};