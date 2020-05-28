
((digest . "764f8b8b448ceaa69b0c6f741ad5767d") (undo-list nil ("test
" . 1) ((marker . 1) . -5) ((marker . 940) . -5) ((marker . 940) . -5) ((marker . 1) . -5) nil (1 . 6) (t 24271 6838 181184 748000) nil ("}
" . 1) ((marker . 1) . -2) ((marker . 940) . -2) ((marker . 940) . -2) nil ("	std::cout << res << std::endl;
" . 1) ((marker . 26) . -32) ((marker . 26) . -32) nil ("
" . 1) ((marker . 940) . -1) ((marker . 940) . -1) nil ("		res += cnt[i][k] * cnt[k][i];
" . 1) ((marker . 26) . -32) ((marker . 26) . -32) nil ("	FOR(i, 1, 10) FOR(k, 1, 10)
" . 1) ((marker . 940) . -29) ((marker . 940) . -29) nil ("	ll res{0};
" . 1) ((marker . 26) . -12) ((marker . 26) . -12) nil ("
" . 1) ((marker . 940) . -1) ((marker . 940) . -1) ((marker . 1) . -1) ((marker . 1) . -1) ((marker . 1) . -1) ((marker . 1) . -1) ((marker . 1) . -1) nil ("	}
" . 1) ((marker . 26) . -3) ((marker . 26) . -3) nil ("		++cnt[v.front()][v.back()];
" . 1) ((marker . 940) . -30) ((marker . 940) . -30) nil ("		vector<ll> v = toDigit(i);
" . 1) ((marker . 26) . -29) ((marker . 26) . -29) nil ("	{
" . 1) ((marker . 940) . -3) ((marker . 940) . -3) nil ("	FOR(i, 1, N+1)
" . 1) ((marker . 26) . -16) ((marker . 26) . -16) nil ("
" . 1) ((marker . 940) . -1) ((marker . 940) . -1) nil ("	ll cnt[10][10] {};
" . 1) ((marker . 26) . -20) ((marker . 26) . -20) nil ("
" . 1) ((marker . 940) . -1) ((marker . 940) . -1) nil ("	ll N; cin >> N;
" . 1) ((marker . 26) . -17) ((marker . 26) . -17) nil ("{
" . 1) ((marker . 940) . -2) ((marker . 940) . -2) ((marker*) . 2) ((marker) . -1) nil ("int main(int argc, char **argv)
" . 1) ((marker . 26) . -32) ((marker . 26) . -32) nil ("
" . 1) ((marker . 940) . -1) ((marker . 940) . -1) nil ("
" . 1) ((marker . 26) . -1) ((marker . 26) . -1) nil ("}
" . 1) ((marker . 940) . -2) ((marker . 940) . -2) nil ("	return (tmp*tmp) % MOD;
" . 1) ((marker . 26) . -25) ((marker . 26) . -25) nil ("	ll tmp = modPow(a, n/2);
" . 1) ((marker . 940) . -26) ((marker . 940) . -26) nil ("	if (n&1) return (a*modPow(a, n-1)) % MOD;
" . 1) ((marker . 26) . -43) ((marker . 26) . -43) nil ("	if (n == 1) return a%MOD;
" . 1) ((marker . 940) . -27) ((marker . 940) . -27) nil ("{
" . 1) ((marker . 26) . -2) ((marker . 26) . -2) ((marker*) . 2) ((marker) . -1) nil ("ll modPow(ll a, ll n)
" . 1) ((marker . 940) . -22) ((marker . 940) . -22) nil ("
" . 1) ((marker . 26) . -1) ((marker . 26) . -1) nil ("
" . 1) ((marker . 940) . -1) ((marker . 940) . -1) nil ("
" . 1) ((marker . 26) . -1) ((marker . 26) . -1) nil ("}
" . 1) ((marker . 940) . -2) ((marker . 940) . -2) nil ("	return res;
" . 1) ((marker . 26) . -13) ((marker . 26) . -13) nil ("	for (ll i = n; i >= a; --i) (res *= i) %= MOD;
" . 1) ((marker . 940) . -48) ((marker . 940) . -48) nil ("	ll res{1};
" . 1) ((marker . 26) . -12) ((marker . 26) . -12) nil ("{
" . 1) ((marker . 940) . -2) ((marker . 940) . -2) ((marker*) . 2) ((marker) . -1) nil ("ll modFac(ll n, ll a)
" . 1) ((marker . 26) . -22) ((marker . 26) . -22) nil ("
" . 1) ((marker . 908) . -1) ((marker . 908) . -1) nil ("int dy[4]{1, 0, -1, 0};
" . 1) ((marker . 1) . -24) ((marker . 1) . -24) nil ("int dx[4]{0, 1, 0, -1};
" . 1) ((marker . 908) . -24) ((marker . 908) . -24) nil ("
" . 1) ((marker . 1) . -1) ((marker . 1) . -1) nil ("}
" . 1) ((marker . 908) . -2) ((marker . 908) . -2) nil ("	return d;
" . 1) ((marker . 1) . -11) ((marker . 1) . -11) nil ("	reverse(d.begin(), d.end());
" . 1) ((marker . 908) . -30) ((marker . 908) . -30) nil ("	}
" . 1) ((marker . 1) . -3) ((marker . 1) . -3) nil ("		num /= 10;
" . 1) ((marker . 908) . -13) ((marker . 908) . -13) nil ("		d.push_back(num%10);
" . 1) ((marker . 1) . -23) ((marker . 1) . -23) nil ("	{
" . 1) ((marker . 908) . -3) ((marker . 908) . -3) nil ("	while (num)
" . 1) ((marker . 1) . -13) ((marker . 1) . -13) nil ("	vector<ll> d;
" . 1) ((marker . 908) . -15) ((marker . 908) . -15) nil ("{
" . 1) ((marker . 1) . -2) ((marker . 1) . -2) ((marker*) . 2) ((marker) . -1) nil ("vector<ll> toDigit(ll num)
" . 1) ((marker . 908) . -27) ((marker . 908) . -27) nil ("
" . 1) ((marker . 1) . -1) ((marker . 1) . -1) nil ("#define ALL(v) (v).begin(),(v).end()
" . 1) ((marker . 197) . -36) ((marker . 908) . -37) ((marker . 908) . -37) nil ("#define REP(i,n) FOR(i,0,n)
" . 1) ((marker . 197) . -27) ((marker . 1) . -28) ((marker . 1) . -28) nil ("#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
" . 1) ((marker . 197) . -43) ((marker . 908) . -44) ((marker . 908) . -44) nil ("
" . 1) ((marker . 1) . -1) ((marker . 1) . -1) nil ("constexpr ll INF = 1ll<<60;
" . 1) ((marker . 908) . -28) ((marker . 908) . -28) nil ("constexpr ll MOD = 1e9+7;
" . 1) ((marker . 1) . -26) ((marker . 1) . -26) nil ("
" . 1) ((marker . 908) . -1) ((marker . 908) . -1) nil ("using ll = long long;
" . 1) ((marker . 1) . -22) ((marker . 1) . -22) nil ("
" . 1) ((marker . 908) . -1) ((marker . 908) . -1) nil ("using namespace std;
" . 1) ((marker . 1) . -21) ((marker . 1) . -21) nil ("#include <bits/stdc++.h>
" . 1) ((marker . 1) . -25) ((marker . 908) . -25) ((marker . 908) . -25) nil (1 . 942) (t 24250 10235 208620 756000) nil (526 . 528) nil (523 . 524) nil (513 . 523) nil (511 . 513) nil (510 . 511) nil (507 . 510) ("mod" . 507) nil (503 . 510) nil (499 . 502) nil (498 . 499) nil (494 . 498) nil (493 . 495) ("(" . -493) (493 . 494) nil (492 . 493) nil (487 . 491) nil (486 . 487) nil (483 . 486) nil (482 . 483) nil (479 . 482) nil (478 . 479) nil (470 . 478) nil (469 . 471) ("(" . -469) (469 . 470) nil (465 . 469) nil (463 . 465) nil (462 . 463) nil (460 . 461) nil (459 . 461) ("{" . -459) (459 . 460) nil (453 . 459) nil (452 . 453) (451 . 453) nil ("	" . 450) (451 . 453) ("{" . -451) (451 . 452) nil (449 . 451) nil (443 . 448) nil (442 . 443) nil (438 . 442) nil (437 . 439) ("(" . -437) (437 . 438) nil (428 . 437) nil (426 . 428) (t 24250 9910 971175 819000) nil (801 . 802) (800 . 802) ("[" . -800) (800 . 801) nil (789 . 790) (788 . 790) ("[" . -788) (788 . 789) nil ("
" . 832) nil (814 . 818) nil (826 . 827) nil (822 . 826) nil (820 . 822) nil (816 . 820) nil (814 . 816) nil (813 . 814) nil (811 . 813) nil (806 . 811) nil (800 . 801) (" " . 800) (805 . 806) (800 . 801) ("	" . 800) (804 . 805) nil (801 . 804) nil (799 . 801) ("	" . 799) 800 nil (798 . 800) nil (797 . 798) nil (795 . 796) (794 . 796) ("[" . -794) (790 . 795) nil (789 . 790) nil (788 . 789) nil (786 . 787) nil (763 . 764) nil ("j" . -763) 764 nil (766 . 767) nil ("0" . -766) 767 nil (752 . 753) nil ("0" . -752) 753 nil (785 . 787) ("[" . -785) (779 . 786) nil (775 . 779) nil (772 . 775) nil (742 . 743) nil (740 . 741) nil (740 . 741) (nil face font-lock-type-face 739 . 740) (nil fontified nil 739 . 740) (739 . 740) ("{" . -739) (739 . 740) nil (733 . 739) nil (731 . 733) nil (756 . 759) nil (755 . 756) nil (753 . 755) nil (752 . 753) nil (751 . 752) nil (740 . 741) nil ("i" . -740) 741 nil (")" . -751) (751 . 752) (")" . -751) (751 . 752) (750 . 752) ("(" . -750) (750 . 751) nil (747 . 750) nil (746 . 747) nil (743 . 745) nil (742 . 743) nil (741 . 742) nil (739 . 741) nil (738 . 739) nil (737 . 738) nil (658 . 659) nil ("0" . -658) 659 nil (")" . -737) (737 . 738) (")" . -737) (737 . 738) (736 . 738) ("(" . -736) (736 . 737) nil (733 . 736) (t 24250 9844 635662 704000) nil (731 . 733) ("	" . 731) 732 nil (730 . 732) nil ("		
" . 728) nil ("
" . 650) ("	ll n;" . -650) 656 nil (701 . 702) nil ("n" . -701) 702 nil (734 . 737) nil (733 . 734) nil (730 . 732) ("(" . -730) (730 . 731) nil (724 . 730) (723 . 725) ("[" . -723) (723 . 724) nil (")" . -721) (721 . 722) (")" . -721) (721 . 722) (720 . 722) ("(" . -720) (720 . 721) nil (715 . 720) nil ("back" . -715) 719 nil (713 . 719) nil (712 . 714) ("[" . -712) (707 . 713) nil (704 . 707) nil (703 . 704) nil (701 . 702) nil (700 . 702) ("(" . -700) (700 . 701) nil (693 . 700) nil ("digit" . -693) 698 nil (689 . 698) nil ("f" . -689) (" " . -690) 691 nil (689 . 691) nil (688 . 689) nil (687 . 688) nil (685 . 687) nil (684 . 685) nil (678 . 684) nil (669 . 671) nil (664 . 666) nil (663 . 664) nil ("(" . -662) 663 nil (")" . -662) 663 nil (")" . -662) (662 . 663) (")" . -662) (662 . 663) (661 . 663) ("(" . -661) (661 . 662) nil (658 . 661) nil ("REP" . -658) 661 (t 24250 9789 956051 974000) nil ("
" . 235) nil ("
" . 235) nil undo-tree-canary))
