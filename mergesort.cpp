const int N = 1e5;
int arr[N];
int ans;
void merge(int l, int m, int r)
{
    int sz_b = m - l + 1, sz_c = r - m;
    int b[sz_b], c[sz_c];
    for (int i = 0; i < sz_b; ++i)
        b[i] = arr[l + i];
    for (int i = 0; i < sz_c; ++i)
        c[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < sz_b && j < sz_c)
    {
        if (b[i] > c[j])
        {
            arr[k++] = c[j++];
            ans += sz_b - i;
        }
        else
            arr[k++] = b[i++];
    }
    while (i < sz_b)
        arr[k++] = b[i++];
    while (j < sz_c)
        arr[k++] = c[j++];
}
ll mergesort(ll l, ll r)
{
    if (r > l)
    {
        int m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}
