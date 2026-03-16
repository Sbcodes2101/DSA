class Solution {
public:
    void sum(int idx, vector<int>& candidates, int target, vector<int> &curr,vector<vector<int>> &ans){
    //     int n = candidates.size();
    //     if(target==0){
    //         st.insert(curr);
    //         return;
    //     }

    //     if(idx==n) return;

    //     if(target>0){
    //         curr.push_back(candidates[idx]);
    //         sum(idx+1,candidates,target-candidates[idx],curr,st);
    //         curr.pop_back();
    //     }
    //     sum(idx+1,candidates,target,curr,st);
           int n= candidates.size();

           if(target==0){
            ans.push_back(curr);
            return;
           }

           for(int i=idx;i<n;i++){
            if(i>idx && candidates[i-1]==candidates[i]) continue;
            if(candidates[i]>target) break;
            curr.push_back(candidates[i]);
            sum(i+1,candidates,target-candidates[i],curr,ans);
            curr.pop_back();
           }
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        sum(0,candidates,target,curr,ans);
        return ans; 
    }
};