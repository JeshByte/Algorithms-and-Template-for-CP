    vector<int> color(n + 1, -1); 
    ll total_ans = 0;
    bool possible = true;

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            ll cnt0 = 0, cnt1 = 0;
            queue<ll> q;
            
            color[i] = 0;
            cnt0++;
            q.push(i);
            possible=true;
            while (!q.empty()) {
                ll u = q.front();
                q.pop();

                for (ll v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        if (color[v] == 0) cnt0++; else cnt1++;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        possible = false; 
                    }
                }
            }
            if(possible){
                total_ans += max(cnt0, cnt1);
            }
        }
    }
