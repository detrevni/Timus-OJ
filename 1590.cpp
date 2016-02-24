#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <climits>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <utility>
#include <sstream>
#include <numeric>
#include <functional>
#include <bitset>
#include <deque>

using namespace std;

#if __cplusplus >= 201103
    #include <unordered_map>
    #include <future>
    #include <atomic>
    #include <chrono>
    #include <unordered_set>
    #include <array>
    #include <random>
    #include <mutex>
#endif

# define pii pair<int, int>

# define pb push_back
# define eb emplace_back
# define mp make_pair

# define f first
# define s second

typedef long long ll;
typedef long double ld;

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

struct node{
    node(){}

    int nxt[27];
    int link, len;

    ~node(){}
}st[20002];

int last, sz, d[maxn];

void Init(){
    st[0].link = -1;
    sz = 1;
}

void Add(char x){
    int code = x - 'a';
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p;
    for(p = last; p != -1 && !st[p].nxt[code]; p = st[p].link)
        st[p].nxt[code] = cur;
    if(p == -1){
        st[p].link = 0;
    }
    else{
        int q = st[p].nxt[code];
        if(st[p].len + 1 == st[q].len){
            st[cur].link = q;
        }
        else{
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            for(ll j = 0; j < 26; ++j)
                st[clone].nxt[j] = st[q].nxt[j];
            for(; p != -1 && st[p].nxt[code] == q; p = st[p].link)
                st[p].nxt[code] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void Count(int v){
    d[v] = 1;
    for(char i = 0; i < 26; ++i){
        if(st[v].nxt[i]){
            Count(st[v].nxt[i]);
            d[v] += d[st[v].nxt[i]];
        }
    }
}

char a[maxn];

main(){
    Init();
    gets(a);
    int n = strlen(a);
    for(int i = 0; i < n; ++i)
        Add(a[i]);
    Count(0);
    printf("%d", d[0] - 1);
    return 0;
}
