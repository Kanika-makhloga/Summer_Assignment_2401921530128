class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> pMap;
        unordered_map<char, int> sMap;
        vector<int> res;

        int left = 0;
        int count = p.length();

        if (s.length() < p.length()) {
            return res;
        }

        for (char c : p) {
            pMap[c]++;
        }

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            sMap[ch]++;

            if (pMap.count(ch) && sMap[ch] <= pMap[ch]) {
                count--;
            }

            if (right - left + 1 > p.length()) {
                char leftChar = s[left];

                if (pMap.count(leftChar) && sMap[leftChar] <= pMap[leftChar]) {
                    count++;
                }

                sMap[leftChar]--;

                if (sMap[leftChar] == 0) {
                    sMap.erase(leftChar);
                }

                left++;
            }

            if (count == 0) {
                res.push_back(left);
            }
        }

        return res;
    }
};