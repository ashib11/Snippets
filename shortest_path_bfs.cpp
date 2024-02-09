#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

#define ll long long
#define pi acos(-1.0)
#define ull unsigned long long
#define endl "\n"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

const int N = 1e5;
vector<int> g[N];
int vis[N];
int level[N];
int parent[N];

void bfs(int source, int target)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    level[source] = 0;
    parent[source] = -1;

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();

        for (int child : g[cur_v])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
                parent[child] = cur_v;
            }
        }
    }
}

void printPath(int source, int target)
{
    vector<int> path;
    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);
    cout << path.size() - 2 << endl;
    for (int i = path.size() - 1; i >= 0; --i)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

void solve()
{
    int n, s, t;
    cin >> n >> s >> t;

    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        vis[i] = 0;
        parent[i] = -1;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            if (x)
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }

    bfs(s, t);
    printPath(s, t);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i)
    {
        cout << "Case " << i << ":" << endl;
        solve();
    }

    return 0;
}
