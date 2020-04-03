// Returns: [radius in pattern, (start, end) in actual string] for every element
// Actual length of pattern is 2*N - 1 (A_0 * A_1 * ... * A_N)
// Time complexity: O(N)
template <typename T>
vector<pair<int, pair<int, int>>> manacher(T &pattern) {
    int n = pattern.size();
    vector<pair<int, pair<int, int>>> radius(n);
    int center = 0;
    for (int i = 0; i < n; ++i) {
        auto &rad = radius[i].first;
        if (i <= center + radius[center].first) {
            rad = min(radius[center - (i - center)].first, center + radius[center].first - i);
        }
        while (i - rad - 1 >= 0 && i + rad + 1 < n && pattern[i - rad - 1] == pattern[i + rad + 1]) {
            ++rad;
        }
        if (i % 2 == 0) {
            radius[i].second = {i / 2 - rad / 2, i / 2 + rad / 2};
        } else {
            radius[i].second = {i / 2 - (rad + 1) / 2 + 1, i / 2 + (rad + 1) / 2};
        }
        if (i + rad > center + radius[center].first) {
            center = i;
        }
    }
    return radius;
}

