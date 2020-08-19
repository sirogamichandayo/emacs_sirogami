long long modpow(const long long a, const long long n, const long long mod)
{
        if (n == 0) return 1;
        long long t = modpow(a, n / 2, mod);
        (t = t * t) %= mod;
        if (n & 1)
			(t = t * a) %= mod;
        return t;
}
