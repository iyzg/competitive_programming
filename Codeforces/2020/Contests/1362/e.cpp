#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

namespace Modop {
    ll modAdd(ll a, ll b) {
        return (a + b) % MOD;
    }
    
    ll modSub(ll a, ll b) {
        return (((a - b) % MOD) + MOD) % MOD;
    }
    
    ll modMul(ll a, ll b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    ll modExp(ll base, ll power) {
        if (power == 0) {
            return 1;
        } else {
            ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
            if (power % 2 == 1) cur = cur * base;
            cur = cur % MOD;
            return cur;
        }
    }
    
    ll modInv(ll a) {
        return modExp(a, MOD - 2);
    }
    
    ll modDiv(ll a, ll b) {
        return modMul(a, modInv(b));
    }
}

using namespace Modop;

ll n, p;

void solve() {
	cin >> n >> p;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	
	if (p == 1) {
		cout << n % 2 << "\n";
		return;
	}
	
	sort(a.begin(), a.end(), greater<int>());
	ll l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		if (l < r) l = modAdd(l, modExp(p, a[i]));
		else r = modAdd(r, modExp(p, a[i]));
	}
	cout << modSub(r, l) << "\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		solve(); 
	}
    return 0;
}
