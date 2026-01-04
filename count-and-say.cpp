    string countAndSay(int n) {
        string curr = "1";
        for(int i=2;i<=n;i++)
        {
            string temp="";
            for(int j=0;j<curr.size();j++)
            {
                int count=0;
                char ch = curr[j];
                while(j<curr.size() and curr[j]==ch)
                {
                    count++;
                    j++;
                }
                temp+=to_string(count);
                temp.push_back(ch);
                j--;
            }
            curr=temp;
        }
        return curr;
    }
