#include<bits/stdc++.h>

using namespace std;

const int maxn = 110;

int times;
int dfn[maxn], low[maxn];
bool cut[maxn];
vector<int> G[maxn];

void articulation(int u, int fa){
    dfn[u] = low[u] = ++times;
    int childs = 0;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!dfn[v]){
            childs++;
            articulation(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v]>=dfn[u] && fa>0)
                cut[u] = true;
        }
        else if(fa != v)
            low[u]=min(low[u], dfn[v]);
    }
    if(fa < 0)
        cut[u] = (childs>=2) ? true : false;
}

int main(){
    int n;
    while(~scanf("%d",&n) && n){
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(cut,0,sizeof(cut));
        times = 0;
        int u,v;
        for(int i = 1; i <= n; ++i)
            G[i].clear();
        while(scanf("%d",&u) && u){
            while(getchar()!='\n'){
                scanf("%d",&v);
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        articulation(1,-1);
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            if(cut[i])
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
