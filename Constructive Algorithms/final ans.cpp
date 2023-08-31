#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int m = 0;
void buildPermutation(vector<int> &vec, int l, int r)
{
    if ((r - l) >= 2)
    {
        int mid = l + (r - l) / 2;
        vector<int> v1, v2;
        for (int i = l; i <= r; i += 2)
        {
            v1.push_back(vec[i]);
        }
        for (int i = l + 1; i <= r; i += 2)
        {
            v2.push_back(vec[i]);
        }

        buildPermutation(v1, 0, v1.size() - 1);
        buildPermutation(v2, 0, v2.size() - 1);
    }
    else
    {
        if (r != l)
        {
            ans[m++] = vec[l];
            ans[m++] = vec[r];
        }
        else
            ans[m++] = vec[l];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    ans.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }
    buildPermutation(v, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    puts("");
}
