bool isNStraightHand(vector<int> &hand, int groupSize)
{
    int n = hand.size();
    if (n % groupSize != 0)
        return false;
    map<int, int> mp;
    for (int i = 0; i < hand.size(); i++)
    {
        mp[hand[i]]++;
    }
    while (!mp.empty())
    {
        auto &[key, value] = *mp.begin();
        int times = value;
        value -= times;
        int tempKey = key;
        if (value <= 0)
            mp.erase(key);
        for (int i = 1; i < groupSize; i++)
        {
            if (mp.find(tempKey + i) == mp.end())
            {
                return false;
            }
            else
            {
                mp[tempKey + i] -= times;
                if (mp[tempKey + i] < 0)
                    return false;
                if (mp[tempKey + i] == 0)
                    mp.erase(tempKey + i);
            }
        }
    }
    return true;
}
