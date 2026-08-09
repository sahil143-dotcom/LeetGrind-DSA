class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;    // quick exit

        int count[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[s[i]-'a']++;    // count letters in s
            count[t[i] - 'a']--;    // uncount letters in t
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;    // any non-zero → mismatch
        }
        return true;
    }
};