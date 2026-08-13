class Solution {
public:
    void removeAdjDup(string &s, int currIdx, string &str){
        if(currIdx == s.size()) return;
        if(!str.empty() && str.back() == s[currIdx]) str.pop_back();
        else str.push_back(s[currIdx]);
        removeAdjDup(s, currIdx+1, str);
    }
    string removeDuplicates(string s) {
        string str = "";
        removeAdjDup(s, 0, str);
        return str;
    }
};