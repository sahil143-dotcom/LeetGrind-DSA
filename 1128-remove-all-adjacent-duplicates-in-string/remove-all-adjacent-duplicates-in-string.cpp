class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>stk;
        string str = "";
        for(auto c: s){
            if(!stk.empty() && stk.top() == c ){
                stk.pop();
                str.pop_back();
            }
            else{
                stk.push(c);
                str.push_back(c);
            }
        }
        return str;
    }
};