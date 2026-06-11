class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            int start = i;

            // move to end of word
            while (i < n && s[i] != ' ') {
                i++;
            }

            // reverse the word [start, i-1]
            reverse(s.begin() + start, s.begin() + i);

            // skip space
            i++;
        }

        return s;
    }
};