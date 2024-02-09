const int N = 1e3 + 10;
int dp[N][N];

int editDistance(string &s1, string &s2, int m, int n)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    int &yo = dp[m][n];
    if (~yo)
        return yo;
    if (s1[m - 1] == s2[n - 1])
        return yo = editDistance(s1, s2, m - 1, n - 1);
    else
    {
        int ins, del, rep;
        ins = editDistance(s1, s2, m, n - 1);
        del = editDistance(s1, s2, m - 1, n);
        rep = editDistance(s1, s2, m - 1, n - 1);
        return yo = 1 + min({ins, del, rep});
    }
}
