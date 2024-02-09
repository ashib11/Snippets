int lisLen(vector<int> &v)
{
    vector<int> lis;
    for (int i = 0; (int)i < v.size(); ++i)
    {
        auto it = lower_bound(all(lis), v[i]);
        if (it == lis.end())
            lis.push_back(v[i]);
        else
        {
            lis[it - lis.begin()] = v[i];
        }
    }
    return lis.size();
    //for lds just use -1*
}
