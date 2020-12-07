struct Comb
{
	const long long MOD_;
	vector<long long> fac, finv, inv;

	Comb(long long n, long long m) : MOD_(m)
	{
		fac.resize(n+1);
		finv.resize(n+1);
		inv.resize(n+1);

		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (int i = 2; i <= n; i++){
			fac[i] = fac[i - 1] * i % MOD_;
			inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD_;
			finv[i] = finv[i - 1] * inv[i] % MOD_;
		}
	}

	// a_C_b 
	//      a!
	// = -------- 
	//   b!(a-b)!
	// = a! * (b!)^(-1) * ((a-b)!)^(-1)
	// = fac[a] * ifac[b] * ifac[a-b]
	long long comb(long long a, long long b)
	{
		if (a < b) return 0;
		if (a < 0 || b < 0) return 0;
		return fac[a] * (finv[b] * finv[a - b] % MOD_) % MOD_;
	}
};
