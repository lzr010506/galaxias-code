#include <bits/stdc++.h>
#define ULL unsigned long long
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
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
namespace pollardrho 
{
    ULL gcd(ULL a, ULL b) {return b ? gcd(b, a % b) : a;}

    ULL mulmod(ULL x,ULL y,ULL p)
    {
        __int128 tmp=(__int128)x*(__int128)y;
        return (ULL)(tmp%p);
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

}
set<ll> factors;
int prime[1000010], lfact[1000010];
bool is_prime[1000010];
int sieve(int n)
{
    int p = 0;
    for (int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i]) {prime[p++] = i; lfact[i] = i;}
        for (int j = 0; j < p; j++)
        {
            if (prime[j]*i > n) break;
            is_prime[prime[j]*i] = false;
            lfact[prime[j]*i] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    return p;
}
ll is_square(ll x)
{
    ll d = (ll)sqrt(x);
    for (ll i = max(1LL, d - 5); i <= d + 5; i++) if (i * i == x) return i;
    return -1;
}
int n;
ll a[1000010], b[1000010];
int main()
{
    int p = sieve(1000000);
    scanf("%d", &n);
    rep(i, 1, n)
    {
        scanf("%lld", &a[i]);
        b[i] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if (b[i] % prime[j] == 0)
            {
                factors.insert(prime[j]);
                while (b[i] % prime[j] == 0) b[i] /= prime[j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 1) continue;
        if (pollardrho::test(b[i]))
        {
            factors.insert(b[i]);
            continue;
        }
        ll x = is_square(b[i]);
        if (x != -1)
        {
            factors.insert(x);
            continue;
        }
        ll g = 0;
        for (int j = 1; j <= n; j++)
        {
            if (j == i) continue;
            ll g = __gcd(b[i], b[j]);
            if (g > 1 && g != b[i])
            {
                factors.insert(g);
                factors.insert(b[i] / g);
                break;
            }
        }
    }
    int ans = 0;
    for (auto x : factors)
    {
        //cout << x << endl;
        int cnt = 0;
        rep(j, 1, n)
        {
            if (a[j] % x == 0) cnt ++;
            else
            {
                ans ^= cnt;
                cnt = 0;
            }
        }
        ans ^= cnt;
    }
    if (ans) puts("First");
    else puts("Second");
    return 0;
}