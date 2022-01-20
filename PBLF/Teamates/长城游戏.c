#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#define MaxN 100
int N,n,ans;
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
bool work()
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
if(res>ans){
ans=res;return true;
}
else return false;}
int dis(int x,int y)
{
	if(x*y>=0) x+=y;
	else x-=y;
	if(x>0) return x;
	else return -x;
}
int main()
{
printf("游戏规则:移动任意摆放的n个/，使其在n*n的方阵中形成一条可以抵御敌人的长城。请求出所需移动/的步数之和的最小值。\n");
printf("给出你想玩的方阵阶数(小于100)\n");
scanf("%d",&N);
while(1){
n=N;
int X,Y,x,y,i,j,k,s,wei;
bool pan;
char r[N][N],xian[N][N];
for(X=0;X<N;X++)
for(Y=0;Y<N;Y++)
{xian[X][Y]='*';
r[X][Y]='*';}
	
int A,B;
char m,h;
int P[N+1][2];
	srand((unsigned) time(NULL));
for(i=1;i<=N;i++)
	{
	A=rand()%N;
	B=rand()%N;
	while (r[A][B]!='*'){
			A=rand()%N;
	        B=rand()%N;
	}
	r[A][B]='/';
	P[i][0]=A+1;P[i][1]=B+1;
	}
	
	
	for(x=0;x<N;x++)
	{for(y=0;y<N;y++){
		printf("%c ",r[x][y]);
		if (y==N-1) printf("\n");
	}
	}
	ans=-(n*n+n);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
		a[j-1][k-1]=-dis(P[j][0]-i,P[j][1]-k);
		pan=work();
		if(pan==true){wei=i;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
		a[j-1][k-1]=-dis(P[j][0]-k,P[j][1]-i);
		pan=work();
		if(pan==true){wei=-i;
		}
}
for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
		a[j-1][k-1]=-dis(P[j][0]-k,P[j][1]-k);
		pan=work();
		if(pan==true){wei=0;
		}
		for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
		a[j-1][k-1]=-dis(P[j][0]-k,P[j][1]-(n-k+1));
		pan=work();
		if(pan==true){wei=101;
		}
		if(wei>=1&&wei<=n){for(i=0;i<N;i++) xian[wei-1][i]='/';
		}
		if((-wei)>=1&&(-wei)<=n){for(i=0;i<N;i++) xian[i][-wei-1]='/';
		}
		if(wei==0){for(i=0;i<N;i++) xian[i][i]='/';
		}
		if(wei==101){for(i=0;i<N;i++) xian[i][N-i-1]='/';
		}
		printf("输入你的答案");
		scanf("%d",&s);
		if (s==-ans)
		printf("你赢了！\n");
		else 
		{
		printf("你输了，是否查看答案(y/n)\n");
		scanf("\n%c",&m);}
		if(m=='y') 
		{
		printf("正确答案是%d\n",-ans);
		for(x=0;x<N;x++)
	{for(y=0;y<N;y++){
		printf("%c ",xian[x][y]);
		if (y==N-1) printf("\n");
	}
	}
	}
		printf("是否继续游戏？(y/n)\n");
		scanf("\n%c",&h);
		if(h=='n') break;}
		
}
