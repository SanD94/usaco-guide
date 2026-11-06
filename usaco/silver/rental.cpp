// https://usaco.org/index.php?page=viewproblem2&cpid=787
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

#define all(x) begin(x), end(x)

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

using ll = long long;
using cow = ll;
using rent = ll;

struct buyer {
    ll amount, cent;
    
    friend istream& operator>>(istream& is, buyer& b) {
        return is >> b.amount >> b.cent;
    }

    friend ostream& operator<<(ostream& os, const buyer& b) {
        return os << "[" << b.amount << " " << b.cent << "]";
    }

    friend bool operator<(const buyer& lhs, const buyer& rhs) {
        return tie(lhs.cent, lhs.amount) < tie(rhs.cent, rhs.amount);
    }

    friend bool operator>(const buyer& lhs, const buyer& rhs) {
        return rhs < lhs;
    }
};


int main() {
    set_io("rental");

    int n, m, r;
    vector<cow> cows;
    vector<buyer> buyers;
    vector<rent> rents;

    cin >> n >> m >> r;
    copy_n(istream_iterator<cow>(cin), n, back_inserter(cows));
    copy_n(istream_iterator<buyer>(cin), m, back_inserter(buyers));
    copy_n(istream_iterator<rent>(cin), r, back_inserter(rents));

    ll res = 0, cur_res = 0;

    sort(all(cows));
    sort(all(buyers), greater<buyer>());
    sort(all(rents), greater<rent>());

    auto rent_cow = [&](bool really) {
        static size_t i = 0;
        if (really) {
            if (i == rents.size()) return false;
            cur_res += rents[i++];
        } else {
            if (i == 0) return false;
            cur_res -= rents[--i];
        }
        return true;
    };


    auto sell_milk = [&](int ci) {
        static size_t i = 0;
        if (i == buyers.size()) return false;

        auto [amount, cent] = buyers[i];
        ll produce = min(amount, cows[ci]);


        cows[ci] -= produce;
        buyers[i].amount -= produce;

        if (buyers[i].amount == 0) i++;

        cur_res += produce * cent;

        return true;
    };

    size_t i = 0;
    while (i < cows.size() && rent_cow(true)) i++;
    int buy_i = (int)i - 1;
    while (i < cows.size() && sell_milk(i)) if (cows[i] == 0) i++;
    res = cur_res;

    while (buy_i >= 0) {
        rent_cow(false);
        while(cows[buy_i] != 0 && sell_milk(buy_i));

        res = max(res, cur_res);
        buy_i--;
    }


    cout << res << endl;

    return 0;
}


