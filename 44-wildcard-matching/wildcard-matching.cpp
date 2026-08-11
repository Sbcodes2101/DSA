class Solution {
public:
    bool f(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return 1;
        if (j == 0)
            return 0;

        if (i == 0) {
            for (int k = 0; k < j; k++) {
                if (p[k] != '*')
                    return 0;
            }
            return 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
            return dp[i][j] = f(s, p, i - 1, j - 1, dp);
        }

        else if (p[j - 1] == '*') {
            return dp[i][j] = f(s, p, i, j - 1, dp) || f(s, p, i - 1, j, dp);
        }

        else {
            return dp[i][j] = 0;
        }
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return f(s, p, n, m, dp);
    }
};