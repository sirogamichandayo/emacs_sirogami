map<long long, long long> prime_factor(long long n) {
	map<long long, long long> ret;
	for(long long i = 2; i * i <= n; i++) {
		while(n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if(n != 1) ret[n] = 1;
	return ret;
}
