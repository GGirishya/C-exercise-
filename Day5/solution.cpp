class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        // empty strings
        if (n == 0) return "";

         // use dynamic progamming
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLength = 1;
        // Single characters are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // Check for palindromes of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        } 
        // Check for palindromes of length 3 or more
            for (int length = 3; length <= n; length++) {
                for (int i = 0; i <= n - length; i++) {
                    int j = i + length - 1;

                    if (s[i] == s[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        start = i;
                        maxLength = length;
                    }
                }
            }

            return s.substr(start, maxLength);
        }
};