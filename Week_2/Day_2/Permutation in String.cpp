class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Map;
        unordered_map<char, int> s2Map;
        int left = 0;

        if (s1.length() > s2.length()) {
            return false;
        }

        for (int i = 0; i < s1.length(); i++) {
            s1Map[s1[i]]++;
            s2Map[s2[i]]++;
        }

        if (s1Map == s2Map) {
            return true;
        }

        for (int right = s1.length(); right < s2.length(); right++) {
            char charRight = s2[right];
            s2Map[charRight]++;

            char charLeft = s2[left];
            s2Map[charLeft]--;

            if (s2Map[charLeft] == 0) {
                s2Map.erase(charLeft);
            }

            left++;

            if (s1Map == s2Map) {
                return true;
            }
        }

        return false;
    }
};