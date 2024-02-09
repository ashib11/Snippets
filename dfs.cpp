#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define ull unsigned long long
#define endl "\n"

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
void dfs(int vertex)
{
    /** Take action on vertex after entering
     * the vertex
     **/
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        /** Take action on child before
         * entering the child node
         * **/
        if (!vis[child])
            dfs(child);
        /** take action on child
         * after exiting child node
         **/
    }
    /** Take action on vertex before
     * exiting the vertex
     **/
}

int main()
{
    fastIO();
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == true)
            continue;
        cnt++;
        dfs(i);
    }
    cout << cnt << endl;
    return 0;
}
