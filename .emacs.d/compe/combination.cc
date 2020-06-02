struct Comb
{
	const long long mod;
	vector<long long> fac, ifac;

	Comb(long long n, long long m) : mod(m)
	{
		fac.resize(n+1);
		ifac.resize(n+1);

		fac[0] = 1;
		ifac[0] = 1;
		for (long long i = 0; i < n; ++i)
		{
			(fac[i+1] = fac[i]*(i+1)) %= mod;
			(ifac[i+1] = ifac[i]*mpow(i+1, mod-2)) %= mod;
		}
		
	}

	long long mpow(long long x, long long n)
	{ 
		long long ans = 1;
		while(n != 0){
			if(n&1) ans = ans*x % mod;
			x = x*x % mod;
			n = n >> 1;
		}
		return ans;
	}

	long long comb(long long a, long long b)
	{ 
		if(a == 0 && b == 0)return 1;
		if(a < b || a < 0)return 0;
		long long tmp = ifac[a-b]* ifac[b] % mod;
		return tmp * fac[a] % mod;
	}
};
