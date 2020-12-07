////////////////////
// Chinese remainder theorem
inline ll mod(ll a, ll m)
{
	a %= m;
	if (a < 0) a += m;
	return a;
}

ll extGcd(ll a, ll b, ll &p, ll &q)
{
	if (b == 0) { p = 1; q = 0; return a;}
	ll d = extGcd(b, a%b, q, p);
	q -= a/b * p;
	return d;
}

pair<ll, ll> ChineseRem(const vector<ll> &b, const vector<ll> &m)
{
	assert(b.size() == m.size());
	ll r = 0, M = 1;
	for (ll i = 0; i < (int)b.size(); ++i)
	{
		ll p, q;
		ll d = extGcd(M, m[i], p, q);
		if ((b[i] - r) % d != 0) return make_pair(0, -1);
		ll tmp = (b[i] - r) / d * p %  (m[i]/d);
		r += M * tmp;
		M *= m[i]/d;
	}
	return {mod(r, M), M};
}

// Chinese remainder theorem
// x = b_0(mod, m_0)
// x = b_1(mod, m_1)
// ...
// x = b_N-1(mod, m_N-1)
// <=>
// x = r(mod, m)
//
// call :   ChineseRem(vector<ll>b, vector<ll>)
// return : pair<ll, ll>(x, m)
// return(no solution) : pair<ll, ll>(0, -1)
