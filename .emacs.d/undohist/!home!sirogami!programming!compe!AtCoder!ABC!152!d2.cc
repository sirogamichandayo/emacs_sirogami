
((digest . "d8e8fca2dc0f896fd7cb4cb0031ba249") (undo-list (5 . 6) nil (1 . 5) nil ("#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

vector<ll> toDigit(ll num)
{
	vector<ll> d;
	while (num)
	{
		d.push_back(num%10);
		num /= 10;
	}
	reverse(d.begin(), d.end());
	return d;
}

vector<ll> toDivisor(ll num)
{
	vector<ll> d;
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

int main(int argc, char **argv)
{
	ll N; cin >> N;

	ll cnt[10][10]{};
	FOR(n, 1, N+1)
	{
		vector<ll> v = toDigit(n);
		++cnt[v.front()][v.back()];
	}

	ll res{0};
	FOR(i, 1, 10)FOR(k, 1, 10)
	{
		res += cnt[i][k] * cnt[k][i];
	}

	std::cout << res << std::endl;
}
" . 1) ((marker . 1) . -24) ((marker) . -25) ((marker) . -25) ((marker) . -46) ((marker) . -46) ((marker) . -47) ((marker) . -47) ((marker) . -69) ((marker) . -69) ((marker) . -70) ((marker) . -70) ((marker) . -96) ((marker) . -96) ((marker) . -124) ((marker) . -124) ((marker) . -125) ((marker) . -125) ((marker) . -169) ((marker) . -169) ((marker) . -197) ((marker) . -197) ((marker) . -234) ((marker) . -234) ((marker) . -235) ((marker) . -235) ((marker) . -262) ((marker) . -262) ((marker) . -264) ((marker) . -264) ((marker) . -279) ((marker) . -279) ((marker) . -292) ((marker) . -292) ((marker) . -295) ((marker) . -295) ((marker) . -318) ((marker) . -318) ((marker) . -331) ((marker) . -331) ((marker) . -334) ((marker) . -334) ((marker) . -364) ((marker) . -364) ((marker) . -375) ((marker) . -375) ((marker) . -377) ((marker) . -377) ((marker) . -378) ((marker) . -378) ((marker) . -407) ((marker) . -407) ((marker) . -409) ((marker) . -409) ((marker) . -424) ((marker) . -424) ((marker) . -457) ((marker) . -457) ((marker) . -460) ((marker) . -460) ((marker) . -478) ((marker) . -478) ((marker) . -482) ((marker) . -482) ((marker) . -501) ((marker) . -501) ((marker) . -505) ((marker) . -505) ((marker) . -530) ((marker) . -530) ((marker) . -534) ((marker) . -534) ((marker) . -553) ((marker) . -553) ((marker) . -576) ((marker) . -576) ((marker) . -580) ((marker) . -580) ((marker) . -583) ((marker) . -583) ((marker) . -594) ((marker) . -594) ((marker) . -596) ((marker) . -596) ((marker) . -597) ((marker) . -597) ((marker) . -629) ((marker) . -629) ((marker) . -631) ((marker) . -631) ((marker) . -648) ((marker) . -648) ((marker) . -649) ((marker) . -649) ((marker) . -668) ((marker) . -668) ((marker) . -684) ((marker) . -684) ((marker) . -687) ((marker) . -687) ((marker) . -716) ((marker) . -716) ((marker) . -746) ((marker) . -746) ((marker) . -749) ((marker) . -749) ((marker) . -750) ((marker) . -750) ((marker) . -762) ((marker) . -762) ((marker) . -790) ((marker) . -790) ((marker) . -793) ((marker) . -793) ((marker) . -825) ((marker) . -825) ((marker) . -828) ((marker) . -828) ((marker) . -829) ((marker) . -829) ((marker) . -861) ((marker) . -861) ((marker) . -610) ((marker) . -614) ((marker) . -623) ((marker) . -627) (t 24250 11370 66883 859000) nil (593 . 594) nil (585 . 593) nil (583 . 585) nil (575 . 576) nil (573 . 574) nil (572 . 573) nil (570 . 572) nil (569 . 570) nil (568 . 570) ("(" . -568) (568 . 569) nil (557 . 568) nil (553 . 557) nil (552 . 553) nil (550 . 551) nil (549 . 551) ("(" . -549) (549 . 550) nil (538 . 549) nil (528 . 529) nil (521 . 528) nil ("^" . -521) 522 nil (517 . 522) nil (516 . 518) ("(" . -516) (516 . 517) nil (515 . 516) nil (520 . 523) (519 . 523) nil (516 . 518) ("			" . 516) (519 . 521) ("{" . -519) (519 . 520) nil (515 . 519) nil (513 . 515) nil (512 . 513) (" x" . -512) (512 . 514) ("else" . 512) (508 . 512) 512 nil (508 . 512) nil (505 . 508) nil (500 . 501) nil (498 . 499) nil (497 . 499) ("(" . -497) (497 . 498) nil (486 . 497) nil (483 . 486) (482 . 486) nil (479 . 481) ("			" . 479) (482 . 484) ("{" . -482) (482 . 483) nil (478 . 482) nil (469 . 477) nil (468 . 469) nil (467 . 468) nil (466 . 468) ("(" . -466) (466 . 467) nil (463 . 466) nil (461 . 463) (460 . 463) nil (458 . 459) ("		" . 458) (460 . 462) ("{" . -460) (460 . 461) nil (457 . 460) nil (452 . 456) nil (451 . 452) nil (446 . 451) nil (445 . 446) nil (443 . 445) nil (442 . 443) nil (440 . 442) nil (439 . 440) nil (431 . 439) nil (430 . 432) ("(" . -430) (430 . 431) nil (426 . 430) nil (424 . 426) nil (423 . 424) nil (421 . 423) nil (420 . 421) nil (418 . 420) nil (417 . 418) nil (411 . 417) nil (410 . 411) (409 . 411) nil ("	" . 408) (409 . 411) ("{" . -409) (409 . 410) nil (407 . 409) nil (400 . 406) nil (399 . 401) ("(" . -399) (399 . 400) nil (397 . 399) nil (389 . 397) nil (388 . 389) nil (386 . 388) nil (385 . 386) nil (379 . 385) nil (377 . 379) (t 24250 10472 610626 7000) nil ("
" . 643) ("	std::cout << __PRETTY_FUNCTION__ << std::endl;" . -643) 690 (t 24250 10451 22810 361000) nil (689 . 690) nil (685 . 689) nil (683 . 685) nil (679 . 683) nil (677 . 679) nil (656 . 677) nil (654 . 656) nil (649 . 654) nil (643 . 644) (" " . 643) (648 . 649) (643 . 644) ("	" . 643) (647 . 648) nil (644 . 647) nil (642 . 644) nil ("
" . 643) ("	o" . -643) 645 nil (644 . 645) nil (642 . 644) nil ("<< std::endl;
" . 643) ("	std::cout << " . -643) 657 nil (669 . 670) nil (665 . 669) nil (663 . 665) nil (659 . 663) nil (657 . 659) nil (656 . 657) nil (654 . 656) nil (649 . 654) nil (643 . 644) (" " . 643) (648 . 649) (643 . 644) ("	" . 643) (647 . 648) nil (644 . 647) nil (642 . 644) (t 24250 10429 586992 914000) nil ("
" . 643) ("		" . -643) 645 nil (625 . 629) nil (637 . 638) nil (633 . 637) nil (631 . 633) nil (627 . 631) nil (625 . 627) nil (624 . 625) nil (622 . 624) nil (617 . 622) nil (611 . 612) (" " . 611) (616 . 617) (611 . 612) ("	" . 611) (615 . 616) nil (612 . 615) (t 24250 10426 131022 295000) nil (610 . 612) ("	" . 610) 611 nil (609 . 611) nil (605 . 606) nil (603 . 604) (602 . 604) ("[" . -602) (602 . 603) nil (600 . 601) (599 . 601) ("[" . -599) (595 . 600) nil (594 . 595) nil (593 . 594) nil (591 . 592) (590 . 592) ("[" . -590) (590 . 591) nil (" " . -590) ("*" . -591) (" " . -592) 593 nil (592 . 593) nil (591 . 592) nil (590 . 591) nil (588 . 589) (587 . 589) ("[" . -587) (577 . 588) nil (575 . 577) (574 . 577) nil (572 . 573) ("		" . 572) (574 . 576) ("{" . -574) (574 . 575) nil (571 . 574) nil (" " . -571) 572 nil (571 . 572) nil (571 . 574) nil ("	}
" . 572) nil ("		
" . 572) nil ("
" . 572) ("	{" . -572) 574 nil (575 . 577) (574 . 577) nil (572 . 573) ("		" . 572) (574 . 576) ("{" . -574) (574 . 575) nil (571 . 574) nil ("	}
" . 572) nil ("		
" . 572) nil ("
" . 572) ("	{" . -572) 574 nil (575 . 577) (574 . 577) nil (572 . 573) ("		" . 572) (574 . 576) ("{" . -574) (574 . 575) nil (571 . 574) nil (567 . 570) nil (566 . 567) nil (565 . 566) nil ("," . -565) 566 nil (565 . 566) nil (564 . 565) nil (563 . 564) nil (562 . 563) nil ("i" . -562) ("," . -563) (" " . -564) 565 nil (564 . 565) nil (563 . 564) nil (562 . 563) nil (")" . -562) (562 . 563) (")" . -562) (562 . 563) (561 . 563) ("(" . -561) (561 . 562) nil (558 . 561) nil ("F" . -557) ("O" . -558) ("R" . -559) 560 nil ("(" . -560) (")" . 561) nil undo-tree-canary))
