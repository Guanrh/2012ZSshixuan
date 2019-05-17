#include<cstdio>
#include <algorithm>

using namespace std;

long long n,row,col,p[510000],l,r,mid;

int check(int mid)
{
	int x=1;
	for (int i=1;i<=row;i++)
	{
		while (p[x]-p[x+col-1]>mid) x++;
		if ((x+=col)>n+1) return 0;
	}
	return 1;
}

int cmp(int x,int y){return x>y;}

int main()
{
	scanf("%d%d%d",&n,&row,&col);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	sort(p+1,p+1+n,cmp);
	l=0;
	r=p[1]-p[n];
	while (l<r)
	{
		mid=(l+r)/2;
		if (check(mid))
			r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}