class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() &&
                   s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < s.size(); i++) {
            expand(i, i);      
            expand(i, i + 1);  
        }

        return s.substr(start, maxLen);
    }
};