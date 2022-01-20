#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#define MaxN 10
int n,ans,cases;
int a[MaxN+1][MaxN+1],Lx[MaxN+1],Ly[MaxN+1],matchY[MaxN+1];
bool usedX[MaxN+1],usedY[MaxN+1];
bool path(int r)
{int i;
usedX[r]=true;
for(i=0;i<n;++i)
if(Lx[r]+Ly[i]==a[r][i])
if(!usedY[i])
{usedY[i]=true;
if(matchY[i]<0||path(matchY[i])){matchY[i]=r;return true;
}
}return false;
}
void work()
{int i,j,k,res=0;
for (i=0;i<n;++i)
{Lx[i]=-2147483647;
for (j=0;j<n;++j)
if(a[i][j]>Lx[i])
Lx[i]=a[i][j];
}
memset(Ly,0,sizeof(Ly));
memset(matchY,-1,sizeof(matchY));
for (i=0;i<n;++i)
for(;;){memset(usedX,false,sizeof(usedX));
memset(usedY,false,sizeof(usedY));
if(path(i)) break;
int delta=2147483647,v;
for(j=0;j<n;++j)
if(usedX[j])
for (k=0;k<n;++k)
if(!usedY[k])
{v=Lx[j]+Ly[k]-a[j][k];
if (v<delta) delta=v;
}
for(j=0;j<n;++j)
if(usedX[j]) Lx[j]-=delta;
for(j=0;j<n;++j)
if(usedY[j]) Ly[j]+=delta;
}
for(i=0;i<n;++i)
if (matchY[i]>=0) res+=a[matchY[i]][i];
if(res>ans)ans=res;
}
int dis(int x,int y)
{
	if(x*y>=0) x+=y;
	else x-=y;
	if(x>0) return x;
	else return -x;
}
int main()
{
printf("游戏规则:计算调整1的位置使1画断整个方阵所需要的最小步数\n");
while(1){
n=10;
int r[MaxN][MaxN]={0},A[10]={0,1,2,3,4,5,6,7,8,9},B[10]={0,1,2,3,4,5,6,7,8,9},t;
int x,y,z,i,j,k,s;
char m,h;
int P[MaxN+1][2];
	srand((unsigned) time(NULL));
for(z=0;z<10;z++)
	{
	x=rand()%10;
	y=rand()%10;
	t=A[x];
	A[x]=A[y];
	A[y]=t;
	}
	for(z=0;z<10;z++)
	{
	x=rand()%10;
	y=rand()%10;
	t=B[x];
	B[x]=B[y];
	B[y]=t;
	}
	for(z=0;z<10;z++)
	{r[A[z]][B[z]]=1;
	}
	for(x=0;x<10;x++)
	{for(y=0;y<10;y++){
		printf("%d",r[x][y]);
		if (y==9) printf("\n");
	}
	}
	ans=-(n*n+n);
	for(i=1;i<=n;i++){P[i][0]=A[i-1];P[i][1]=B[i-1];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
		a[j-1][k-1]=-dis(P[j][0]-i,P[j][1]-k);
		work();
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
		a[j-1][k-1]=-dis(P[j][0]-k,P[j][1]-i);
		work();
}
for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
		a[j-1][k-1]=-dis(P[j][0]-k,P[j][1]-k);
		work();
		for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
		a[j-1][k-1]=-dis(P[j][0]-k,P[j][1]-(n-k+1));
		work();
		printf("输入你的答案");
		scanf("%d",&s);
		if (s==-ans)
		printf("你赢了！\n");
		else 
		printf("你输了，是否查看答案(y/n)\n");
		scanf("\n%c",&m);
		if(m=='y') 
		printf("正确答案是%d\n",-ans);
		printf("是否继续游戏？(y/n)\n");
		scanf("\n%c",&h);
		if(h=='n') break;}
		
}
