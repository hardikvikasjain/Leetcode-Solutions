class Solution {
public:
    string trim(string s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        return s;
    }
    int lengthOfLastWord(string s) {
        //use trim function
        //run loop from last till we get space
        s = trim(s);
        int count = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == ' ')
            break;
        count++;
        }
    return count;
    }
};