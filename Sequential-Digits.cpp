    int digits(int n)
    {
        int count=0;
        while(n)
        {
            n/=10;
            count++;
        } 
        return count;
    }
    vector<int> sequentialDigits(int low, int high) 
    {
        int countL = digits(low);
        int countR = digits(high);
        vector<int> ans;
        string mein="123456789";
        for(int curr=countL;curr<=countR;curr++)
        {
            string temp="";
            for(int i=0;i<=(9-curr);i++)
            {
                string temp = mein.substr(i,curr);
                int number = stoi(temp);
                if(number>=low and number<=high)
                {
                    ans.push_back(number);
                }
            }
        }
        return ans;
    }
