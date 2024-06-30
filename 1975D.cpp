#include <bits/stdc++.h>
using namespace std;

int dfs(vector<unordered_map<int, int>> &G, int time, int p, int v){
    G[p][v] = time;
    for(auto &[u, t] : G[v]){
        if(u != p){
            G[u][v] = G[p][v];
            time = dfs(G, time+1, v, u);
        }
    }
    return time+1;
}

int dfsB(vector<vector<pair<int, int>>> &G, int time, int p, int v, vector<bool> &vis, int licznik){
    cout << v << " dziwne\n";
    for(auto &[t, u] : G[v]){
        if(!vis[u] && time >= t){
            vis[u] = true;
            licznik++;
            if(licznik == G.size()-1){
                return time;
            }
            time = dfsB(G, time+1, v, u, vis, licznik);
        }
    }
    for(auto &[t, u] : G[v]){
        if(!vis[u]){
            time = dfsB(G, time+1, v, u, vis, licznik);
            break;
        }
    }
    return time+1;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<unordered_map<int, int>> G(n+1);
        int a, b;
        cin >> a >> b;
        for(int i = 0; i<n-1; i++){
            int x, y;
            cin >> x >> y;
            G[x][y] = 0;
            G[y][x] = 0;
        }
        G[0][a] = 0;
        dfs(G, 0, 0, a);
        vector<vector<pair<int, int>>> G2(n+1);
        for(int i = 1; i<n+1; i++){
            for(auto &[u, t] : G[i]){
                G2[i].push_back({t, u});
            }
        }
        for(int i = 1; i<n+1; i++){
            sort(G2[i].begin(), G2[i].end());
        }
        vector<bool> vis(n+1, 0);
        int licznik = 0;
        if(a==b){
            vis[a] = true;
            licznik++;
        }
        cout << dfsB(G2, 0, 0, b, vis, licznik) << "\n";
        // cout << "Asdf\n";
    }
}