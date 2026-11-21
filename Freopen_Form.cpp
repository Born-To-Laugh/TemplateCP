// Born_To_Laugh - Hughie Do
#include <bits/stdc++.h>
#define alle(AC) AC.begin(), AC.end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
[[maybe_unused]] const int MOD = 998244353, INF = 1e9 + 7;

signed main(){
    const string FileName = "";
    if(fopen((FileName + ".INP").c_str(), "r")){
        freopen((FileName + ".INP").c_str(), "r", stdin);
        freopen((FileName + ".OUT").c_str(), "w", stdout);
    }
    else{
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}