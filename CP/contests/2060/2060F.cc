#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

// Helper function to calculate modular multiplicative inverse
ll modInverse(ll a, ll m = MOD) {
  ll m0 = m;
  ll y = 0, x = 1;
  if (m == 1)
    return 0;
  while (a > 1) {
    ll q = a / m;
    ll t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0)
    x += m0;
  return x;
}

// Calculate nPr % MOD
ll permutation(ll n, ll r) {
  if (r > n)
    return 0;
  ll result = 1;
  for (ll i = 0; i < r; i++) {
    result = (result * (n - i)) % MOD;
  }
  return result;
}

// Calculate factorial modulo MOD
vector<ll> factorials;
void precomputeFactorials(int maxN) {
  factorials.resize(maxN + 1);
  factorials[0] = 1;
  for (int i = 1; i <= maxN; i++) {
    factorials[i] = (factorials[i - 1] * i) % MOD;
  }
}

// Calculate multinomial coefficient modulo MOD
ll multinomial(vector<ll> &freq) {
  ll sum = 0;
  ll denom = 1;
  for (ll f : freq) {
    sum += f;
    denom = (denom * factorials[f]) % MOD;
  }
  ll num = factorials[sum];
  ll denomInv = modInverse(denom);
  return (num * denomInv) % MOD;
}

// Find all factorizations of x using numbers ≤ k
void findFactorizations(ll x, ll k, ll curr_num, vector<ll> &curr_fact,
                        vector<vector<ll>> &all_facts) {
  if (x == 1) {
    if (!curr_fact.empty())
      all_facts.push_back(curr_fact);
    return;
  }
  for (ll i = curr_num; i <= min(x, k); i++) {
    if (x % i == 0) {
      curr_fact.push_back(i);
      findFactorizations(x / i, k, i, curr_fact, all_facts);
      curr_fact.pop_back();
    }
  }
}

// Calculate result for a single number x
ll solveForX(ll x, ll k, ll n) {
  if (x > k)
    return 0;
  vector<vector<ll>> factorizations;
  vector<ll> curr;
  findFactorizations(x, k, 1, curr, factorizations);

  ll result = 0;
  for (auto &fact : factorizations) {
    if (fact.size() > n)
      continue;

    // Count frequencies
    map<ll, ll> freq_map;
    for (ll num : fact)
      freq_map[num]++;

    vector<ll> frequencies;
    for (auto &p : freq_map)
      frequencies.push_back(p.second);

    // Calculate contribution from this factorization
    ll multi = multinomial(frequencies);
    result = (result + multi) % MOD;
  }

  // Add single element factorization if possible
  if (x <= k && 1 <= n) {
    result = (result + 1) % MOD;
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Precompute factorials
  precomputeFactorials(105);

  int t;
  cin >> t;
  while (t--) {
    ll k, n;
    cin >> k >> n;

    // Calculate and output result for each x from 1 to k
    for (ll x = 1; x <= k; x++) {
      cout << solveForX(x, k, n) << " ";
    }
    cout << "\n";
  }

  return 0;
}