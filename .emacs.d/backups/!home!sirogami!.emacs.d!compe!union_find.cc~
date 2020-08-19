struct UnionFind
{
	vector<long long> par;

	void init(long long n) {par.assign(n, -1);}

	long long root(long long x)
	{
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool merge(long long x, long long y)
	{
		x = root(x);
		y = root(y);
		if(x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	bool issame(long long x, long long y)
	{
		return root(x) == root(y);
	}

	long long size(long long x)
	{
		return -par[root(x)];
	}
};
