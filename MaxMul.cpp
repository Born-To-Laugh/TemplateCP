// Born_To_Laugh - Hughie Do
#include <bits/stdc++.h>
#define alle(Lotus) Lotus.begin(), Lotus.end()
using namespace std;
typedef long long ll;
[[maybe_unused]] const ll MOD = 998244353, INF = 1e9 + 7;

const int maxn = 5e5 + 10;
int n;
vector<int> sz(maxn, 1), dep(maxn, 1), bigchild(maxn, -1);
vector<int> bitm(maxn, 0);
vector<int> besdep((1 << 22) + 5, -1);
vector<int> ans(maxn, 0);
vector<int> clearlist;
vector<pair<int,int>> adj[maxn];

int lat_bit(int x, int i){
    x ^= (1 << i);
    return x;
}
void pre_dfs(int a, int par){
    for(auto &sth: adj[a]){
        int elm = sth.first;
        int wei = sth.second;
        if(elm == par)continue;

        dep[elm] = dep[a] + 1;
        bitm[elm] = lat_bit(bitm[a], wei);
        pre_dfs(elm, a);

        sz[a] += sz[elm];
        if(bigchild[a] == -1 || sz[bigchild[a]] < sz[elm])bigchild[a] = elm;
    }
}

void calc(int a, int par, int root){
    for(auto &sth: adj[a]){
        int elm = sth.first;
        if(elm == par)continue;
        calc(elm, a, root);
    }

    int sth = bitm[a];
    if(besdep[sth] != -1){
        ans[root] = max(ans[root], besdep[sth] + dep[a] - 2 * dep[root]);
    }
    for(int i=0; i<22; ++i){
        sth = lat_bit(bitm[a], i);
        if(besdep[sth] != -1){
            ans[root] = max(ans[root], besdep[sth] + dep[a] - 2 * dep[root]);
        }
    }
}

void add(int a, int par, bool godown){
    if(besdep[bitm[a]] == -1) clearlist.push_back(bitm[a]);
    besdep[bitm[a]] = max(besdep[bitm[a]], dep[a]);

    if(!godown)return;
    for(auto &sth: adj[a]){
        int elm = sth.first;
        if(elm == par)continue;
        add(elm, a, 1);
    }
}
void cleardata(){
    for(auto &elm: clearlist){
        besdep[elm] = -1;
    }
    claerlist.clear();
}
void dfs(int a, int par){
    for(auto &sth: adj[a]){
        int elm = sth.first;
        if(elm == par || elm == bigchild[a])continue;
        dfs(elm, a);
        cleardata();
        ans[a] = max(ans[a], ans[elm]);
    }

    if(bigchild[a] != -1){
        dfs(bigchild[a], a);
        ans[a] = max(ans[a], ans[bigchild[a]]);
    }

    for(auto &sth: adj[a]){
        int elm = sth.first;
        if(elm == par || elm == bigchild[a])continue;
        calc(elm, a, a);
        add(elm, a, 1);
    }

    int root = a;
    int sth = bitm[a];
    if(besdep[sth] != -1){
        ans[root] = max(ans[root], besdep[sth] + dep[a] - 2 * dep[root]);
    }
    for(int i=0; i<22; ++i){
        sth = lat_bit(bitm[a], i);
        if(besdep[sth] != -1){
            ans[root] = max(ans[root], besdep[sth] + dep[a] - 2 * dep[root]);
        }
    }

    add(a, par, 0);
}

void solve(){
    cin >> n;
    for(int i=2; i<=n; ++i){
        int x;char y;cin >> x >> y;
        adj[i].push_back({x, y - 'a'});
        adj[x].push_back({i, y - 'a'});
    }
    pre_dfs(1, -1);
    dfs(1, -1);
    for(int i=1; i<=n; ++i){
        cout << ans[i] << ' ';
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}