// Optimized
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t ans=0;
        for(int i=0;i<32;i++)
        {
            ans=(ans*2)+(n%2);
            n/=2;
        }
        return ans;
    }

    uint32_t reverseBits(uint32_t n) 
    {
        string s = "";
        while (n) 
        {
            s.push_back((n % 2) + '0');
            n /= 2;
        }
        int x = 32 - s.size() + 1;
        while (x--) s += '0';
        int i = s.size() - 1;
        uint32_t ans = 0;
        int j = 0;
        while (i--) ans += ((s[i] - '0') * pow(2, j++));
        return ans;
    }
