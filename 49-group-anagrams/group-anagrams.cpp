class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        // sorting every element present inside the string array

        int n = strs.size();

        for(int i=0;i<n;i++){
            string ele = strs[i];
            sort(ele.begin(),ele.end());
            mp[ele].push_back(strs[i]);
        }

        for(auto& pair:mp){
            ans.push_back(pair.second);
        }

        return ans;
    }
};