// Born_To_Laugh - Hughie Do
#include <bits/stdc++.h>
#define alle(AC) AC.begin(), AC.end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
[[maybe_unused]] const int MOD = 998244353, INF = 1e9 + 7;
 
struct Treap
{
    struct node{
        ll val, sum;
        int pri, sz;
        array<int, 2> child;
        int lazrev;
        node(int num = -INF){
            if(num == -INF){
                val = pri = lazrev = sum = sz = 0;
                child = {0, 0};
                return;
            }
            val = sum = num;
            sz = 1;
            lazrev = 0;
            child = {0, 0};
            pri = rnd();
        }
    };
    int cntnode = 0;
    vector<node> tree;
    int init(){
        tree.assign(1, node());
        return cntnode = 0;
    }
    int new_node(int val){
        cntnode++;
        tree.push_back(node(val));
        return cntnode;
    }
    void pull(int id){
        if(id == 0) return;
        int l = tree[id].child[0], r = tree[id].child[1];
        tree[id].sz = tree[l].sz + tree[r].sz + 1;
        tree[id].sum = tree[l].sum + tree[r].sum + tree[id].val;
    }
    void apply_rev(int id){
        if(id == 0) return;
        swap(tree[id].child[0], tree[id].child[1]);
        tree[id].lazrev ^= 1;
    }
    void push(int id){
        if(id == 0 || tree[id].lazrev == 0) return;
        apply_rev(tree[id].child[0]);
        apply_rev(tree[id].child[1]);
        tree[id].lazrev = 0;
    }
    int merge(int l, int r){
        if(!l || !r) return (l > 0) ? l : r;
        push(l), push(r);
        if(tree[l].pri < tree[r].pri){
            tree[l].child[1] = merge(tree[l].child[1], r);
            pull(l);
            return l;
        }
        else{
            tree[r].child[0] = merge(l, tree[r].child[0]);
            pull(r);
            return r;
        }
    }
    pair<int, int> split(int id, int pos){
        if(id == 0) return {0, 0};
        push(id);
        int v = tree[tree[id].child[0]].sz;
        if(v >= pos){
            pair<int, int> sth = split(tree[id].child[0], pos);
            tree[id].child[0] = sth.se;
            pull(id);
            return {sth.fi, id};
        }
        else{
            pair<int, int> sth = split(tree[id].child[1], pos - v - 1);
            tree[id].child[1] = sth.fi;
            pull(id);
            return{id, sth.se};
        }
    }
 
    void upd_rev(int &root, int l, int r){
        pair<int, int> a = split(root, l - 1); // 1 -> l - 1, l -> n
        pair<int, int> b = split(a.se, r - l + 1); // l -> r, r + 1 -> n
        apply_rev(b.fi);
        root = merge(a.fi, merge(b.fi, b.se));
    }
    ll get_sum(int &root, int l, int r){
        pair<int, int> a = split(root, l - 1); // 1 -> l - 1, l -> n;
        pair<int, int> b = split(a.se, r - l + 1);
        ll ans = tree[b.fi].sum;
        root = merge(a.fi, merge(b.fi, b.se));
        return ans;
    }
};
 
const int maxn = 2e5 + 10;
Treap treap;
int n, q, root;
int inp[maxn];
 
void solve(){
    cin >> n >> q;
    root = treap.init();
    for(int i=1; i<=n; ++i){
        cin >> inp[i];
        root = treap.merge(root, treap.new_node(inp[i]));
    }
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r;
            treap.upd_rev(root, l, r);
        }
        else{
            int l, r; cin >> l >> r;
            cout << treap.get_sum(root, l, r) << '\n';
        }
    }
}
signed main(){
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}