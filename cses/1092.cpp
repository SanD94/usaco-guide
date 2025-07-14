// https://cses.fi/problemset/task/1092
#include <iostream>
using namespace std;

#define MAXN 1000010

using lli = long long int;

int main()
{
    int n, cnt[2] = {1, 0};
    lli sum[2] = {1, 0};
    bool set_marker[MAXN] = {false};

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int s_num = (i + 1) / 2;
        set_marker[s_num] ^= true;
        set_marker[i] = !set_marker[s_num];
        sum[set_marker[i]] -= s_num;
        sum[set_marker[i]] += i;

        sum[set_marker[s_num]] += s_num;
        cnt[set_marker[s_num]]++;
    }

    if (sum[0] != sum[1])
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << cnt[0] << endl;
    for (int i = 1; i <= n; i++)
        if (!set_marker[i])
            cout << i << " ";
    cout << endl;
    cout << cnt[1] << endl;
    for (int i = 1; i <= n; i++)
        if (set_marker[i])
            cout << i << " ";
    cout << endl;

    return 0;
}