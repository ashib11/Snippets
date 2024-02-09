#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
#define ll long long
#define pi acos(-1.0)
#define ull unsigned long long
#define endl "\n"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
// find_by_order();
// order_of_key();
const int N = 1e5+10 ;
int weight[N];
ll val[N];
ll dp[N][35];
ll func(int index, int weight_left)
{
    if (index < 0)
        return 0;
    if (weight_left == 0)
        return 0;
    if (dp[index][weight_left] != -1)
        return dp[index][weight_left];
    ll ans = func(index - 1, weight_left);
    if (weight_left - weight[index] >= 0)
        ans = max(ans, func(index - 1, weight_left - weight[index]) + val[index]);
    return dp[index][weight_left] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n_obj;
    cin >> n_obj;
    for (int i = 0; i < n_obj; ++i)
        cin >> val[i] >> weight[i];
    int g;
    cin >> g;
    int total = 0;
    for (int i = 0; i < g; ++i)
    {
        int w;
        cin >> w;
        total += func(n_obj - 1, w);
    }
    cout << total << endl; 
}
int main()
{
    fastIO();
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
