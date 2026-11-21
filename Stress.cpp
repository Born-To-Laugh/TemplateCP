#include<bits/stdc++.h>
#define fi first
#define se second
#define alle(x) x.begin(), x.end()
typedef long long ll;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int Times = 200;
ll rando(ll l, ll r){ return l + rng() % (r - l + 1); }
void gentest(){
    ofstream fout("inp.txt");
    
    fout.close();
}
signed main(){
    system("g++-15 -std=c++17 -O2 main.cpp -o Program1.exe");
    system("g++-15 -std=c++17 -O2 Source.cpp -o Program2.exe");
    for(int i=1; i<=Times; ++i){
        gentest();
        system("./Program1.exe");
        system("./Program2.exe");
        if(system("diff out.txt ans.txt") != 0){
            cout << "TEST " << i << " WRONG\n";
            return 0;
        }
        else cout << "TEST " << i << " CORRECT\n";
    }
    cout << "AC DI MA\n";
    return 0;
}

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #define ProgramInfo() do{cerr<<"Time: "<<fixed<<setprecision(6)<<((long double)clock()/CLOCKS_PER_SEC)<<"s\n";cerr<<"Memory: "<<(long double)abs(&MemoryMark2-&MemoryMark1)/1048576.0<<" MB"<<"\n";}while(0)
// bool MemoryMark1; // to calculate memory 1
// bool MemoryMark2; // to calculate memory 2