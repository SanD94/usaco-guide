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
using milk = ll;

struct buyer {
    milk amount;
    ll cent;
    
    friend istream& operator>>(istream& is, buyer& b) {
        return is >> b.amount >> b.cent;
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

    sort(all(cows), greater<cow>());
    sort(all(buyers), greater<buyer>());
    sort(all(rents), greater<rent>());

    // total profit from milk
    vector<milk> milk_profit(n+1);
    int buyer_idx = 0;
    for (int i = 0; i < n; i++) {
        milk_profit[i+1] = milk_profit[i];
        milk remaining = cows[i];

        while(remaining && buyer_idx < m) {
            auto [amount, price] = buyers[buyer_idx];
            milk produce = min(remaining, amount);

            milk_profit[i+1] += produce * price;
            amount -= produce;
            remaining -= produce;

            buyers[buyer_idx].amount = amount;
            if (amount == 0) buyer_idx++;
        }
    }

    r = min(r, n);

    vector<rent> rentals(r+1);
    for (int i = 0; i < r; i++)
        rentals[i+1] = rentals[i] + rents[i];

    ll res = 0;
    for (int i = 0; i <= n; i++)
        res = max(res, milk_profit[i] + rentals[min(n - i, r)]);
    
    cout << res << endl;

    return 0;
}
