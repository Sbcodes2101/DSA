class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_set<int> seen;
        unordered_set<string> result;

        int sum=0;
        int k = 10;
        // "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
        //  i
        unordered_map<char, int> mpp = {
            {'A', 0},
            {'C', 1},
            {'G', 2},
            {'T', 3}
        };

        for(int i=0;i<k;i++){
            int power = k-i-1;
            sum = sum + (pow(4,power)*mpp[s[i]]);
        }

        seen.insert(sum);

        for(int i=k;i<s.size();i++){
            sum = sum - (pow(4,k-1)*mpp[s[i-k]]);
            sum = sum*4;
            sum = sum+mpp[s[i]];

            if(seen.find(sum)!=seen.end()){
                result.insert(s.substr(i-k+1,k));
            }

            seen.insert(sum);
        }

        while(!result.empty()){
            string ans1 = *result.begin();
            result.erase(ans1);
            ans.push_back(ans1);
        }

        return ans;

    }
};