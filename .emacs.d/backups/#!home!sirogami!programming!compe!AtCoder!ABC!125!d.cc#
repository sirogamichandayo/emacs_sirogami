#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

ll dp[100010][2];

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> A(N);
	ll M{0};
	for (ll i = 0; i < N; ++i)
	{
		cin >> A[i];
		if (A[i] < 0)
		{
			++M;
			A[i] *= -1;
		}
	}

	sort(A.begin(), A.end(), greater<ll>());
	ll sum = accumulate(A.begin(), A.end(), 0ll);

	if (M&1)
		std::cout << sum - 2*A.back() << std::endl;
	else
		std::cout << sum << std::endl;
}
