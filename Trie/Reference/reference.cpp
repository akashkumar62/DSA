// Akash Kumar


#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

void solve();
void solvg();
void solve_mul();

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vl> vvl;

#define make_it_fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rept(i, a, n) for (ll i = (a); i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define sorr(x) sort(x.rbegin(),x.rend()) // this is in order to do sorting in descending order
#define lb lower_bound
#define ub upper_bound
#define pb emplace_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462
#define mset multiset<ll> // it contains multiple instances of the same value in ascending order
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repd(i,a,b) for(ll i=b-1;i>=a;i--)
#define nn endl
#define setbits(n) __builtin_popcount(n)

vl seive(1000009,-1);

string yup="YES";
string nope="NO";
ll fibonacci(ll n){ll a=0;ll b=1;ll c;if(n==0 || n==1){return n;}for(ll i=2;i<n+1;i++){c=a+b;a=b;b=c;}return c;}
void rev(vl &arr,ll n){rep(i,0,n){cin>>arr[i];}return;}
void prv(vl arr){rep(i,0,arr.size()){cout<<arr[i]<<" ";}cout<<nn;return;}

// Now when we need to find the prime numbers in the range [l.....r]
// where r and l can be really large like 10^12 but still r-l+1<=10^6 or 10^7
// then we can use segmented seive
// Here if ans[i]==-1 means l+i it is prime actually
// else it will give the lowest factor>1 that divides i actually

vl segmented_seive(ll l,ll r){
    ll n=r;
    ll num=(ll)ceil(sqrtl(n));
    vl is_prime(num,-1);
    vl primes;
    vl ans(r-l+1,-1);
    for(ll i=2;i<=num;i++){
        if(is_prime[i]==-1){
            primes.pb(i);
            for(ll j=i*i;j<num;j=j+i){
                if(is_prime[j]==-1){
                    is_prime[j]=i;
                }
            }
        }
    }
    for(ll i=0;i<primes.size();i++){
        for(ll j=max(primes[i]*primes[i],(((l-1)/primes[i])*primes[i])+primes[i]);j<=r;j+=primes[i]){
            if(ans[j-l]==-1){
                ans[j-l]=primes[i];
            }
        }
    }
    if (l == 1){
        is_prime[0] = 1;
    }
    return ans;
}

bool prime(ll n){rep(i,2,(ll)floor(sqrtl(n))+1){if(n%i==0){return false;}}return true;}

// if seive[i]==-1 it means it is prime else composite and seive[i] will give 
// the lowest factor>1 that divides l+i actually.

void seiv(){
    seive[0]=0;
    seive[1]=1;
    for(ll i=2;i*i<=1000008;i++){
        if(seive[i]==-1){
            seive[i]=i;
            for(ll j=i*i;j<=1000008;j=j+i){
                if(seive[j]==-1){
                    seive[j]=i;
                }
            }
        }
    }
}

// Always return a positive integer
ll gcd(ll a,ll b){a=abs(a);b=abs(b);ll k=1;while(a%2==0 && b%2==0){k=2*k;a=a/2;b=b/2;}while(a%2==0){a=a/2;}while(b%2==0){b=b/2;}while(b!=0){a=a%b;swap(a,b);}return k*a;}

// This implementation of extended Euclidean algorithm produces correct results for negative integers as well.
ll gcd(ll a,ll b,ll &x,ll &y){
    a=abs(a);
    b=abs(b);
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1,y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Always return a positive integer
ll lcm(ll a,ll b){a=abs(a);b=abs(b);return (a/gcd(a, b))*b;}

// Binary Exponentiation
ll binpow(ll a,ll n){ll res=1;while(n!=0){if(n%2==0){a=a*a;n=n/2;}else{res=res*a;n=n-1;}}return res;}

// Modulo Binary Exponentiation
ll binpowmod(ll a,ll n,ll m){ll res=1;while(n!=0){if(n%2==0){a=a*a%m;n=n/2;}else{res=res*a%m;n=n-1;}}return res;}

// if we know that in Modulo Binary Exponentiation the m is going to be prime than even for n>>m we can speed it up
ll binpowmod_prime(ll a,ll n,ll m){ll res=1;while(n!=0){if(n%2==0){a=a*a%m;n=(n/2)%(m-1);}else{res=res*a%m;n=(n-1)%(m-1);}}return res;}

ll add_mod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mul_mod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll sub_mod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

/*
    A) double sqrt(double arg): It returns the square root of a number to type double. 
    B) float sqrtf(float arg): It returns the square root of a number to type float.
    C) long double sqrtl(long double arg): It returns the square root of a number to type long double with more precision. 
    Advised to always use C) as always give correct one as other may halt in case of the big numbers
    cbrt() in built function to give the cube root in float/double
    abs() is used for the absolute value of a number
    swap() function in c++ used to swap value of two elements of the same data type.
    toupper() This function is used for converting a lowercase character to uppercase.
    tolower() This function is used for converting an uppercase character to lowercase.
    ceil() and floor() function
    sort(vect.begin(),vect.end(), greater<int>());
    reverse(vect.begin(), vect.end());
    count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
    find(first_iterator, last_iterator, x) – Returns an iterator to the first occurrence of x in vector and points to last address of vector ((name_of_vector).end()) if element is not present in vector
    
    maximium value long long can take 9, 223, 372, 036, 854, 775, 807
    2^63-1
    i.e, length of 19 only
    maximium value long long can take 18, 446, 744, 073, 709, 551, 615
    2^64-1
    i.e, length of 20 only

    lower_bound(v.begin(), v.end(), 6) these are the syntax
    upper_bound(v.begin(), v.end(), 6)

    In multiset to remove all element of a same number use a.erase()
    else to remove 1 lement only use ans.erase(ans.find(*it)) here it is the iterator

    priority_queue<int, vector<int>, greater<int> > gquiz(arr, arr + n);
    Here above is the syntax of the min_heap implementation with the help of the priority queue and here push() and pop() and top() are the main operations
    priority_queue<int> gquiz(arr, arr + n);
    Here above is the syntax of the max_heap implementation with the help of the priority queue and here push() and pop() and top() are the main operations

    Whenever need to do the hashing always use the map which is the stl template of hashing never use the array indexing method.
    map.find() function has complexity 0(logn)
    map.insert function has complexity 0(1)
    __builtin_popcount(n) - we use this function to count the number of 1's (set bits) in the number in binary form
    __builtin_parity(n) - this is boolean function which return true if number of 1's in binary form of n are odd else returns false;
    __builtin_clz(n) - eg: Binary form of 16 is 00000000 00000000 00000000 00010000 therefore will return the number of the leading zeroes in n here answer will be 27
    __builtin_ctz(n) - eg: Binary form of 20 is 00000000 00000000 00000000 00010100 therefore will return the number of the trailing zeroes in n here answer will be 2

    An important info about the lower_bound used in various data structures
    actually if number is present they will return te iterator pointing to that number in the data structure otherwise return the
    next iterator in that data structure so depends whether sorted in ascending or descending order.
    An important info about the upper_bound used in various data structures
    is that it will return the iterator pointing to the next iterator to which the number should be there also depends on the sorting order

    Modulo operations, although we see them as O(1), are a lot slower than simpler operations like addition, subtraction or bitwise operations. So it would be better to avoid those.
    getline(cin,s); used for the string input
    Always in the question related to the graph always access from the global variables
*/

struct dsu{
    vl parent;
    vl size;
    
    dsu(ll n){
        size.resize(n+1);
        parent.resize(n+1);
        rep(i,0,n+1){
            make_set(i);
        }
    }

    void make_set(ll v){
        parent[v]=v;
        size[v]=1;
    }

    ll find_set(ll v){
        if(v==parent[v]){
            return v;
        }
        else{
            return parent[v]=find_set(parent[v]);
        }
    }
    void union_set(ll a,ll b){
        a=find_set(a);
        b=find_set(b);
        if(a==b){
            return;
        }
        else{
            if(size[a]>=size[b]){
                parent[b]=a;
                size[a] += size[b];
            }
            else{
                parent[a]=b;
                size[b] += size[a];
            }
        }
    }
};

struct segtree{
    ll n;
    vl a,tree;
    
    // segtree(vl &a){
    //     this->a = a;
    //     ll k=1;
    //     this->n = a.size();
    //     while(k<n){
    //         k=k*2;
    //     }
    //     k*=2;
    //     this->tree.resize(k);
    //     built(1,0,n-1);
    // }
    
    segtree(ll n){
        ll k=1;
        this->n = n;
        while(k<n){
            k=k*2;
        }
        k*=2;
        tree.assign(k,0);
    }
 
    ll merge_opn(ll x, ll y){
        return x+y;
    }
    
    // void built(ll node, ll l, ll r){
    //     if(l==r){
    //         tree[node]=a[l];
    //         return;
    //     }
    //     built(2*node,l,(l+r)/2);
    //     built(2*node+1,(l+r)/2+1,r);
        
    //     merge(node);
    // }
    
    void merge(ll node){
        tree[node]=merge_opn(tree[2*node+1],tree[2*node+2]);
    }
    
    ll range_query(ll node, ll l, ll r, ll query_l, ll query_r){
        if(r<query_l || l>query_r){
            return 0;
        }
        if(l>=query_l && r<=query_r){
            return tree[node];
        }
        ll mid = (l+r)/2;
        ll left=range_query(2*node+1,l,mid,query_l,query_r);
        ll right=range_query(2*node+2,mid+1,r,query_l,query_r);
        return merge_opn(left,right);
    }
    
    ll range_query(ll query_l, ll query_r){
        return range_query(0,0,n-1,query_l,query_r-1);
    }
    
    void point_update(ll node, ll l, ll r, ll idx, ll val){
        if(r-l==0){
            tree[node]=val;
            return;
        }
        ll mid = (l+r)/2;
        if(idx>mid){
            point_update(2*node+2,mid+1,r,idx,val);
        }
        else{
            point_update(2*node+1,l,mid,idx,val);
        }
        merge(node);
    }
    
    void point_update(ll idx, ll val){
        point_update(0,0,n-1,idx,val);
    }
    
    // void range_update(int node, int l, int r, int query_l, int query_r, int val){
    //     if(l>query_r || r<query_l){    
    //         return;
    //     }
    //     if(l>=query_l && r<=query_r){
    //         tree[node]=val;
    //         return;
    //     }
    //     int mid = (l+r)/2;
        
    //     //if(tree[node]!=-1)
    //     //tree[2*node]=tree[2*node+1]=tree[node];
    //     //tree[node]=-1;
        
    //     range_update(2*node,l,mid,query_l,query_r,val);
    //     range_update(2*node+1,mid+1,r,query_l,query_r,val);
        
    //     merge(node);
    // }
    
    // void range_update(int query_l, int query_r, int val){
    //     range_update(1,0,n-1,query_l,query_r,val);
    // }
    
    // int point_query(int node, int l, int r, int idx){
    //     if(l==r || tree[node]!=-1){
    //         return tree[node];
    //     }
    //     int mid = (l+r)/2;
    //     if(idx>mid){
    //         return point_query(2*node+1,mid+1,r,idx);
    //     }
    //     else{
    //         return point_query(2*node,l,mid,idx);
    //     }
    // }
    
    // int point_query(int idx){
    //     return point_query(1,0,n-1,idx);
    // }
};


bool mycompare(pll p1 ,pll p2){
    if(p1.first<p2.first){return true;}
    else if(p1.first==p2.first){return p1.second<p2.second;}
    else{return false;}
}

void solve_mul(){
    ll test;
    cin>>test;
    rep(i,0,test){
        
    }
}

void solve(){
    string s;
    ll n;
    cin>>n;
    vl arr(n,0);
    rev(arr,n);
}

void solvg(){
    ll n,m;
    cin>>n>>m;
    vl a;
    vvl arr(n,a);
    rep(i,0,m){
        ll x,y;
        cin>>x>>y;
        arr[x-1].pb(y);
        arr[y-1].pb(x);
    }
}

signed main(){
    make_it_fast();
    //seiv();
    solve_mul();
    //solve();
    //solvg();
    return 0;
}