const int arr[] = {1, 5, 10, 25, 50};
const int N = 1e5 + 10;
ll dp[6][N];
ll func(int val, int indx)
{
    if (indx < 0)
        return 0;
    if (val == 0)
        return 1;
    ll &posh = dp[indx][val];
    if (~posh)
        return posh;
    posh = func(val, indx - 1);
    ll ans = 0;
    if (arr[indx] <= val)
        ans = func(val - arr[indx], indx);

    return posh += ans;
}
