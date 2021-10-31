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
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
    char c, _c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
#define ld long double
const long double eps = 1e-9;
const int N = 110;
pair<int, int> p[N];
vector<int> ord;
int sx[N];

bool cmp(int i, int j)
{
    if(p[i].Y != p[j].Y) return p[i].Y < p[j].Y;
    return p[i].X < p[j].X;
}

bool cmp1(int i, int j)
{
    ll xa = p[i].X - p[ord[0]].X;
    ll ya = p[i].Y - p[ord[0]].Y;
    ll xb = p[j].X - p[ord[0]].X;
    ll yb = p[j].Y - p[ord[0]].Y;
    if(xa * yb - xb * ya != 0) return xa * yb - xb * ya > 0;
    return xa * xa + ya * ya < xb * xb + yb * yb;
}
vector<ld> x, y;
void bpm(ld a, ld b, ld c)
{
    if(x.size() < 3) return;
    x.pb(x[0]);
    y.pb(y[0]);
    vector<ld> nx, ny;
    rep0(j, sz(x) - 1)
    {
        ld z = a * x[j] + b * y[j] + c;
        if(z > -eps) nx.pb(x[j]), ny.pb(y[j]);
        ld z2 = a * x[j + 1] + b * y[j + 1] + c;
        if((z > eps && z2 < -eps) || (z < -eps && z2 > eps))
        {
            ld aa = y[j + 1] - y[j];
            ld bb = x[j] - x[j + 1];
            ld cc = -aa * x[j] - bb * y[j];
            ld d = a * bb - b * aa;
            ld dx = (b * cc - c * bb) / d;
            ld dy = (c * aa - a * cc) / d;
            nx.pb(dx);
            ny.pb(dy);
        }
    }
    swap(x, nx);
    swap(y, ny);
};

int main()
{
    int dx, dy, n;
    scanf("%d%d%d", &dx, &dy, &n);
    rep0(i, n) scanf("%d%d", &p[i].X, &p[i].Y);
    rep0(i, n) scanf("%d", &sx[i]), sx[i] --, ord.pb(i);
    sort(ord.begin(), ord.end(), cmp);
    sort(ord.begin() + 1, ord.end(), cmp1);
    vector<int> st;
    for(int i : ord)
    {
        //cout << i << " ";
        while(st.size() >= 2)
        {
            int pt1 = st[st.size() - 1], pt2 = st[st.size() - 2];
            ll a = p[pt1].Y - p[pt2].Y;
            ll b = p[pt2].X - p[pt1].X;
            ll c = -a * p[pt1].X - b * p[pt1].Y;
            ll z = a * p[i].X + b * p[i].Y + c;
            if(z >= 0)  st.pop_back();
            else break;
        }
        st.pb(i);
    }
    x = {0, (ld)dx, (ld)dx, 0};
    y = {0, 0, (ld)dy, (ld)dy};
  //  cout << sz(x) << endl;
    rep0(i, n - 1)
    {
        ld a = p[sx[i + 1]].Y - p[sx[i]].Y;
        ld b = p[sx[i]].X - p[sx[i + 1]].X;
        ld c = -a * p[sx[i]].X - b * p[sx[i]].Y;
        bpm(a, b, c);
    }
    //cout << sz(x);
    ld area = 0;
    rep0(i, sz(x)) area += (x[i] - x[(i + 1) % (int)x.size()]) * (y[i] + y[(i + 1) % (int)y.size()]);
    //cout << area << endl;
    ld res = abs(area) * 0.5;

  // cout << sz(st) << endl;
    if(st.size() >= 3)
    {
        st.pb(st[0]);
        rep0(i, sz(st) - 1)
        {
            ld a = p[st[i + 1]].Y - p[st[i]].Y;
            ld b = p[st[i]].X - p[st[i + 1]].X;
            ld c = -a * p[st[i]].X - b * p[st[i]].Y;
            bpm(-a, -b, -c);
        }
        area = 0;
        rep0(i, sz(x)) area += (x[i] - x[(i + 1) % (int)x.size()]) * (y[i] + y[(i + 1) % (int)y.size()]);
    //    cout << area << endl;
        res -= abs(area) * 0.5;
    }
    printf("%.10Lf\n", res);
}