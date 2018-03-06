#include<bits/stdc++.h>

#define sz 101

using namespace std;

struct edge
{
    int f,t,c;
    edge(int a,int b,int co)
    {
        f=a;
        t=b;
        c=co;
    }
};
vector<edge>vec;
vector<int>mat[sz];
int cost[sz][sz];
int n,e;
int comp(edge a,edge b)
{
    return a.c<b.c;
}
int par[sz];
int set_find(int a)
{
    if(a==par[a])                                           //mst
        return a;
    return(par[a]=set_find(par[a]));
}
void link(int x,int y)
{
    if(x<y)
        par[y]=x;
    else par[x]=y;
}
void mst(void)
{
    int i,x,y;
    sort(vec.begin(),vec.end(),comp);
    for(i=0; i<e; i++)
    {
        x=set_find(vec[i].f);
        y=set_find(vec[i].t);
        if(x!=y)
        {
            link(x,y);
            mat[x].push_back(y);
            mat[y].push_back(x);
            cost[x][y]=cost[y][x]=vec[i].c;
        }
    }
}
void ini(void)
{
    for(int i=1; i<=n; i++)
    {
        par[i]=i;
        mat[i].clear();
    }
    vec.clear();
}

int par_bfs[sz];
void bfs_path(int start,int end)
{
    queue<int>Q;
    bool visited[sz];
    memset(visited,0,sizeof visited);
    Q.push(start);
    visited[start]=1;
    while(!Q.empty())
    {

        int f=Q.front();
        Q.pop();
        //   printf("%d ",f);
        for(int i=0; i<mat[f].size(); i++)
        {
            int v=mat[f][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                par_bfs[v]=f;
                Q.push(v);
                if(v==end)
                {
                    // printf("\n");
                    return;
                }
            }

        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t,i,j,f,c,ans,cs=1,q;
    bool chk=true;

    while(scanf("%d %d %d",&n,&e,&q)==3)
    {
        if(n==0 && e==0 && q==0)
            break;
        ini();
        for(j=0; j<e; j++)
        {
            scanf("%d %d %d",&f,&t,&c);
            vec.push_back(edge(f,t,c));
        }
        mst();
        if(chk==false)
            printf("\n");
        chk=false;
        printf("Case #%d\n",cs++);
        while(q--)
        {
            scanf("%d %d",&f,&t);
            // printf("par %d %d\n",par[f],par[t]);
            if(set_find(f)!=set_find(t))
            {
                printf("no path\n");
            }
            else
            {
                bfs_path(f,t);
                int ans=0;
                while(f!=t)
                {
                    ans=max(ans,cost[t][par_bfs[t]]);
                    //  printf(" t =  %d  ans = %d\n",f,ans);
                    t=par_bfs[t];
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
