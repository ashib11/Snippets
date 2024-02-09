int func(int val, vector<int> &coin)
{
    if (val == 0)
        return 0;
    int ans = INT_MAX;
    for (int it : coin)
    {
        if (val - it >= 0)
            ans = min(ans, func(val - it, coin) + 1);
    }
    return ans;
}
