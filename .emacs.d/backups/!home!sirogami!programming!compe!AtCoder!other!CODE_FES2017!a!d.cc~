#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N, M, K;
	cin >> N >> M >> K;

	vector<bool> can(N*M+1, false);

	for (ll h = 0; h <= M; ++h)
	{
		for (ll w = 0; w <= N; ++w)
		{
			can[h*w + (M-h)*(N-w)] = true;
		}
	}

	std::cout << (can[K] ? "Yes" : "No")<< std::endl;
}
