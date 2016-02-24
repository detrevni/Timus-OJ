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
typedef unsigned long long ull;

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

struct node{
    node *l, *r;
    int val;

    node(){
        l = r = nullptr;
        val = 0;
    }

    ~node(){}
};

node *root = new node();

int n;
int a[maxn];

void Find(node *&now, int l, int r){
    now -> val = a[l];
    if(l == r) return;
    int id = -1;
    for(int i = l + 1; i <= r; ++i){
        if(a[i] < a[l]){
            id = i;
            break;
        }
    }
    if(id == -1){
        now -> r = new node();
        Find(now -> r, l + 1, r);
    }
    else if(id == l + 1){
        now -> l = new node();
        Find(now -> l, l + 1, r);
    }
    else{
        now -> r = new node();
        now -> l = new node();
        Find(now -> r, l + 1, id - 1);
        Find(now -> l, id, r);
    }
}

void Visit(node *now){
    if(now == nullptr) return;
    Visit(now -> r);
    Visit(now -> l);
    printf("%d\n", now -> val);
}

main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    reverse(a + 1, a + 1 + n);
    Find(root, 1, n);
    Visit(root);
    return 0;
}
