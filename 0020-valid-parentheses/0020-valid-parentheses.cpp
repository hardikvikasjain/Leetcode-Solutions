class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s){

            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {

                if(st.empty())
                    return false;

                if((ch == ')' && st.top() != '(') ||
                   (ch == '}' && st.top() != '{') ||
                   (ch == ']' && st.top() != '['))
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};

/* this is totally wrong approach 
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        for (int i = 0; i < n; i ++){
            if ((s[i] == '(' && s[n-i-1] == ')' ) || ( s[i] == '{' && s[n-i-1] == '}' )
             || (s[i] == '[' && s[n-i-1] == ']' )){
                return true;
              }
            }
            return false;
    }
};
*/