#include<bits/stdc++.h>
#define N 2000010

using namespace std;

int ch[N][26],got[N],g[N],f[N],ans,tn=1,m,k,n,l,t;
char s[60];

void dfs(int x)
{
	g[x]=(f[x]=-1)+1;
	for (int i=0;i<26;i++)
		 if (ch[x][i])
		 {
		 	int v=0;
		 	dfs(v=ch[x][i]);
		 	if (g[v]>g[x])
		 	{
		 		g[x]=g[v];
		 		f[x]=v;
		 	}
		 }
	g[x]+=(got[x]==1);
	return;
}

void walk(int x)
{
	if(got[x]) ++t;
	g[x]=0;got[x]=0;
	int v=f[x];
	if (v==1) return;
	walk(v);

	for (int i=0;i<26;i++)
		if (ch[x][i])
		{
			int u =ch[x][i];
			if (g[u]>g[x])
			{
				g[x]=g[u];
				f[x]=u;
			}
		}
	return;
}

int main()
{
	scanf("%d%d%d%d\n",&n,&k,&l,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%s\n",s+1);
		int now=1,len = strlen(s+1);
		for(int j=1;j<=len;j++)
		{
			if(!ch[now][s[j]-'A']) ch[now][s[j]-'A'] = ++tn;
			now  = ch[now][s[j]-'A'];
		}
		got[now] = 1;
	}
	
	dfs(1); 

	for (int i=0;i<=n;i++)
	{
		t=0;
		walk(1);
		ans+=t;
	}

	printf("%d\n",ans);

	return 0;
}