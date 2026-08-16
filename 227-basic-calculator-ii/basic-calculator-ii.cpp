class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num =0;
        char operation = '+';
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }
            if((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1){
                if(operation == '+'){
                    st.push(num);
                }
                else if (operation == '-'){
                    st.push(-num);
                }
                else if (operation == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                else if (operation == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                operation = s[i];
                num = 0;
            }
        }
        int answer = 0;
        while (!st.empty()){
            answer += st.top();
            st.pop();
        }
        return answer;
    }
};