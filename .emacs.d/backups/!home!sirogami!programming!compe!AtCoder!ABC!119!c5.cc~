#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
void chmin(T &a, T b) {if (a > b) a = b;}

ll N, A, B, C;
vector<ll> L;

ll solve(ll i, ll a, ll b, ll c)
{
	if (i == N)
	{
		if (a == 0 || b == 0 || c == 0) return 1ll << 60;
		return abs(A-a) + abs(B-b) + abs(C-c);
	}
	ll res{1ll<<60};
	chmin(res, solve(i+1, a, b, c));
	chmin(res, solve(i+1, a+L[i], b, c) + (a == 0 ? 0 : 10));
	chmin(res, solve(i+1, a, b+L[i], c) + (b == 0 ? 0 : 10));
	chmin(res, solve(i+1, a, b, c+L[i]) + (c == 0 ? 0 : 10));
	
	return res;
	
}

int main(int argc, char **argv)
{
	cin >> N >> A >> B >> C;
	L.resize(N); for (int i = 0; i < N; ++i) cin >> L[i];

	std::cout << solve(0, 0, 0, 0) << std::endl;
}
