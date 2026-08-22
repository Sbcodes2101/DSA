class Solution {
public:
    // Too much time complexity
    // bool helper(string &word1,string &word2,int idx,string &ans){
    //     if(idx==word2.size()){
    //         if(ans == word1) return true;
    //         else return false;
    //     }

    //     ans += word2[idx];
    //     bool pick = helper(word1,word2,idx+1,ans);
    //     ans.pop_back();
    //     bool not_pick = helper(word1,word2,idx+1,ans);

    //     return pick||not_pick;
    // }

    bool helper(string& word1, string& word2, int i, int j) {
        if (i == word1.size())
            return true;
        if (j == word2.size())
            return false;

        if (word1[i] == word2[j])
            return helper(word1, word2, i + 1, j + 1);
        else
            return helper(word1, word2, i, j + 1);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        vector<int> LSC(n, 1);
        int ans = 1;

        for (int i = 1; i < words.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if(words[j].size()+1==words[i].size()){
                    if (helper(words[j], words[i], 0, 0) && LSC[i] < LSC[j] + 1) {
                    LSC[i] = 1 + LSC[j];
                }
                }
            }

            ans = max(ans, LSC[i]);
        }

        return ans;
    }
};