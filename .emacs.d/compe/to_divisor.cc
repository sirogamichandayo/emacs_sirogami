vector<long long> toDivisor(ll num)
{
	vector<long long> d;
	for (ll i = 1; i*i <= num; ++i)
	{
		if (i*i == num)
		{
			d.push_back(i);
		}
		else if (num % i == 0)
		{
			d.push_back(i);
			d.push_back(num/i);
		}
	}
	return d;
}

vector<pair<long long , long long>> toDivisorP(ll num)
{
	vector<pair<long long, long long>> d;
	for (ll i = 1; i * i <= num; ++i)
	{
		if (i*i == num) d.push_back(pair<ll, ll>(i, i));
		else if (num % i == 0)
		{
			d.push_back(pair<ll, ll>(i, num/i));
		}
	}
	return d;
}
