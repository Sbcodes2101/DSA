class Solution {
public:
    // void sum(int idx,vector<int>& candidates, int target,vector<int> &curr,vector<vector<int>>& ans,int s) {
    //     int n = candidates.size();

    //     if (s == target) {
    //         ans.push_back(curr);
    //         return;
    //     }
        
    //     if(idx == n || s > target) return;

        
    //     curr.push_back(candidates[idx]);
    //     sum(idx,candidates,target,curr,ans,s+candidates[idx]);
    //     curr.pop_back();
        
        
    //     sum(idx+1,candidates,target,curr,ans,s);

    // }

     void sum(int idx, vector<int>& candidates, int target, vector<int> &curr,vector<vector<int>> &ans){
        int n = candidates.size();
        if(target==0){
            ans.push_back(curr);
            return;
        }

        if(idx==n) return;

        if(target>0){
            curr.push_back(candidates[idx]);
            sum(idx,candidates,target-candidates[idx],curr,ans);
            curr.pop_back();
        }

        sum(idx+1,candidates,target,curr,ans);
    
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sum(0,candidates,target,curr,ans);
        return ans;
    }
};