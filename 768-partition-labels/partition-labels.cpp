class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char,int> mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
        }
        
        int last_index=0;
        int start = 0;

        for(int i=0;i<n;i++){
            last_index = max(last_index,mp[s[i]]);

            if(i==last_index){
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        
        return ans;
    }
};