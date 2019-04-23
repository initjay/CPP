// Method using a stack to check the validity of
// parentheses matches 

#include <stack>


class Solution {
public:
    bool openString(char paranth){
        return paranth == '{' || paranth == '[' || paranth == '(';
    }
    bool matchingParanth(char l, char r){
        if(l == '{')
            return r == '}';
        else if(l == '(')
            return r == ')';
        else if(l == '[')
            return r == ']';
        else
            return false;
    }
    bool isValid(string s) {
        stack<char> charStack;
        for(int i = 0; i < s.length(); i++){
            if(openString(s[i]))
                charStack.push(s[i]);
            else if(!charStack.empty() && matchingParanth(charStack.top(), s[i])){
                charStack.pop();
            } else
                return false;
        }
        return charStack.empty();
    }
};
