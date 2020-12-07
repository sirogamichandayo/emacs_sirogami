template<class T>
struct BIT
{
        int N;
        vector<T> bit[2]; // 1-indexed
        BIT(int n_) {init (n_);}
        void init(int n)
        {
                N = n + 1;
                bit[0].assign(N, 0);
                bit[1].assign(N, 0);
        }

        void add_sub(int p, int i, T x)
        {
                for (int j = i; j < N; j += (j & -j))
                        bit[p][j] += x;
        }

        T sum_sub(int p, int i)
        {
                T res{0};
                for (int j = i; j > 0; j -= (j & -j))
                        res += bit[p][j];
                return res;
        }

        void add(int l, int r, T x)
        {
			++l, ++r;
			add_sub(0, l, -x*(l-1));
			add_sub(0, r, x*(r-1));
			add_sub(1, l, x);
			add_sub(1, r, -x);
        }

        T sum(int i)
        {
			++i;
			return sum_sub(0, i) + sum_sub(1, i) * i;
        }
};
