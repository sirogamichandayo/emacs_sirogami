vector<long long> toDigit(ll num)
{
	vector<long long> d;
	while (num)
	{
		d.push_back(num%10);
		num /= 10;
	}
	reverse(d.begin(), d.end());
	return d;
}
