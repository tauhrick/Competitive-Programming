template <typename T>
class Fenwick {
public:
	vector<T> Fenw;
	int n;

	Fenwick(int _n) : n(_n) {
		Fenw.rezize(n);
	}

	void modify(int x, T v) {
		while (x < n) {
			Fenw[x] += v;
			x |= (x + 1);
		}
	}

	T get(int x) {
		T v{};
		while (x >= 0) {
			v += Fenw[x];
			x = (x & (x + 1)) - 1;
		}
		return v;
	}
};