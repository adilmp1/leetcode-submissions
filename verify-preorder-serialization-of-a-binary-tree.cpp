    bool isValidSerialization(string s) {
        int vacancy = 0;
        if(isdigit(s[0])) vacancy=2; 
        for(int i=1;i<s.size();i++)
        {
            if(isdigit(s[i]) and !isdigit(s[i-1])) 
            {
                vacancy--;
                if(vacancy<0) return false;
                vacancy+=2;
            }
            else if(s[i]=='#')
            {
                vacancy--;
                if(vacancy<0) return false;
            }
        }
        return (!vacancy);
    }
