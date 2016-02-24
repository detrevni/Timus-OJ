# include <bits/stdc++.h>

typedef long long ll;

int n, m;
int a[1001], must[1001][1001];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        must[x][y] = 1;
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        for(int j = i - 1; j >= 1; --j){
            if(must[a[i]][a[j]])
                return printf("NO"), 0;
        }
    }
    printf("YES");
    return 0;
}
