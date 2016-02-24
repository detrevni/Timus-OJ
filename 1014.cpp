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

# define int long long

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

int n;
int cnt[10];

main(){
    scanf("%lld", &n);
    if(n <= 1){
        if(!n)
            return printf("10"), 0;
        printf("%lld", n);
        return 0;
    }
    for(int i = 9; i >= 2; --i){
        while(n % i == 0)
            n /= i, ++cnt[i];
    }
    if(n > 9){
        printf("-1");
        return 0;
    }
    while(cnt[2] >= 2) --cnt[2], ++cnt[4];
    while(cnt[3] >= 2) --cnt[3], ++cnt[6];
    while(cnt[4] >= 2) --cnt[4], ++cnt[8];
    for(int i = 1; i <= 9; ++i){
        while(cnt[i]--)
            printf("%lld", i);
    }
    return 0;
}
