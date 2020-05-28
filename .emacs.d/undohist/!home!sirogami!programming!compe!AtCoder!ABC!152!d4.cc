
((digest . "086331f7a0c43a9d5b28c11f02f74c32") (undo-list nil (274 . 275) ("	" . 274) (t 24271 8614 84715 629000) nil ("
" . 240) ((marker) . -1) ((marker) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker) . -1) nil ("
" . 241) ((marker) . -1) ((marker) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker) . -1) (t 24271 8323 206601 897000) nil ("template<int mod> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % mod) {
        if (val < 0) val += mod;
    }
    constexpr int getmod() { return mod; }
    constexpr Fp operator - () const noexcept {
        return val ? mod - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % mod;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = mod, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % mod;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<mod>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<mod> modpow(const Fp<mod> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
	friend constexpr Fp<mod> modfac(long long l, long long r) noexcept
	{
		auto res = Fp<mod>(1);
		for (Fp<mod> i = l; i < r; ++i) res *= i;
		return res;
	}
};
using mint = Fp<1000000007>;
" . 240) ((marker . 240) . -2074) ((marker) . -758) ((marker) . -758) ((marker . 240) . -2074) ((marker . 276) . -672) ((marker . 276) . -672) ((marker . 274) . -694) ((marker . 274) . -694) ((marker . 272) . -730) ((marker . 272) . -730) ((marker) . -752) ((marker) . -752) ((marker . 240) . -2045) ((marker . 240) . -2045) ((marker . 240) . -2045) ((marker . 240) . -2045) ((marker . 240) . -2045) ((marker . 240) . -2074) ((marker . 240) . -2074) ((marker . 240) . -2074) ((marker . 240) . -2074) ((marker . 240) . -2074) ((marker) . -2074) ((marker . 240) . -2025) ((marker . 240) . -2025) ((marker . 240) . -2025) ((marker . 240) . -2025) ((marker . 240) . -2025) (t 24271 8282 738780 985000) nil (240 . 2314) (t 24271 8262 438861 294000) nil (239 . 240) nil ("}
" . 240) ((marker . 240) . -2) ((marker . 240) . -2) ((marker . 240) . -2) ((marker . 240) . -2) ((marker . 240) . -2) nil ("	return res;
" . 240) nil ("	for (ll i = n; i >= a; --i) (res *= i) %= MOD;
" . 240) ((marker . 240) . -48) nil ("	ll res{1};
" . 240) nil ("{
" . 240) ((marker*) . 2) ((marker) . -1) nil ("ll modFac(ll n, ll a)
" . 240) nil ("
" . 339) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) ((marker . 240) . -1) nil ("
" . 340) nil (338 . 340) nil (335 . 336) nil (325 . 335) nil (323 . 325) nil (322 . 323) nil (319 . 322) ("mod" . 319) nil (315 . 322) nil (311 . 314) nil (310 . 311) nil (306 . 310) nil (305 . 307) ("(" . -305) (305 . 306) nil (304 . 305) nil (299 . 303) nil (298 . 299) nil (295 . 298) nil (294 . 295) nil (291 . 294) nil (290 . 291) nil (282 . 290) nil (281 . 283) ("(" . -281) (281 . 282) nil (277 . 281) nil (275 . 277) nil (274 . 275) nil (272 . 273) nil (271 . 273) ("{" . -271) (271 . 272) nil (265 . 271) nil (264 . 265) (263 . 265) nil ("	" . 262) (263 . 265) ("{" . -263) (263 . 264) nil (261 . 263) nil (255 . 260) nil (254 . 255) nil (250 . 254) nil (249 . 251) ("(" . -249) (249 . 250) nil (240 . 249) (t 24271 7261 698801 174000) nil undo-tree-canary))
