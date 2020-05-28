struct Eratos
{
	vector<long long> primes;
	vector<bool> isprime;
	vector<long long> min_factor;
 
	Eratos(long long MAX) : primes(),
							isprime(MAX+1, true),
							min_factor(MAX+1, -1)
	{
		isprime[0] = isprime[1] = false;
		min_factor[0] = 0;
		min_factor[1] = 1;
 
		for (long long i = 2; i <= MAX; ++i)
		{
			if(!isprime[i]) continue;
			primes.push_back(i);
			min_factor[i] = i;
			for (long long j = i*2; j <= MAX; j += i)
			{
				isprime[j] = false;
				if (min_factor[j] == -1) min_factor[j] = i;
			}
		}
	}
 
	vector<pair<long long, long long>> prime_factorize(long long n)
	{
		vector<pair<long long, long long>> res;
		while (n != 1)
		{
			long long prime = min_factor[n];
			long long exp = 0;
			while (min_factor[n] == prime)
			{
				++exp;
				n /= prime;
			}
			res.push_back(make_pair(prime, exp));
		}
		return res;
	}
};
