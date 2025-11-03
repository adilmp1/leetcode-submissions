// Brute Force Approach

bool isBeautiful(int n)
{
    vector<int> freq(10,0);
    while(n)
    {
        freq[n%10]++;
        n/=10;
    }
    if(freq[0]) return false;
    for(int i=1;i<=9;i++) if(freq[i]!=0 and freq[i]!=i) return false;
    return true;
}

int nextBeautifulNumber(int n)
{
    for(int i=n+1;i<=10000000;i++) if(isBeautiful(i)) return i;
    return -1;
}
