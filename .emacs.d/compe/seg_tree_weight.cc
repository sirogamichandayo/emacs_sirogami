struct UnionFind
{
	vector<ll> par, wei;
	UnionFind(ll n)
	{
		init(n);
	}

	void init(ll n)
	{
		par.assign(n, -1);
		wei.assign(n, 0);
	}

	ll root(ll x)
	{
		if (par[x] < 0) return x;
		else
		{
			ll r = root(par[x]);
			wei[x] += wei[par[x]];
			return par[x] = r;
		}
	}

	bool merge(ll x, ll y, ll w)
	{
		// rank(x) > rank(y)
		w += weight(x);
		w -= weight(y);

		x = root(x);
		y = root(y);
		
		if (x == y) return false;
		if (rank(x) < rank(y)) swap(x, y), w *= -1;
		par[x] += par[y];
		par[y] = x;

		wei[y] = w;
		return true;
	}

	ll weight(ll x)
	{
		root(x);
		return wei[x];
	}

	ll rank(ll x)
	{
		return -par[root(x)];
	}

	ll issame(ll x, ll y)
	{
		return root(x) == root(y);
	}

	ll diff(ll x, ll y)
	{
		return weight(y) - weight(x);
	}
};
