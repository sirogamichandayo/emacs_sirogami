#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define DEBUG(x) ;
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll D, N; cin >> D >> N;

	auto f = [&](ll n)
			 {
				 ll cnt{0};
				 while (n)
				 {
					 if (n % 100 != 0) break;
					 n /= 100;
					 ++cnt;
				 }
				 return cnt;
			 };

	ll cnt{0};
	ll res{0};
	for (ll i = 1; i < 100*100*200; ++i)
	{
		if (f(i) == D)
		{
			++cnt;
			if (cnt == N)
			{
				std::cout << i << std::endl;
				return 0;
			}
		}
	}
	return 0;
}
