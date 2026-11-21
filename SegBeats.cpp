// Born_To_Laugh - Hughie Do
#include <bits/stdc++.h>
#define alle(AC) AC.begin(), AC.end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
[[maybe_unused]] const int MOD = 998244353, INF = 1e9 + 7;
const int maxn = 1e6 + 10;
class SegBeat
{
private:
    struct node{
        int mx, smx;
        int cnt, laz;
        ll sum;
        node(int val = 0){
            mx = val;
            smx = -1;
            cnt = 1;
            laz = INF;
            sum = val;
        }
        static node merge(node a, node b){
            node c;
            if(a.mx == b.mx){
                c.mx = a.mx;
                c.cnt = a.cnt + b.cnt;
                c.smx = max(a.smx, b.smx);
            }
            else if(a.mx > b.mx){
                c.mx = a.mx;
                c.cnt = a.cnt;
                c.smx = max(a.smx, b.mx);
            }
            else{
                c.mx = b.mx;
                c.cnt = b.cnt;
                c.smx = max(a.mx, b.smx);
            }
            c.sum = a.sum + b.sum;
            c.laz = INF;
            return c;
        }
    };
    int n;
    vector<node> tree;
    inline void apply(int id, int val){
        if(tree[id].mx <= val) return;
        tree[id].sum -= (ll)(tree[id].mx - val) * tree[id].cnt;
        tree[id].mx = tree[id].laz = val;
    }
    inline void push(int id){
        if(tree[id].laz == INF) return;
        apply(id << 1, tree[id].laz);
        apply(id << 1|1, tree[id].laz);
        tree[id].laz = INF;
    }
    inline void setpos(int id, int l, int r, int pos, int val){
        if(l == r){
            tree[id] = node(val);
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) setpos(id << 1, l, mid, pos, val);
        else setpos(id << 1|1, mid + 1, r, pos, val);
        tree[id] = node::merge(tree[id << 1], tree[id << 1|1]);
    }
    inline void chmin(int id, int l, int r, int lo, int hi, int val){
        if(l > hi || r < lo || val >= tree[id].mx) return;
        if(l >= lo && r <= hi && val > tree[id].smx){
            apply(id, val);
            return;
        }
        int mid = (l + r) >> 1;
        push(id);
        chmin(id << 1, l, mid, lo, hi, val);
        chmin(id << 1|1, mid + 1, r, lo, hi, val);
        tree[id] = node::merge(tree[id << 1], tree[id << 1|1]);
    }
    inline int getmx(int id, int l, int r, int lo, int hi){
        if(l > hi || r < lo) return -INF;
        if(l >= lo && r <= hi) return tree[id].mx;
        int mid = (l + r) >> 1;
        push(id);
        return max(getmx(id << 1, l, mid, lo, hi), getmx(id << 1|1, mid + 1, r, lo, hi));
    }
    inline ll getsum(int id, int l, int r, int lo, int hi){
        if(l > hi || r < lo) return 0;
        if(l >= lo && r <= hi) return tree[id].sum;
        int mid = (l + r) >> 1;
        push(id);
        return getsum(id << 1, l, mid, lo, hi) + getsum(id << 1|1, mid + 1, r, lo, hi);
    }
public:
    inline void init(int len){
        n = len;
        tree.assign(n << 2, node());
    }
    inline void setpos(int pos, int val){
        setpos(1, 1, n, pos, val);
    }
    inline void chmin(int l, int r, int val){
        chmin(1, 1, n, l, r, val);
    }
    inline int getmx(int l, int r){
        return getmx(1, 1, n, l, r);
    }
    inline ll getsum(int l, int r){
        return getsum(1, 1, n, l, r);
    }
};
SegBeat st;
int n, q;
int inp[maxn];
void solve(){
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> inp[i];
    st.init(n);
    for(int i=1; i<=n; ++i) st.setpos(i, inp[i]);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r, x; cin >> l >> r >> x;
            st.chmin(l, r, x);
        }
        else if(t == 2){
            int l, r; cin >> l >> r;
            cout << st.getmx(l, r) << '\n';
        }
        else{
            int l, r; cin >> l >> r;
            cout << st.getsum(l, r) << '\n';
        }
    }
}
signed main(){
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}