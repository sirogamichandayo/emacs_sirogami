vector<ll> zAlgorithm(const string& str)
{
	ll N = (ll)str.size();
	vector<ll> res(N);

	res[0] = N;
	for (ll i = 1, j = 0; i < N;)
	{
		while (i+j<N && str[j]==str[i+j]) {++j;}
		res[i] = j;

		if (j == 0) {++i; continue;}

		ll k{1};
		while (i+k<N && k+res[k]<j) res[i+k] = res[k], ++k;
		i += k;
		j -= k;
	}

	return res;
}
