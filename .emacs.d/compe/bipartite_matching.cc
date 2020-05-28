struct Bipartite_Matching
{
	vector<vector<long long>> graph;
	vector<long long> match, alive, used;
	long long timestamp;

	Bipartite_Matching(long long n)
	{
		timestamp = 0;
		graph.resize(n);
		alive.assign(n, 1);
		used.assign(n, 0);
		match.assign(n, -1);
	}

	void add_edge(long long u, long long v)
	{
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bool dfs(long long v)
	{
		used[v] = timestamp;
		for (auto &u : graph[v])
		{
			long long w = match[u];
			if (alive[u] == 0) continue;
			if (w == -1 || (used[w] != timestamp && dfs(w)))
			{
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

	long long bipartite_matching()
	{
		long long res{0};
		for (long long i = 0; i < (long long)graph.size(); ++i)
		{
			if (alive[i] == 0) continue;
			if (match[i] == -1)
			{
				++timestamp;
				res += dfs(i);
			}
		}
		return res;
	}
};
