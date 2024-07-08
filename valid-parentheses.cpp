    bool isValid(string s) 
    {
        stack<char> st;
        for(char i:s)
        {
            if(i=='(' or i=='{' or i=='[')
            {
                st.push(i);
            }
            else 
            {   
                if(!st.empty())
                {
                    bool b1 = (i==')') and (st.top()=='(');
                    bool b2 = (i=='}') and (st.top()=='{');
                    bool b3 = (i==']') and (st.top()=='[');
                    if(b1 or b2 or b3) 
                    {
                        st.pop();
                        continue;
                    }
                }
                return false;
            }
        }    
        return (st.empty());
    }
