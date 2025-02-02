int check(vector<int> &a)
{
    int n = a.size();
    if (n == 1 or n == 2)
        return true;
    int idx = 0;
    while (idx < n - 1 and a[idx] == a[idx + 1])
        idx++;
    if (idx == n - 1)
        return true;
    while (idx < n - 1 and a[idx] <= a[idx + 1])
        idx++;
    if (idx == n - 1)
        return true;
    int start = idx + 1;
    int count = 0;
    while (true)
    {
        if (count == n - 1)
            return true;
        int next = (start + 1) % n;
        if (a[start] <= a[next])
        {
            count++;
            start = next;
        }
        else
        {
            break;
        }
    }
    return false;
}
