
((digest . "0d170af7316a13b57776661560c00ec4") (undo-list (813 . 814) nil (810 . 811) (809 . 811) nil ("	" . 808) (809 . 811) ("{" . -809) (809 . 810) nil (807 . 809) nil (802 . 806) nil (800 . 802) nil (794 . 800) nil (793 . 794) nil (785 . 793) nil (784 . 786) ("(" . -784) (784 . 785) nil (776 . 784) nil (774 . 776) nil (nil rear-nonsticky nil 773 . 774) (nil fontified nil 152 . 774) (nil fontified nil 151 . 152) (nil category c->-as-paren-syntax 151 . 152) (nil fontified nil 148 . 151) (nil fontified nil 147 . 148) (nil category c-<-as-paren-syntax 147 . 148) (nil fontified nil 1 . 147) (1 . 774) nil ("#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
#define MAX_E 100000

int par[MAX], rank_[MAX];

void init(int N)
{
    for (int i = 0; i < N; i++) {
	par[i] = i;
	rank_[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) {
	return x;
    }
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (rank_[x] < rank_[y]) {
	par[x] = y;
    } else {
	par[y] = x;
	if (rank_[x] == rank_[y]) {
	    rank_[x]++;
	}
    }
}

bool same(int x,int y)
{
    return (find(x) == find(y));
}

struct edge{ int u, v, cost; };

bool comp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}

int V,E;
edge es[MAX_E];

int kruskal()
{
    sort(es, es+E, comp);
    init(V); // init union_find
    int res = 0;
    for (int i = 0; i < E; i++)
	{
		std::cout << \"---\" << i << \"---\" << std::endl;
		std::cout << \"per\" << std::endl;
		for (int j = 0; j < V; ++j)
			std::cout << par[j] << \" \";
		std::cout << std::endl;
		std::cout << \"rank\" << std::endl;
		for (int j = 0; j < V; ++j)
			std::cout << rank_[j] << \" \";
		std::cout << std::endl;

		
		edge e = es[i];
		if (!same(e.u, e.v))
		{
			unite(e.u, e.v);
			res += e.cost;
		}

	}

    return res;
	}

int main()
{
    int s,t,w;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
	cin >> s >> t >> w;
        es[i]=(edge){s, t, w};
    }
    cout << kruskal() << endl;
    return 0;
}
" . 1) ((marker . 1) . -837) ((marker . 20) . -23) ((marker . 266) . -361) ((marker . 1580) . -684) ((marker . 1580) . -684) (t 24237 23239 533517 246000) nil (1067 . 1068) nil ("E" . -1067) ((marker . 1580) . -1) 1068 nil (944 . 945) nil ("E" . -944) ((marker . 1580) . -1) 945 (t 24237 23055 194525 847000) nil (1134 . 1137) ("		" . 1134) ((marker . 1580) . -2) 1136 nil (1133 . 1136) nil ("
" . 1152) nil undo-tree-canary))
