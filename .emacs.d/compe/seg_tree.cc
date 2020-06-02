template <typename T>
struct SegTree
{
	using F = function<T(T, T)>; // T*T -> X
	long long N;
	F f;
	const T ex;
	vector<T> dat;
	SegTree(long long n_, F f_, T ex_) : N(), f(f_), ex(ex_), dat(n_*4, ex_)
	{
		long long x = 1;
		while (n_ > x) x <<= 1;
		N = x;
	}

	void set(long long i, T x) {dat[i+N-1] = x;};
	void set(vector<T> &v)
	{
		assert(N == v.size());
		for (long long i = 0; i < N; ++i)
			set(i, v[i]);
	}

	void build()
	{
		for (long long k = N-2; k >= 0; --k)
			dat[k] = f(dat[k*2+1], dat[k*2+2]);
	}

	void update(long long i, T x)
	{
		i += N-1;
		dat[i] = x;
		while (i > 0)
		{
			i = (i-1)/2;
			dat[i] = f(dat[i*2+1], dat[i*2+1]);
		}
	}

	T query(long long a, long long b) {return query_sub(a, b, 0, 0, N);}
	T query_sub(long long a, long long b, long long k, long long l, long long r)
	{
		if (r <= a || b <= l) return ex;
		if (a <= l && r <= b) return dat[k];
		T vl = query_sub(a, b, k*2+1, l, (l+r)/2);
		T vr = query_sub(a, b, k*2+2, (l+r)/2, r);
		return f(vl, vr);
	}
};
