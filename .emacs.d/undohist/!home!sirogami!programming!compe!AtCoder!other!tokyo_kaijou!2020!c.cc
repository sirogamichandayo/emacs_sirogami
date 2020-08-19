
((digest . "d76590778f3c875dbc2ad5439109522e") (undo-list nil (781 . 783) nil ("=" . -781) ((marker . 783) . -1) 782 nil (731 . 733) nil ("=" . -731) ((marker . 783) . -1) 732 nil (832 . 835) nil ("=" . -832) ((marker . 783) . -1) ((marker . 834) . -1) ((marker . 834) . -1) (" " . -833) ((marker . 783) . -1) ((marker . 834) . -1) ((marker . 834) . -1) 834 nil (1063 . 1064) nil ("+" . -1063) ((marker . 783) . -1) ((marker . 1066) . -1) ((marker . 1066) . -1) ("=" . -1064) ((marker . 783) . -1) ((marker . 1066) . -1) ((marker . 1066) . -1) 1065 nil (1063 . 1065) nil ("=" . -1063) ((marker . 783) . -1) ((marker . 1066) . -1) 1064 nil (2456 . 2457) nil (2454 . 2456) nil (2453 . 2454) nil (2462 . 2464) nil (2461 . 2462) nil (2457 . 2460) ("max" . 2457) nil (2457 . 2460) nil (2456 . 2458) ("(" . -2456) (2456 . 2457) nil (2446 . 2456) nil ("se" . -2446) ((marker . 783) . -2) 2448 nil (2446 . 2448) nil (2444 . 2446) ("	" . 2444) ((marker . 783) . -1) 2445 nil (2443 . 2445) nil ("	std::cout << std::endl;
" . 2445) ((marker . 2473) . -10) ((marker . 2473) . -19) ((marker . 978) . -25) ((marker . 978) . -25) nil ("		std::cout << imos[i] << \" \";
" . 2445) ((marker . 2473) . -2) nil ("	REP(i, N)
" . 2445) nil ("
" . 2445) nil ("	}
" . 2445) nil ("		imos[i+1] += imos[i];
" . 2445) nil ("	{
" . 2445) nil ("
" . 2445) ((marker*) . 1) ((marker*) . 1) ("	REP(i, MAX)" . -2445) ((marker . 2473) . -1) ((marker . 783) . -12) ((marker*) . 1) ((marker) . -12) ((marker*) . 8) ((marker) . -5) 2457 nil (2438 . 2439) nil ("=" . -2438) ((marker . 2441) . -1) ((marker . 2441) . -1) ((marker . 2441) . -1) ((marker . 2441) . -1) ((marker . 2441) . -1) ((marker . 783) . -1) ("K" . -2439) ((marker . 2441) . -1) ((marker . 2441) . -1) ((marker . 2441) . -1) ((marker . 2441) . -1) ((marker . 2441) . -1) ((marker . 783) . -1) 2440 nil (2414 . 2416) nil ("+" . -2414) ((marker . 783) . -1) ("=" . -2415) ((marker . 783) . -1) ("K" . -2416) ((marker . 783) . -1) 2417 (t 24292 51666 781116 13000) nil (" " . -627) ((marker . 783) . -1) 628 (t 24292 51663 449144 510000) nil ("
" . 535) nil ("      void 
" . 535) ((marker . 534) . -12) ((marker . 534) . -12) ("  " . -535) ((marker . 783) . -2) 537 (t 24292 51654 241223 255000) nil (nil rear-nonsticky nil 2233 . 2234) (nil fontified nil 356 . 2234) (nil fontified nil 355 . 356) (nil category c->-as-paren-syntax 355 . 356) (nil fontified nil 354 . 355) (nil fontified nil 353 . 354) (nil category c-<-as-paren-syntax 353 . 354) (nil fontified nil 307 . 353) (nil fontified nil 306 . 307) (nil category c->-as-paren-syntax 306 . 307) (nil fontified nil 296 . 306) (nil fontified nil 295 . 296) (nil category c-<-as-paren-syntax 295 . 296) (nil fontified nil 287 . 295) (nil fontified nil 286 . 287) (nil fontified nil 285 . 286) (285 . 2234) (t 24292 51637 173369 215000) nil ("template <typename T>
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
			dat[i] = f(dat[i*2+1], dat[i*2+2]);
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
" . 285) ((marker . 675) . -452) ((marker . 675) . -452) ((marker . 629) . -413) ((marker . 629) . -413) ((marker . 585) . -410) ((marker . 585) . -410) ((marker . 575) . -396) ((marker . 575) . -396) ((marker . 551) . -395) ((marker . 551) . -395) ((marker . 535) . -392) ((marker . 535) . -392) ((marker . 943) . -336) ((marker . 943) . -336) ((marker . 888) . -339) ((marker . 888) . -339) ((marker . 534) . -375) ((marker . 534) . -375) ((marker . 285) . -979) ((marker . 693) . -491) ((marker . 693) . -491) ((marker . 743) . -494) ((marker . 743) . -494) ((marker . 793) . -495) ((marker . 793) . -495) ((marker . 811) . -526) ((marker . 811) . -526) ((marker . 285) . -339) ((marker . 285) . -339) ((marker . 285) . -375) ((marker . 285) . -375) ((marker . 2421) . -491) ((marker . 285) . -494) ((marker . 285) . -494) ((marker) . -979) (t 24292 51607 681621 347000) nil (285 . 1264) nil undo-tree-canary))
