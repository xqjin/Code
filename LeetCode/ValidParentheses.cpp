Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.



class Solution {
public:
    bool isValid(string s) {
        stack<char> sym;
        
        bool re = true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                sym.push(s[i]);
            else
            {   
                if(sym.empty())
                {
                    re = false;
                    return re;
                }
                
                char temp = sym.top();
                sym.pop();
                if((temp=='(' && s[i]!=')' )|| (temp=='[' && s[i]!=']' )||(temp=='{' && s[i]!='}' ))
                {
                    re = false;
                    return re;
                }
            }
            
        }
        
        if(!sym.empty())
            re = false;
        
        return re;
    }
};
