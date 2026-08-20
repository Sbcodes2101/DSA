class Solution {
public:
    static bool comp(vector<int>& first,vector<int>& second){
        if(first[0]==second[0]) return first[1]>second[1];
        
        return first[0]<second[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        int n = envelopes.size();
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for(int i=1;i<n;i++){
            int idx = lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
            if(idx==ans.size()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                ans[idx] = envelopes[i][1];
            }
        }
        return ans.size();
    }
};