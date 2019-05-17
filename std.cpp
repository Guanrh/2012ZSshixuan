#include<bits/stdc++.h>
#define open(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define N 2000010
#define R 60
using namespace std;

int M,K,L,n,i,j,t,ans;
int ch[N][26],tn=1,root,got[N];
int g[N],f[N];
char s[R];

void dfs(int x)
{
	g[x] = (f[x]=-1) + 1;
	for(int i=0;i<26;i++)
		if(ch[x][i])
		{
			int v=0;
			dfs(v=ch[x][i]);
			if(g[v] > g[x]) 
			{
				g[x] = g[v];
				f[x] = v;
			}
		}
	if(got[x])++g[x];
	return ;
}


void walk(int x)
{
	if(got[x])++t;
	g[x]=0;got[x]=0;
	int v=f[x]; 
	if(v==-1)return ;
	walk(v);
	
	for(int i=0;i<26;i++)
		if(ch[x][i])
		{
			int u = ch[x][i];
			if(g[u] > g[x]) 
			{
				g[x] = g[u];
				f[x] = u;
			}
			
		}
	return ;
}
int main()
{
	scanf("%d%d%d%d\n",&M,&K,&L,&n);
	for(i=1;i<=M;i++)
	{
		scanf("%s\n",s+1);
		int now=1,len = strlen(s+1);
		for(j=1;j<=len;j++)
		{
			if(!ch[now][s[j]-'A']) ch[now][s[j]-'A'] = ++tn;
			now  = ch[now][s[j]-'A'];
		}
		got[now] = 1;
	}
	
	dfs(1); // f,g
	
	for(i=1;i<=n;i++)
	{
		t=0;
		walk(1);
		ans+=t;
	}
	
	printf("%d",ans);
	
	return 0;
}