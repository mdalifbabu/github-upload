#include <bits/stdc++.h>
#define sc              scanf
#define pf              printf
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)           push_back(a)
#define vi(a)           vector<a>
#define pii(a, b)       pair<a, b>
#define MP              make_pair
#define db              double
#define ll              long long
#define eps             1e-9
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define D(x)            cout<<#x " = "<<(x)<<endl
#define MOD             100007
#define MAX             INT_MAX
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define auto(x, a)      for(auto x: a)
#define PRINT_CASE      printf("Case %d: ",z)
#define CASE_PRINT      cout<<"Case "<<z<<":"<<endl;
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long
#define vprint(v)       auto(x, v)cout<<x<<" ";cout<<endl;
#define bp(n)           __builtin_popcount(n)
#define Read(a)         freopen(a, "r", stdin);
#define Write(a)        freopen(a, "w", stdout);
using namespace std;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0}; const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1}; const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*-----------------------Bitmask------------------*//*
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int lcm(int a, int b) {  return a * (b / __gcd(a, b)); }

/*---------------------Prime Sieve--------------------------*//*
ll _sieve_size;bitset<100000100>bs;vi(ll) primes;
void sieve(ll upperbound) {_sieve_size = upperbound +1;bs.set();bs[0] = bs[1] = 0;
    for(ll i = 2; i < _sieve_size; i++)if(bs[i]){for(ll j = i*i; j <= _sieve_size; j += i)bs[j] = 0; primes.pb((int)i);}}
bool isPrime(ll N) {if(N <= _sieve_size)return bs[N];for(int i = 0; i < (int)SZ(primes); i++)if(N % primes[i] == 0)return false; return true;}
/*-----------------------Big MOD----------------------------*//*
ll big_mod(ll base, ll power, ll mod){
    if(power == 0)return  1;else if(power & 1){ll p1 = base % mod; ll p2 = (big_mod(base, power-1, mod)) % mod; return (p1 * p2) % mod;}
    else{ ll p1 = (big_mod(base, power/2, mod)) % mod; return (p1 * p1) % mod; }}
/*---------------------Segment Tree-----------------------------*//*
struct data{ll val, prop; bool mark;};
vector<data>t(100005*4);
void build(int a[], int v, int lf, int rt){if(lf==rt){t[v].val = a[lf];}
else{int md = (lf+rt) / 2; build(a, v*2, lf, md); build(a, v*2+1, md+1, rt); t[v].val = t[v*2].val + t[v*2+1].val;}}
void push(int v, int lf, int md, int rt){if(t[v].mark){
t[v*2].val += t[v].prop * (md-lf+1); t[v*2+1].val += t[v].prop * (rt-md); t[v*2].prop += t[v].prop; t[v*2+1].prop += t[v].prop;
t[v*2].mark = t[v*2+1].mark = true; t[v].mark  = t[v].prop = 0;}}
void update(int v, int lf, int rt, int l, int r, int newVal){ if(l > r)return; if(lf == l && r == rt){
t[v].val += (ll)newVal * (ll)(rt-lf+1);t[v].prop += (ll)newVal; t[v].mark = true;}
else{ int md = (lf+rt) / 2; push(v, lf, md, rt); update(v*2, lf, md, l, min(r, md), newVal); update(v*2+1, md+1, rt, max(l, md+1), r, newVal);
t[v].val = t[v*2].val + t[v*2+1].val;}}
ll sum(int v, int lf, int rt, int l, int r){if(l > r)return 0;if(lf == l && r == rt){return t[v].val;}
else{int md = (lf+rt) / 2;push(v, lf, md, rt);ll p1 = sum(v*2, lf, md, l, min(md, r));ll p2 = sum(v*2+1, md+1, rt, max(l, md+1), r);return p1+p2;}}
void Clear(){loop(i, SZ(t))t[i].val = 0, t[i].prop = 0, t[i].mark = false;}
/*---------------------Mobius Function-----------------------------*//*
vi(int) mobius(int fSize){
int mobi[fSize+2];bool pr[fSize+2];
loop(i, fSize)mobi[i] = 1, pr[i] = false; REP(i, 2, fSize){if(!pr[i]){mobi[i] *= -1;
for(int j = i+i; j < fSize; j += i){pr[j] = 1;mobi[j] *= (j%(i*i) ? -1:0);}}}
vi(int)v(mobi, mobi+fSize);return v;}
/*-----------------------------IO-----------------------------------------*/
void fileIO(){
    #ifndef ONLINE_JUDGE
        Read("D://Input.txt"); Write("D://Output.txt");
    #else
        Read("immetric.in"); Write("immetric.out");
    #endif
}
/*-----------------------------------------------------------------------*/


int main()
{
    CIN;
    fileIO();  int start_s = clock();



    int end_s=clock();
    printf("\nTime :: %.2lf\n", (double)(end_s-start_s)/CLOCKS_PER_SEC);
    return 0;
}
