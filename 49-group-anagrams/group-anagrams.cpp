class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;

        for (string s:strs) {
            string k = s;                       // copy original
            sort(k.begin(), k.end());           // sort the copy → fingerprint
            ans[k].push_back(s);                // group original under fingerprint
        }

        vector<vector<string>> result;
        for (auto& pair : ans) {
            result.push_back(pair.second);      // extract all groups
        }
        return result;
    }
};