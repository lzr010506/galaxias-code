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
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
    char c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}

inline ll read1() {
    char c; ll x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10LL + c - '0'; } return x;
}
#define ULL unsigned long long
vector<ll> fac;
namespace pollardrho 
{
    ULL gcd(ULL a, ULL b) {return b ? gcd(b, a % b) : a;}

    ULL mulmod(ULL x,ULL y,ULL p)
    {
        ULL z=(long double)x/p*y;
        ULL res=(ULL)x*y-(ULL)z*p;
        return (res+p)%p;
    }

    ULL powmod(ULL b, ULL e, ULL m) 
    {
        ULL r = 1;
        while (e) 
        {
            if (e & 1) r = mulmod(r, b, m);
            b = mulmod(b, b, m);
            e >>= 1;
        }
        return r;
    }

    bool test(ULL n)
    {
        if (n < 3) return n==2;
        // ! The array a[] should be modified if the range of x changes.
        static const ULL a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23,  ULLONG_MAX};//works for 1e18
        ULL r = 0, d = n-1, x;
        while (~d & 1) d >>= 1, r++;
        for (int i=0; a[i] < n; i++)
        {
            x = powmod(a[i], d, n);
            if (x == 1 || x == n-1) goto next;
            for(int i=0;i<r;i++)
            {
                x = mulmod(x, x, n);
                if (x == n-1) goto next;
            }
            return false;
            next:;
        }
        return true;
    }

    map<ULL, int> mp;
    mt19937_64 gen(time(NULL));

    void PollardRho(ULL n) 
    {
        ULL c, x, y, d;
        while (n % 2 == 0) 
        {
            mp[2]++;
            n /= 2;
        }
        if (n == 1) return;

        if (test(n)) 
        {
            mp[n]++;
            return;
        }

        d = n;
        static int counter = 0;
        while (d == n) 
        {
            x = y = 2;
            d = 1;
            c = gen() % (n - 1) + 1;
            while (d == 1) 
            {
                counter++;
                x = (mulmod(x, x, n) + c) % n;
                y = (mulmod(y, y, n) + c) % n;
                y = (mulmod(y, y, n) + c) % n;
                d = gcd(x > y ? x - y : y - x, n);
            }
        }
        PollardRho(d);
        PollardRho(n / d);
    }

    void work(ULL n) 
    {
        if(n == 0) return;
        PollardRho(n);
        for(auto p:mp) fac.pb((ll)p.X);
        mp.clear();
    }
};
using namespace pollardrho;
const int N = 2e5 + 10;
ll a[N];
unordered_map<ll, int> num, used;
int main()
{
    mt19937_64 gen(time(NULL));
    //work(100);
    //puts("111");
    int T = read();
    while(T --)
    {
        int n = read();
        rep(i, 1, n) a[i] = read1();
        int cnt0 = 0, cnt1 = 0;
       // puts("1111");
        rep(i, 1, n) 
            if(a[i] & 1) cnt1 ++;
            else cnt0 ++;
        used.clear();
        int ans;
        used[2] = 1;
        ans = max(cnt0, cnt1);
        int lim = 50;
        fac.clear();
        rep(p, 1, lim)
        {
            int x = gen() % n + 1;
            int y = gen() % n + 1;
            ll tmp = a[x] - a[y];
            if(tmp < 0) tmp = -tmp;
//            cout << tmp << endl;
            work(tmp);
        }
        rep0(i, (int)sz(fac))
        {
            ll pp = 0;
            int cnt = 0, mx = 0;
            num.clear();
            rep(j, 1, 10)
            {
                int pos = gen() % n + 1;
                ll x = a[pos] % fac[i];
                num[x] ++;
                if(num[x] > mx)
                {
                    mx = num[x];
                    pp = x;
                }
            }
            rep(j, 1, n)
            {
                ll x = a[j] % fac[i];
                if(x == pp) cnt ++;
            }
            ans = max(ans, cnt);
        }
        printf("%d\n",ans);
    }

}