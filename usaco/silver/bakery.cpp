// https://usaco.org/index.php?page=viewproblem2&cpid=1302
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

using ll = long long;

struct bfriend {
    ll cnt_cookie, cnt_muffin, t_wait;
    bool dir;

    friend istream& operator>>(istream& is, bfriend& b) {
        is >> b.cnt_cookie >> b.cnt_muffin >> b.t_wait;
        b.dir = b.cnt_cookie <= b.cnt_muffin;
        return is;
    }
};

// trick is dir 
// dir true min feasible cookie
// false false false ... true true ...
// dir false max feasible cookie
// true true true ... false false ...
ll find_idx(bfriend& f, ll K, bool dir) {
    ll l = 0, r = K - 1;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        ll t_cur = mid * f.cnt_cookie + (K - mid) * f.cnt_muffin;
        if ((t_cur > f.t_wait) ^ dir) r = mid - 1;
        else l = mid;
    }
    return l + dir;
}


// if cookie <= muffin pick least #cookie -> lower bound
// or else most #cookie -> upper bound
bool pass(vector<bfriend>& friends, ll K, ll tc, ll tm) {
    ll cl = 1, cr = min(K - 1, tc);
    ll ml = 1, mr = min(K - 1, tm);
    for (auto& f: friends) {
        if (f.dir) {
            cl = max(find_idx(f, K, true), cl);
            mr = min(mr, K - cl);
        } else {
            cr = min(find_idx(f, K, false), cr);
            ml = max(ml, K - cr);
        }

    }
    return cl <= cr && ml <= mr;
}


ll eval(ll tc, ll tm, vector<bfriend>& friends) {
    // want max K such that n - K is min
    ll l = 2, r = tc + tm;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (!pass(friends, mid, tc, tm)) r = mid - 1;
        else l = mid;
    }
    
    return tc + tm - l;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll tc, tm;
        vector<bfriend> friends;
        cin >> n >> tc >> tm;
        copy_n(istream_iterator<bfriend>(cin), n, back_inserter(friends));

        cout << eval(tc, tm, friends) << endl;
    }

    return 0;
}
