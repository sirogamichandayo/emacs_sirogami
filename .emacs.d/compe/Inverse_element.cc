struct InvElem
{
	const long long mod;
	vector<long long> inv;

	InvElem(long long n, long long m) : mod(m)
	{
		inv.resize(n+1);

		inv[1] = 1;
		for (long long i = 2; i <= n; ++i)
			(inv[i] = mod - inv[mod%i] * (mod/i)) %= mod;
	}
};
