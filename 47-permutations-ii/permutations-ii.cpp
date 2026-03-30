class Solution {
public:
    void f(vector<int> &nums,vector<bool> &curr,vector<int> &ans1,set<vector<int>> &ans){
        if(ans1.size()==nums.size()){
            ans.insert(ans1);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(curr[i]==false) {
            ans1.push_back(nums[i]);
            curr[i] = true;
            f(nums,curr,ans1,ans);
            ans1.pop_back();
            curr[i]=false;
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> ans1;
        int n = nums.size();
        vector<bool> curr(n,false);
        f(nums,curr,ans1,ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};