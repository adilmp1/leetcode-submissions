double slope(int a, int b, int c, int d)
{
    double slopeVal = (double)(d - b) / (c - a);
    return slopeVal;
}

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
{
    bool b1 = slope(a, b, c, d) == slope(a, b, e, f) and slope(a, b, c, d) == slope(c, d, e, f);
    if (!b1)
    {
        if (abs(c - e) == abs(d - f)) return 1;
        if((a-e)==0 or (b-f)==0) return 1;
        return 2;
    }
    vector<pair<int, int>> arr;
    arr.push_back({a, b});
    arr.push_back({c, d});
    arr.push_back({e, f});
    sort(arr.begin(), arr.end());
    if (arr[1].first == a and arr[1].second == b)
    {
        if((a-e)==0 or (b-f)==0) return 1;
        return 2;
    }
    if (arr[1].first == c and arr[1].second == d)
    {
        if (abs(c - e) == abs(d - f)) return 1;
        return 2;
    }
    return 1;
}
