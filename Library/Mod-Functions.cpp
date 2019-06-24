namespace ModFunctions {
	const int F = 3e5 + 10;

	int fact[F], inv_fact[F];

	inline void add(int &a, int b, int mod = MOD) {
		a += b;
		if (a >= mod) {
			a -= mod;
		}
	}

	inline void sub(int &a, int b, int mod = MOD) {
		a -= b;
		if (a < 0) {
			a += mod;
		}
	}

	inline int mul(int a, int b, int mod = MOD) {
		return int((1ll * a * b) % mod);
	}

	inline int power(int a, ll b, int mod = MOD) {
		int res = 1;
		while (b > 0) {
			if (b & 1) {
				res = mul(res, a, mod);
			}
			a = mul(a, a, mod);
			b >>= 1;
		}
		return res;
	}

	inline int inv(int a, int mod = MOD) {
		a %= mod;
		if (a < 0) {
			a += mod;
		}
		int b = mod, u = 0, v = 1;
		while (a) {
			int t = b / a;
			b -= t * a;
			swap(a, b);
			u -= t * v;
			swap(u, v);
		}
		assert(b == 1);
		if (u < 0) {
			u += mod;	
		}
		return u;
	}

	void pre_build(int mod = MOD) {
		fact[0] = 1;
		for (int i = 1; i < F; ++i) {
			fact[i] = mul(fact[i - 1], i, mod);
		}
		inv_fact[F - 1] = inv(fact[F - 1], mod);
		for (int i = F - 2; i >= 0; --i) {
			inv_fact[i] = mul(inv_fact[i + 1], i + 1, mod);
		}
	}

	int choose(int x, int y, int mod = MOD) {
		if (x < y) {
			return 0;
		}
		return mul(fact[x], mul(inv_fact[y], inv_fact[x - y], mod), mod);
	}
}

using namespace ModFunctions;