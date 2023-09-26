void sortColors(vector<int> &a)
{
    int n = a.size();
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            swap(a[ind], a[i]);
            ind++;
        }
    }
    for (int i = ind; i < n; i++)
    {
        if (a[i] == 1)
        {
            swap(a[ind], a[i]);
            ind++;
        }
    }
    for (int i = ind; i < n; i++)
    {
        if (a[i] == 2)
        {
            swap(a[ind], a[i]);
            ind++;
        }
    }
}
