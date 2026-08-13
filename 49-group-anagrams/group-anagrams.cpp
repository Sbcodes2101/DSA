class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        // sorting every element present inside the string array

        int n = strs.size();

        for(int i=0;i<n;i++){
            string ele = strs[i];
            vector<int> count(26,0);

            for(int j=0;j<ele.size();j++){
                count[ele[j]-'a']++;
            }

            string key = "";
            for(int k=0;k<26;k++){
                key += to_string(count[k])+'*';
            }

            mp[key].push_back(strs[i]);
        }

        for(auto& pair:mp){
            ans.push_back(pair.second);
        }

        return ans;
    }
};