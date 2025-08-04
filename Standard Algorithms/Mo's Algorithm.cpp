#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;
const int MAXA = 1e6 + 5;

int N, Q;
int block_size;
int arr[MAXN];
int ans[MAXQ];

struct Query {
    int l, r, idx;
};

bool compareQueries(const Query& a, const Query& b) {
    int block_a = a.l / block_size;
    int block_b = b.l / block_size;
    if (block_a != block_b) {
        return block_a < block_b;
    }
    if (block_a % 2 == 0) {
        return a.r < b.r;
    }
    return a.r > b.r;
}

int current_answer = 0;
int freq[MAXA];

void add(int idx) {
}

void remove(int idx) {
}

int main() {
    std::cin >> N >> Q;
    block_size = static_cast<int>(sqrt(N));

    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    std::vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        std::cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].idx = i;
    }

    std::sort(queries.begin(), queries.end(), compareQueries);

    int current_l = 0;
    int current_r = -1;

    for (int i = 0; i < Q; ++i) {
        int l = queries[i].l;
        int r = queries[i].r;

        while (current_l > l) {
            current_l--;
            add(current_l);
        }
        while (current_l < l) {
            remove(current_l);
            current_l++;
        }

        while (current_r < r) {
            current_r++;
            add(current_r);
        }
        while (current_r > r) {
            remove(current_r);
            current_r--;
        }

        ans[queries[i].idx] = current_answer;
    }

    for (int i = 0; i < Q; ++i) {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}
