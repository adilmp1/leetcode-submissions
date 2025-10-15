int evalRPN(vector<string> &a)
{
    stack<int> s;
    int ans=0;
    for(auto token:a)
    {
        if(token=="+" or token=="-" or token=="*" or token=="/")
        {
            int b = s.top();s.pop();
            int a = s.top();s.pop();
            if(token=="+") s.push(a+b);
            else if(token=="-") s.push(a-b);
            else if(token=="*") s.push(a*b);
            else if(token=="/") s.push(a/b);
        }
        else
        {
            s.push(stoi(token));
        }
    }
    return s.top();
}
