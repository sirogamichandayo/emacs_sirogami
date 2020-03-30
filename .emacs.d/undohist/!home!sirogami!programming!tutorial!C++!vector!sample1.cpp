
((digest . "d41d8cd98f00b204e9800998ecf8427e") (undo-list nil ("#include <iostream>
#include <vector>

class myVector : std::vector<int>
{
public:	
	~myVector()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

struct A
{
	myVector vec_;

public:
	A()
	{
		vec_.resize(10);
		for (int i = 0; i < 10; ++i)
		{
			vec_.push_back(i);
		}
	}
};
" . 1) ((marker . 1) . -20) ((marker . 1) . -37) ((marker . 1) . -56) ((marker) . -75) ((marker) . -75) ((marker) . -84) ((marker) . -84) ((marker) . -97) ((marker) . -97) ((marker) . -100) ((marker) . -100) ((marker) . -38) ((marker) . -38) ((marker) . -20) ((marker) . -20) ((marker) . -39) ((marker) . -39) ((marker) . -149) ((marker) . -149) ((marker) . -152) ((marker) . -152) ((marker) . -155) ((marker) . -155) ((marker) . -156) ((marker) . -156) ((marker) . -165) ((marker) . -165) ((marker) . -167) ((marker) . -167) ((marker) . -219) ((marker) . -219) ((marker) . -183) ((marker) . -183) ((marker) . -250) ((marker) . -250) ((marker . 1) . -194) ((marker) . -254) ((marker) . -254) ((marker . 1) . -197) ((marker) . -197) ((marker) . -197) ((marker) . -276) ((marker) . -276) ((marker . 1) . -221) ((marker) . -280) ((marker) . -280) ((marker . 1) . -253) ((marker) . -192) ((marker) . -192) ((marker) . -184) ((marker) . -184) ((marker . 1) . -257) ((marker . 1) . -275) ((marker . 1) . -198) ((marker) . -73) ((marker) . -73) ((marker . 1) . -198) ((marker . 1) . -86) ((marker . 1) . -183) ((marker . 1) . -85) ((marker . 1) . -85) ((marker . 1) . -85) ((marker . 1) . -126) ((marker . 1) . -85) ((marker) . -200) ((marker) . -200) ((marker . 1) . -83) ((marker . 1) . -171) ((marker . 1) . -78) ((marker . 1) . -169) ((marker . 1) . -272) ((marker . 1) . -272) ((marker . 1) . -274) ((marker) . -283) ((marker) . -283) ((marker) . -214) ((marker) . -216) ((marker) . -214) ((marker) . -216) ((marker) . -272) ((marker) . -273) ((marker) . -272) ((marker) . -273) ((marker . 1) . -237) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) ((marker . 1) . -215) nil (218 . 219) nil (215 . 217) nil (214 . 216) ("(" . -214) (214 . 215) nil (203 . 214) nil (200 . 203) (t 24189 44631 571221 973000) nil (266 . 267) nil ("<" . -177) ((marker . 1) . -1) 178 nil ("int>" . -178) ((marker . 1) . -4) ((marker*) . 1) ((marker) . -4) 182 nil (79 . 81) nil ("i" . -79) ((marker . 1) . -1) ((marker . 1) . -1) ("l" . -80) ((marker . 1) . -1) ((marker . 1) . -1) 81 (t 24189 44601 947292 312000) nil (82 . 83) nil (76 . 82) nil (75 . 77) (t 24189 44587 971325 514000) nil (69 . 72) nil ("T" . -69) ((marker . 1) . -1) 70 nil ("late <class T>
" . 40) ("temp" . -40) ((marker . 1) . -4) 44 nil ("	" . 198) (205 . 206) nil (199 . 205) nil (197 . 199) nil (261 . 262) nil (259 . 260) nil (258 . 260) ("(" . -258) (258 . 259) nil (244 . 258) nil (241 . 244) (240 . 244) nil (237 . 239) ("			" . 237) ((marker . 1) . -3) (240 . 242) ("{" . -240) (240 . 241) nil (236 . 240) nil (231 . 235) nil (230 . 231) nil (227 . 230) nil (226 . 227) nil (223 . 226) nil (222 . 223) nil (213 . 222) nil (212 . 214) ("(" . -212) (212 . 213) nil (209 . 212) nil ("r" . -209) ((marker . 1) . -1) 210 nil (208 . 210) nil ("v" . -208) ((marker . 1) . -1) ((marker . 1) . -1) ("e" . -209) ((marker . 1) . -1) ((marker . 1) . -1) 210 nil undo-tree-canary))
