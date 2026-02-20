const ll MAXN = 100005;
const ll K = 20; 

ll st[MAXN][K];
ll logs[MAXN];


void precomputeLogs(ll n) {
    logs[1] = 0;
    for (int i = 2; i <= n; i++)
        logs[i] = logs[i / 2] + 1;
}


void build(const vector<ll>& arr, ll n) {
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}


ll query(ll L, ll R) {
    ll j = logs[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}
