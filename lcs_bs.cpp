#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define ull unsigned long long
#define endl "\n"
#define all(v) v.begin(), v.end()
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<int> v[52];
void preCal(string &a)
{

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
            v[a[i] - 'a'].push_back(i);
        else
            v[a[i] - 'A' + 26].push_back(i);
    }
}
void solve()
{
    string a;
    cin >> a;
    preCal(a);
    int n;
    cin >> n;

    while (n--)
    {
        string b;
        cin >> b;
        int first = -1, last = -1;
        bool checker = false;
        for (int i = 0; i < b.size(); ++i)
        {
            int inx;
            if (b[i] >= 'a' && b[i] <= 'z')
                inx = b[i] - 'a';
            else
                inx = b[i] - 'A' + 26;

            auto val = lower_bound(v[inx].begin(), v[inx].end(), last+1);
            if (val == v[inx].end())
            {
                checker = true;
                break;
            }
            if (first < 0)
                first = *val;
            last = *val;

        }
        if (checker)
            cout << "Not matched" << endl;
        else
        {
            cout << "Matched ";
            cout << first << " " << last << endl;
        }

        // cout << a.size() << endl;
    }
}
int main()
{
    fastIO();
    int tc = 1;
    while (tc--)
    {
        solve();
    }
    return 0;
}
