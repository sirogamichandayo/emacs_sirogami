vector<int> zAlgo(const string& str)
{
	int N = (int)str.size();
	vector<int> res(N);
	int from{-1}, last{-1};
	res[0] = N;
	for (int i = 1; i < N; ++i)
	{
		int &same = res[i];
		if (from != -1)
		{
			same = min(res[i-from], last-i);
			same = max(0, same);
		}
		while (same+i < N && str[same] == str[i+same]) ++same;
		if (last < i + same)
		{
			last = i + same;
			from = i;
		}
	}
	return res;
}
