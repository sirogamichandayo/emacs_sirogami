
((digest . "2bb88471defcd7388f9800d729dcaa78") (undo-list nil ("
" . 1066) ((marker . 1558) . -1) ((marker . 1558) . -1) ((marker) . -1) ("	" . -1066) ((marker . 1066) . -1) ((marker) . -1) 1067 nil (1065 . 1067) ("	" . 1065) ((marker . 1066) . -1) 1066 (t 24368 15336 274854 749000) nil (1064 . 1066) nil (1063 . 1064) nil (1061 . 1062) nil (1060 . 1062) ("(" . -1060) (1060 . 1061) nil (1053 . 1060) nil (1051 . 1053) nil (";
" . 1033) ((marker . 1052) . -2) ((marker . 1052) . -2) ((marker*) . 2) ((marker*) . 2) ("	uf.init(1010)" . -1033) ((marker . 1066) . -14) ((marker*) . 1) ((marker) . -14) ((marker*) . 6) ((marker) . -9) 1047 (t 24368 15328 410933 756000) nil (1048 . 1050) nil (1047 . 1048) nil (1042 . 1046) nil (1041 . 1043) ("(" . -1041) (1041 . 1042) nil (1036 . 1041) nil (1034 . 1036) nil (1032 . 1034) nil (1031 . 1032) nil (1026 . 1031) nil ("d" . -1026) ((marker . 1066) . -1) 1027 nil (1019 . 1027) nil ("u" . -1019) ((marker . 1066) . -1) ((marker . 1019) . -1) ((marker . 1019) . -1) 1020 nil (1019 . 1020) nil (1018 . 1019) ("	" . 1018) ((marker . 1018) . -1) ((marker . 1018) . -1) nil ("
" . 1018) ((marker . 1033) . -1) ((marker . 1033) . -1) nil (1018 . 1020) ("	" . 1018) ((marker . 1066) . -1) 1019 nil (1017 . 1019) (t 24368 15310 407114 667000) nil (367 . 881) nil (365 . 367) (t 24368 15290 167318 71000) nil (347 . 1129) ("//#define DEBUG(x) ;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};

struct UnionFind
{
	vector<long long> par;

	void init(long long n) {par.assign(n, -1);}

	long long root(long long x)
	{
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool merge(long long x, long long y)
	{
		x = root(x);
		y = root(y);
		if(x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	bool issame(long long x, long long y)
	{
		return root(x) == root(y);
	}

	long long size(long long x)
	{
		return -par[root(x)];
	}
};


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	UnionFind uf;
	uf.init(1010);
	
	ll N; cin >> N;
	
	" . 347) ((marker . 489) . -585) ((marker . 347) . -725) ((marker . 347) . -160) ((marker . 347) . -703) ((marker . 347) . -722) ((marker . 347) . -722) ((marker . 347) . -722) ((marker . 347) . -688) ((marker . 347) . -723) ((marker . 907) . -114) ((marker . 1140) . -723) ((marker . 1066) . -723) (t 24368 15250 367718 148000) nil (1069 . 1070) ("	" . 1069) ((marker . 347) . -1) nil ("
" . 1069) nil ("		uf.merge(i, i+1);
" . 1069) ((marker . 347) . -11) ((marker . 347) . -1) nil ("REP(i, N-1)
" . 1069) ("	" . -1069) ((marker . 1066) . -1) 1070 (t 24368 15182 676398 896000) nil (1102 . 1104) ("	" . 1102) ((marker . 1066) . -1) 1103 nil (1101 . 1103) nil (1100 . 1101) nil (1095 . 1099) nil (1094 . 1095) nil (1093 . 1094) nil (1092 . 1094) ("(" . -1092) (1092 . 1093) nil (1084 . 1092) nil (1081 . 1084) nil (1079 . 1080) nil ("2" . -1079) ((marker . 1066) . -1) 1080 nil (1076 . 1080) nil (1075 . 1076) nil (1074 . 1075) nil (")" . -1074) (1074 . 1075) (")" . -1074) (1074 . 1075) (1073 . 1075) ("(" . -1073) (1073 . 1074) nil (1070 . 1073) nil (1068 . 1070) nil (")
" . 1050) ("	REP(" . -1050) ((marker . 1066) . -5) ((marker . 347) . -5) 1055 nil (")" . -1055) (1055 . 1056) (")" . -1055) (1055 . 1056) (1054 . 1056) ("(" . -1054) (1054 . 1055) nil (1051 . 1054) nil (1049 . 1051) (t 24368 15163 192594 921000) nil (1049 . 1051) nil (1048 . 1049) nil (1043 . 1047) nil (1042 . 1044) ("(" . -1042) (1042 . 1043) nil (1035 . 1042) nil (1033 . 1035) nil (1032 . 1033) nil (" " . -1032) ((marker . 1066) . -1) ("=" . -1033) ((marker . 1066) . -1) 1034 nil (1020 . 1034) nil ("unifo" . -1020) ((marker . 1066) . -5) 1025 nil (1020 . 1025) nil (1018 . 1020) (t 24368 15139 652831 798000) nil (418 . 932) nil (416 . 418) nil (519 . 521) nil (518 . 519) nil (516 . 518) nil (514 . 516) nil (509 . 514) nil ("c" . -509) ((marker . 1066) . -1) (" " . -510) ((marker . 1066) . -1) 511 nil ("in " . -511) ((marker . 1066) . -3) 514 nil (509 . 514) nil (508 . 509) nil (504 . 508) nil (503 . 504) nil (1 . 519) (t 24368 15117 369056 93000)))
