    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int> mp;
        for(auto email:emails)
        {
            string s = "";
            bool flag=true;
            bool isLocalName = true;
            bool plusOccurred = false; 
            for(char ch:email)
            {
                if(ch=='@') isLocalName=false;
                if(ch=='+') plusOccurred=true;
                if(ch=='@' or !isLocalName or isLocalName and !plusOccurred and ch!='.') s+=ch;
            }
            mp[s]=1;
        }
        return mp.size();
    }
