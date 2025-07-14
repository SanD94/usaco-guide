// https://cses.fi/problemset/task/1755
#include <iostream>
using namespace std;

int len, odd_index = -1;

void palindrome(int cnt[], int cur_index, int depth = 1)
{
    if (cur_index == 26)
        return;

    if (depth == (len + 1) / 2 && odd_index != -1)
    {
        cout << char(odd_index + 'A');
        cnt[odd_index]--;
        return;
    }

    if (cnt[cur_index] < 2)
    {
        palindrome(cnt, cur_index + 1, depth);
        return;
    }

    cout << char(cur_index + 'A');
    cnt[cur_index] -= 2;
    palindrome(cnt, cur_index, depth + 1);
    cout << char(cur_index + 'A');
}

int main()
{
    int cnt[26] = {0}, odd = 0;
    string s;
    cin >> s;
    len = s.length();
    for (char c : s)
        cnt[c - 'A']++;

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            odd++;
            odd_index = i;
        }
    }

    if (odd > len % 2)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    palindrome(cnt, 0);
    cout << endl;

    return 0;
}