
((digest . "166b8baa2d22562260cc06ac7f9db7a7") (undo-list (1079 . 1109) ("			show(v.begin(), v.end());" . 1079) ((marker . 1079) . -7) ((marker . 1079) . -28) ((marker . 1079) . -28) ((marker . 1079) . -28) ((marker . 1079) . -2) ((marker) . -3) ((marker) . -7) (t 24205 48643 86489 246000) nil (213 . 214) nil ("v" . -213) ((marker . 166) . -1) ((marker . 213) . -1) ((marker . 213) . -1) ("." . -214) ((marker . 166) . -1) 215 nil ("size()" . -215) ((marker . 166) . -6) ((marker*) . 1) ((marker) . -6) ((marker*) . 2) ((marker) . -5) 221 (t 24205 48619 623279 586000) nil ("		}
" . 559) ((marker . 552) . -4) ((marker . 552) . -4) ((marker . 552) . -4) ((marker . 552) . -4) ((marker . 552) . -4) ((marker . 552) . -4) ((marker . 552) . -4) ((marker . 1020) . -4) ((marker . 1020) . -4) nil ("{
" . 528) ((marker . 521) . -2) ((marker . 577) . -2) ((marker . 577) . -2) ((marker*) . 2) ((marker) . -1) ("		" . -528) ((marker . 166) . -2) 530 (t 24205 48612 35539 510000) nil (416 . 417) nil ("		}
" . 416) ((marker . 409) . -4) ((marker . 409) . -4) ((marker . 409) . -4) ((marker . 409) . -4) ((marker . 409) . -4) ((marker . 1110) . -4) ((marker . 409) . -4) ((marker . 409) . -4) ((marker . 410) . -4) ((marker . 410) . -4) nil ("		{
" . 383) ((marker . 376) . -4) ((marker . 552) . -4) ((marker . 552) . -4) nil ("
" . 599) ((marker . 224) . -1) ((marker . 224) . -1) (t 24205 48557 817462 135000) nil (995 . 996) nil ("m" . -995) ((marker . 972) . -1) ((marker . 972) . -1) ((marker . 166) . -1) 996 nil (263 . 266) nil ("size_" . -263) ((marker . 166) . -5) ((marker . 256) . -5) ((marker . 256) . -5) 268 nil ("t" . -268) ((marker . 166) . -1) 269 (t 24205 48461 311207 899000) nil (281 . 282) nil ("v" . -281) ((marker . 166) . -1) ("." . -282) ((marker . 166) . -1) 283 nil ("size()" . -283) ((marker . 166) . -6) ((marker*) . 1) ((marker) . -6) ((marker*) . 2) ((marker) . -5) 289 (t 24205 48451 523330 933000) nil ("	" . 103) nil ("	ll n, m;
" . 114) (113 . 114) ("
" . 103) (104 . 114) nil ("	ll n, m;
" . 162) (114 . 162) ("bool check(const Graph &G, const vector<ll> &v)
" . 104) ((marker . 112) . -33) ((marker . 112) . -39) (152 . 162) nil ("	ll n, m;
" . 164) (162 . 164) ("{
" . 152) (154 . 164) nil ("	ll n, m;
" . 194) (164 . 194) ("	if (v[0] != 0) return false;
" . 154) (184 . 194) nil ("	ll n, m;
" . 195) (194 . 195) ("
" . 184) (185 . 195) nil ("	ll n, m;
" . 232) ((marker . 224) . -10) (195 . 232) ("	vector<bool> seen(v.size(), false);
" . 185) (222 . 232) nil ("	ll n, m;
" . 258) (232 . 258) ("	seen[0] = true; // start
" . 222) (248 . 258) nil ("	ll n, m;
" . 299) ((marker . 281) . -10) (258 . 299) ("	for (size_t i = 0; i < v.size()-1; ++i)
" . 248) ((marker . 224) . -35) (289 . 299) nil ("	ll n, m;
" . 302) ((marker . 284) . -10) ((marker . 284) . -10) (299 . 302) ("	{
" . 289) (292 . 302) nil ("	ll n, m;
" . 322) (302 . 322) ("		ll current{v[i]};
" . 292) (312 . 322) nil ("	ll n, m;
" . 343) ((marker . 325) . -10) ((marker . 325) . -10) ((marker . 325) . -10) ((marker . 325) . -10) ((marker . 325) . -10) ((marker . 325) . -10) ((marker . 325) . -10) (322 . 343) ("		ll target{v[i+1]};
" . 312) ((marker . 284) . -20) (333 . 343) nil ("	ll n, m;
" . 346) ((marker . 328) . -10) ((marker . 328) . -10) ((marker . 328) . -10) ((marker . 328) . -10) ((marker . 328) . -10) ((marker . 328) . -10) (343 . 346) ("		
" . 333) (336 . 346) nil ("	ll n, m;
" . 366) (346 . 366) ("		bool flag{false};
" . 336) ((marker . 325) . -12) (356 . 366) nil ("	ll n, m;
" . 394) (366 . 394) ("		for (auto e : G[current])
" . 356) (384 . 394) nil ("	ll n, m;
" . 398) ((marker . 376) . -10) (394 . 398) ("		{
" . 384) (388 . 398) nil ("	ll n, m;
" . 431) ((marker . 409) . -10) (398 . 431) ("			if (e == target) flag = true;
" . 388) (421 . 431) nil ("	ll n, m;
" . 435) ((marker . 409) . -10) ((marker . 409) . -10) ((marker . 1) . -10) ((marker . 1) . -10) ((marker . 409) . -10) ((marker . 409) . -10) ((marker . 409) . -10) ((marker . 1110) . -10) ((marker . 161) . -10) ((marker . 409) . -10) ((marker . 409) . -10) (431 . 435) ("		}
" . 421) (425 . 435) nil ("	ll n, m;
" . 462) ((marker . 26) . -10) ((marker . 26) . -10) (435 . 462) ("		if (!flag) return false;
" . 425) (452 . 462) nil ("	ll n, m;
" . 490) ((marker . 465) . -10) ((marker . 465) . -10) ((marker . 47) . -10) ((marker . 47) . -10) ((marker . 465) . -10) ((marker . 465) . -10) (462 . 490) ("		else seen[target] = true;
" . 452) ((marker . 409) . -7) ((marker . 409) . -7) ((marker . 409) . -7) ((marker . 1110) . -7) ((marker . 161) . -7) ((marker . 409) . -7) ((marker . 409) . -7) (480 . 490) nil ("	ll n, m;
" . 491) ((marker . 466) . -10) ((marker . 466) . -10) ((marker . 466) . -10) ((marker . 69) . -10) ((marker . 69) . -10) (490 . 491) ("
" . 480) (481 . 491) nil ("	ll n, m;
" . 506) ((marker . 481) . -10) ((marker . 103) . -10) ((marker . 103) . -10) (491 . 506) ("		flag = true;
" . 481) (496 . 506) nil ("	ll n, m;
" . 546) ((marker . 521) . -10) ((marker . 521) . -10) ((marker . 521) . -10) ((marker . 521) . -10) ((marker . 521) . -10) ((marker . 112) . -10) ((marker . 112) . -10) (506 . 546) ("		for (size_t i = 0; i < v.size(); ++i)
" . 496) (536 . 546) nil ("	ll n, m;
" . 550) ((marker . 521) . -10) ((marker . 113) . -10) ((marker . 113) . -10) (546 . 550) ("		{
" . 536) (540 . 550) nil ("	ll n, m;
" . 581) ((marker . 552) . -10) ((marker . 552) . -10) ((marker . 552) . -10) ((marker . 161) . -10) ((marker . 161) . -10) (550 . 581) ("			if (!seen[i]) flag = false;
" . 540) ((marker . 521) . -3) ((marker . 521) . -13) ((marker . 521) . -30) ((marker . 521) . -14) (571 . 581) nil ("	ll n, m;
" . 585) ((marker . 552) . -10) ((marker . 552) . -10) ((marker . 552) . -10) ((marker . 552) . -10) ((marker . 552) . -10) ((marker . 552) . -10) ((marker . 552) . -10) ((marker . 933) . -10) ((marker . 933) . -10) (581 . 585) ("		}
" . 571) (575 . 585) nil ("	ll n, m;
" . 610) ((marker . 577) . -10) ((marker . 577) . -10) ((marker . 577) . -10) ((marker . 577) . -10) ((marker . 577) . -10) ((marker . 912) . -10) ((marker . 912) . -10) (585 . 610) ("		if (flag) return true;
" . 575) ((marker . 552) . -6) ((marker . 552) . -24) (600 . 610) nil ("	ll n, m;
" . 611) ((marker . 224) . -10) ((marker . 224) . -10) (610 . 611) ("
" . 600) (601 . 611) nil ("	ll n, m;
" . 614) ((marker . 580) . -10) ((marker . 580) . -10) ((marker . 250) . -10) ((marker . 250) . -10) (611 . 614) ("	}
" . 601) (604 . 614) nil ("	ll n, m;
" . 615) ((marker . 581) . -10) ((marker . 581) . -10) ((marker . 581) . -10) ((marker . 281) . -10) ((marker . 281) . -10) (614 . 615) ("
" . 604) (605 . 615) nil ("	ll n, m;
" . 630) ((marker . 284) . -10) ((marker . 284) . -10) (615 . 630) ("	return false;
" . 605) ((marker . 580) . -1) ((marker . 580) . -14) (620 . 630) nil ("	ll n, m;
" . 632) ((marker . 598) . -10) ((marker . 466) . -10) ((marker . 466) . -10) (630 . 632) ("}
" . 620) (622 . 632) nil ("	ll n, m;
" . 633) ((marker . 599) . -10) ((marker . 599) . -10) ((marker . 481) . -10) ((marker . 481) . -10) (632 . 633) ("
" . 622) (623 . 633) nil ("	ll n, m;
" . 659) ((marker . 521) . -10) ((marker . 521) . -10) (633 . 659) ("template <class Iterator>
" . 623) (649 . 659) nil ("	ll n, m;
" . 699) ((marker . 665) . -10) ((marker . 665) . -10) ((marker . 665) . -10) ((marker . 665) . -10) ((marker . 665) . -10) ((marker . 577) . -10) ((marker . 577) . -10) (659 . 699) ("void show(Iterator begin, Iterator end)
" . 649) ((marker . 599) . -9) (689 . 699) nil ("	ll n, m;
" . 701) ((marker . 667) . -10) ((marker . 667) . -10) ((marker . 667) . -10) ((marker . 580) . -10) ((marker . 580) . -10) (699 . 701) ("{
" . 689) (691 . 701) nil ("	ll n, m;
" . 732) ((marker . 698) . -10) ((marker . 581) . -10) ((marker . 581) . -10) (701 . 732) ("	for (; begin != end; ++begin)
" . 691) ((marker . 665) . -1) ((marker . 665) . -6) ((marker . 665) . -7) ((marker . 665) . -20) ((marker . 665) . -15) (722 . 732) nil ("	ll n, m;
" . 766) ((marker . 732) . -10) ((marker . 596) . -10) ((marker . 596) . -10) (732 . 766) ("		std::cout << *begin + 1 << \" \";
" . 722) ((marker . 667) . -15) ((marker . 667) . -25) (756 . 766) nil ("	ll n, m;
" . 791) ((marker . 936) . -10) ((marker . 936) . -10) (766 . 791) ("	std::cout << std::endl;
" . 756) ((marker . 698) . -13) (781 . 791) nil ("	ll n, m;
" . 793) ((marker . 937) . -10) ((marker . 937) . -10) ((marker . 166) . -10) (791 . 793) ("}
" . 781) ((marker . 732) . -1) (783 . 793) nil ("	ll n, m;
" . 794) ((marker . 952) . -10) ((marker . 952) . -10) (793 . 794) ("
" . 783) (784 . 794) nil ("	ll n, m;
" . 826) ((marker . 980) . -10) ((marker . 980) . -10) (794 . 826) ("int main(int argc, char **argv)
" . 784) (816 . 826) nil ("	ll n, m;
" . 828) ((marker . 998) . -10) ((marker . 998) . -10) (826 . 828) ("{
" . 816) (818 . 828) (t 24205 48017 528863 848000) nil (458 . 459) (" x" . -458) (458 . 460) ("else" . 458) ((marker . 166) . -4) (454 . 458) 458 nil (454 . 458) nil ("		seen[target] = true;
" . 476) ((marker . 465) . -23) ((marker . 465) . -23) ((marker . 47) . -23) ((marker . 47) . -23) ((marker . 465) . -23) ((marker . 465) . -23) (475 . 476) ("
" . 452) (453 . 476) nil ("		seen[target] = true;
" . 491) ((marker . 466) . -23) ((marker . 466) . -23) ((marker . 466) . -23) ((marker . 69) . -23) ((marker . 69) . -23) (476 . 491) ("		flag = true;
" . 453) (468 . 491) (t 24205 47834 575265 395000) nil ("-" . -1002) ((marker . 166) . -1) ("1" . -1003) ((marker . 166) . -1) 1004 (t 24205 47813 387547 418000) nil (1051 . 1053) ("			" . 1051) nil ("			if (v[0] != 0) break;
" . 1095) (1076 . 1095) ("		if (check(G, v))
" . 1051) (1070 . 1095) nil ("			if (v[0] != 0) break;
" . 1099) ((marker . 1067) . -25) ((marker . 1067) . -3) (1095 . 1099) ("		{
" . 1070) (1074 . 1099) nil ("		{
" . 1099) ((marker . 166) . -3) ((marker . 1067) . -4) (1074 . 1099) ("			if (v[0] != 0) break;
" . 1070) (1095 . 1099) 1098 nil ("			if (v[0] != 0) break;
" . 1099) ((marker . 166) . -24) ((marker . 1067) . -15) (1095 . 1099) ("		{
" . 1070) ((marker . 634) . -3) ((marker . 1044) . -3) ((marker . 1044) . -3) ((marker . 1044) . -3) ((marker . 1044) . -3) (1074 . 1099) 1098 (t 24205 47791 331842 0) nil (1097 . 1098) nil (1091 . 1097) nil (1089 . 1090) nil (1085 . 1089) nil (1083 . 1084) (1082 . 1084) ("[" . -1082) (1081 . 1083) nil (1080 . 1082) ("(" . -1080) (1080 . 1081) nil (1077 . 1080) nil (1073 . 1077) nil (137 . 143) nil ("deque" . -137) ((marker . 112) . -5) ((marker . 166) . -5) 142 nil (993 . 994) nil ("1" . -993) ((marker . 166) . -1) 994 nil (966 . 972) nil ("deque" . -966) ((marker . 166) . -5) 971 nil ("		v.push_front(0);
" . 1049) ((marker . 1020) . -2) ((marker . 1020) . -4) ((marker . 1020) . -16) nil ("		v.pop_front();
" . 1136) ((marker . 1114) . -17) ((marker . 1114) . -2) ((marker . 1114) . -16) nil ("<< std::endl;
" . 1132) ((marker*) . 14) ((marker*) . 14) ("			std::cout << v.size()" . -1132) ((marker . 166) . -24) ((marker*) . 1) ((marker) . -24) ((marker*) . 2) ((marker) . -23) ((marker . 1110) . -24) 1156 (t 24205 47724 596739 905000) nil (")" . -1155) (1155 . 1156) (")" . -1155) (1155 . 1156) (1154 . 1156) ("(" . -1154) (1154 . 1155) nil (")" . -1154) ((marker . 166) . -1) ((marker*) . 1) ((marker) . -1) 1155 nil (1154 . 1155) (")" . -1154) (1154 . 1155) nil (1148 . 1154) nil (1160 . 1161) nil (1156 . 1160) nil (1154 . 1156) nil (1150 . 1154) nil (1148 . 1150) nil (1147 . 1148) nil (1145 . 1147) nil (1140 . 1145) nil (1132 . 1135) ("		" . 1132) (1138 . 1139) (1132 . 1134) ("			" . 1132) ((marker . 166) . -3) (1138 . 1139) nil (1135 . 1138) nil (1131 . 1135) (t 24205 47626 610078 770000) nil (1103 . 1106) ("											" . 1103) ((marker . 1079) . -11) ((marker . 1079) . -8) ((marker . 1079) . -8) ((marker . 1079) . -11) 1139 nil ("//" . -1111) ((marker . 1079) . -2) ((marker . 1079) . -2) 1141 nil (1103 . 1111) ("			" . 1103) (t 24205 47584 518662 423000) nil undo-tree-canary))
