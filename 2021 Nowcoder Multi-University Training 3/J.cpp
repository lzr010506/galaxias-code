#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;

namespace GenHelper
{
    unsigned z1,z2,z3,z4,b,u;
    unsigned get()
    {
        b=((z1<<6)^z1)>>13;
        z1=((z1&4294967294U)<<18)^b;
        b=((z2<<2)^z2)>>27;
        z2=((z2&4294967288U)<<2)^b;
        b=((z3<<13)^z3)>>21;
        z3=((z3&4294967280U)<<7)^b;
        b=((z4<<3)^z4)>>12;
        z4=((z4&4294967168U)<<13)^b;
        return (z1^z2^z3^z4);
    }
    bool read() {
      while (!u) u = get();
      bool res = u & 1;
      u >>= 1; return res;
    }
    void srand(int x)
    {
        z1=x;
        z2=(~x)^0x233333333U;
        z3=x^0x1234598766U;
        z4=(~x)+51;
        u = 0;
    }
}
using namespace GenHelper;
bool edge[8005][8005];
int w[8005], bb[8005];
int main()
{
    int n, seed;
    cin >> n >> seed;

    srand(seed);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            edge[j][i] = edge[i][j] = read();
            if(edge[i][j]) w[i] ++, w[j] ++;
            else bb[i] ++, bb[j] ++;
        }
    //rep0(i, n) cout << bb[i] << " " << w[i] << endl; 
    ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
    ll del = 0;
    rep0(i, n)
    {
        del += 1LL * bb[i] * w[i];
    }
    cout << ans - del / 2;
    return 0;
}