class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_set<string> seen;
        unordered_set<string> result;

        int n = s.size()-10;
        for(int i=0;i<=n;i++){
            string st = s.substr(i,10);
            if(seen.find(st)!=seen.end()){
                result.insert(st);
            }
            seen.insert(st);
        }

        while(!result.empty()){
            string ans1 = *result.begin();
            result.erase(ans1);
            ans.push_back(ans1);
        }

        return ans;

    }
};