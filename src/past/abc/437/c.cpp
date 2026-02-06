# include <bits/stdc++.h>
using namespace std;

struct Node {
    long long w;   // 重さ
    long long v;   // 価値（元の W の合計）
    int c;         // 個数
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> w(N), p(N), orig_w(N);
        long long Wsum = 0;

        for (int i = 0; i < N; i++) {
            cin >> w[i] >> p[i];
            orig_w[i] = w[i];
            Wsum += w[i];
            w[i] += p[i];   // 制約用の重さ
        }

        int n1 = N / 2;
        int n2 = N - n1;

        vector<Node> A, B;

        // 前半
        for (int mask = 0; mask < (1 << n1); mask++) {
            long long sw = 0, sv = 0;
            int cnt = 0;
            for (int i = 0; i < n1; i++) {
                if (mask & (1 << i)) {
                    sw += w[i];
                    sv += orig_w[i];
                    cnt++;
                }
            }
            if (sw <= Wsum) A.push_back({sw, sv, cnt});
        }

        // 後半
        for (int mask = 0; mask < (1 << n2); mask++) {
            long long sw = 0, sv = 0;
            int cnt = 0;
            for (int i = 0; i < n2; i++) {
                if (mask & (1 << i)) {
                    sw += w[n1 + i];
                    sv += orig_w[n1 + i];
                    cnt++;
                }
            }
            if (sw <= Wsum) B.push_back({sw, sv, cnt});
        }

        // 後半を重さ昇順に並べる
        sort(B.begin(), B.end(), [](const Node &a, const Node &b) {
            if (a.w != b.w) return a.w < b.w;
            return a.v > b.v;
        });

        // 同じ重さ以下で「価値最大，価値が同じなら個数最大」に圧縮
        vector<Node> B2;
        long long best_v = -1;
        int best_c = 0;

        for (auto &x : B) {
            if (x.v > best_v || (x.v == best_v && x.c > best_c)) {
                best_v = x.v;
                best_c = x.c;
                B2.push_back({x.w, best_v, best_c});
            }
        }

        long long ans_v = 0;
        int ans_c = 0;

        for (auto &a : A) {
            long long rem = Wsum - a.w;
            auto it = upper_bound(
                B2.begin(), B2.end(),
                rem,
                [](long long val, const Node &x) {
                    return val < x.w;
                }
            );
            if (it == B2.begin()) continue;
            --it;

            long long total_v = a.v + it->v;
            int total_c = a.c + it->c;

            if (total_v > ans_v || (total_v == ans_v && total_c > ans_c)) {
                ans_v = total_v;
                ans_c = total_c;
            }
        }

        // 価値（元の W の最大値）と個数を出力
        cout << ans_v << " " << ans_c << '\n';
    }

    return 0;
}
