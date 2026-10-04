/*
 * Problem 678: Valid Parenthesis String (POTD)
 * Language: C++
 */
class Solution {
public:
    bool checkValidString(string s) 
    {
        int n=s.size();
        stack<int>st1;
        stack<int>st2;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                st1.push(i);
            }
            else if(ch=='*')
            {
                st2.push(i);
            }
            else
            {
                if(!st1.empty())
                {
                    st1.pop();
                }
                else{
                    if(st2.size())st2.pop();
                    else return false;
                }
                
            }
        }
        while(st1.size())
        {
            if(st2.size()==0 || st1.top()-st2.top()>0)return false;
            else{
                st1.pop();
                st2.pop();
            }
        }
        return true;
    }
};