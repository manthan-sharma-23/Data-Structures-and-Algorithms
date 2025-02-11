#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxN = 1000050;
const int md = 1e9 + 7;

typedef long long ll;

vector<int> spf(maxN);

void computeSpf() {
  for (int i = 2; i < maxN; i++) {
    spf[i] = i;
  }
  for (ll p = 2; p * p < maxN; p++) {
    if (spf[p] == p) {
      for (ll f = p * p; f < maxN; f += p) {
        if (spf[f] == f) {
          spf[f] = p;
        }
      }
    }
  }
}

unordered_map<ll, ll> primeFactorization(ll x) {
  unordered_map<ll, ll> factors;
  while (x != 1) {
    int f = spf[x];
    factors[f]++;
    x /= f;
  }
  return factors;
}

int main() {
  computeSpf();

  int n, m;
  cin >> n >> m;

  unordered_map<ll, ll> b1;
  for (ll i = 2; i <= m; i++) {
    auto a2 = primeFactorization(i);
    for (auto itr = a2.begin(); itr != a2.end(); itr++) {
      b1[itr->first] += itr->second;
    }
  }

  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    auto a2 = primeFactorization(a[i]);
    auto b5 = b1;
    for (auto itr = a2.begin(); itr != a2.end(); ++itr) {
      b5[itr->first] += itr->second;
    }

    ll d = 1;
    for (auto itr = b5.begin(); itr != b5.end(); ++itr) {
      d = (d * (itr->second + 1)) % md;
    }

    b[i] = d;
  }

  for (auto di : b) {
    cout << di << " ";
  }
  cout << endl;

  return 0;
}
