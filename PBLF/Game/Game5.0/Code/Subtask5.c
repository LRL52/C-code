#include "Subtask5.h" //引入你的头文件
#include "diynode.h"  //引入自定义结构体类型,
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define MaxN 100
extern node Data[]; //共享游戏数据Data 
extern int id, taskid; //共享id, taskid, id为当前用户对应的数字序号, 用作Data[]下标, taskid表示当前正在进行或即将进入的关卡, 你很可能会用到 
//你可以在下面写函数，定义变量等等

static time_t start,end;
static int	N, n, ans;
static int	a[MaxN + 1][MaxN + 1], Lx[MaxN + 1], Ly[MaxN + 1], matchY[MaxN + 1];
static bool	usedX[MaxN + 1], usedY[MaxN + 1];
static bool path( int r )//判断是否有增广路 
{
	int i;
	usedX[r] = true;
	for ( i = 0; i < n; ++i )
		if ( Lx[r] + Ly[i] == a[r][i] )
			if ( !usedY[i] )
			{
				usedY[i] = true;
				if ( matchY[i] < 0 || path( matchY[i] ) )
				{
					matchY[i] = r; return(true);
				}
			}
	return(false);
}


static bool work()//利用KM算法求最佳匹配，并标记 
{
	int i, j, k, res = 0;
	for ( i = 0; i < n; ++i )
	{
		Lx[i] = -2147483647;
		for ( j = 0; j < n; ++j )
			if ( a[i][j] > Lx[i] )
				Lx[i] = a[i][j];
	}
	memset( Ly, 0, sizeof(Ly) );//初始化顶标Lx,Ly，使其满足顶标之和大于等于边权 
	memset( matchY, -1, sizeof(matchY) );
	for ( i = 0; i < n; ++i )
		for (;; )//寻找增广路 
		{
			memset( usedX, false, sizeof(usedX) );
			memset( usedY, false, sizeof(usedY) );
			if ( path( i ) )
				break;
			int delta = 2147483647, v;
			for ( j = 0; j < n; ++j )
				if ( usedX[j] )
					for ( k = 0; k < n; ++k )
						if ( !usedY[k] )
						{
							v = Lx[j] + Ly[k] - a[j][k];
							if ( v < delta )
								delta = v;
						}
			for ( j = 0; j < n; ++j )
				if ( usedX[j] )
					Lx[j] -= delta;
			for ( j = 0; j < n; ++j )
				if ( usedY[j] )
					Ly[j] += delta;//变换，增加相等子图中的边数 
		}
	for ( i = 0; i < n; ++i )
		if ( matchY[i] >= 0 )
			res += a[matchY[i]][i]; //求和 
	if ( res > ans )
	{
		ans = res; return(true);//比较，标记最佳解 
	}else return(false);
}


static int dis( int x, int y )//求两点间的距离 
{
	if ( x * y >= 0 )
		x += y;
	else x -= y;
	if ( x > 0 )
		return(x);
	else return(-x);
}

#define score(x) Data[id].data[5][x+3]
#define xuan Data[id].data[5][2]
#define MaxPoints Data[id].data[5][1]

static void print(){
	system("cls"); printf("当前关卡：长城游戏[关卡5]   当前用户: %s\n\n", Data[id].username);  
	printf("\t\t\t\t     Username   名次   总分   子关卡1   子关卡2   子关卡3  \n");
	ShowRank(5);
	system("pause");
}

void Subtask5(){ //下面将是你的游戏入口, 确保return后将taskid更改为合适的值, 1~Gamecnt表示对应关卡, -1表示退出游戏
    Data[id].data[5][0] = 5;	
		printf( "╭===================○●○●==================╮\n\ 
│  ★ ☆欢迎来到Subtask5: 长城游戏☆ ★       │\n\
╰=======○●○●==============================╯\n游戏规则:移动任意摆放的n个/，使其在n*n的方阵中形成一条可以抵御敌人的直线长城。请求出所需移动/的步数之和的最小值。\n" );
	int sas=0,sa=0,ssa,/*score[3]={0},xuan=0,*/cishu=2;
	float ze,guanka;
	char str[100]={'\0'},strr[100]={'\0'},strrr[100]={'\0'};
	done:
		fflush(stdin);
	printf( "1.选择关卡\n2.查看历史分数\n3.退出游戏\n" ); 
	for(sa=0;;){scanf("%c",&str[sa]);
	        if(str[sa]=='\n') break;
	        sa++;
	}
	ze=(str[0]-'0');
	if (str[1]!='\n'){
		printf("非法输入，请重输。\n");goto done;
	}
		if (ze==1){
			tryagain:
		printf("总共三关，你已打通%d关，所以你可以选择玩前%d关。\n请输入你的选择（1、2、3）\n",xuan,xuan==3?3:xuan+1);
	           for(sas=0;;){scanf("%c",&strr[sas]);
	        if(strr[sas]=='\n') break;
	        sas++;
	}
	guanka=(strr[0]-'0');
	if (strr[1]!='\n'){
		printf("非法输入，请重新输入。\n");goto tryagain;
	}
	if(guanka>(xuan==3?3:xuan+1)||guanka<=0){
		printf("输入非法，请重新输入。\n");goto tryagain; 
	}
	           N=guanka*2+1;}
	    else if (ze==2){
		//printf("总分\t第一关分数\t第二关分数\t第三关分数\n%d \t%d       \t%d       \t%d\n",score(0)+score(1)+score(2),score(0),score(1),score(2)); 
		print(); 
			 goto done;}
		else if (ze==3){return;} 
		else {
		printf("非法输入，请重输。\n");goto done;} 
 	            
		n = N;
		int	X, Y, x, y, i, j, k, s, wei;
		bool	pan;
		char	r[N][N], xian[N][N];
		for ( X = 0; X < N; X++ )
			for ( Y = 0; Y < N; Y++ )
			{
				xian[X][Y]	= '*';
				r[X][Y]		= '*';
			}//初始化数组 

		int	A, B;
		char	m;
		int h=0;
		int	P[N + 1][2];
		srand( (unsigned) time( NULL ) );
		for ( i = 1; i <= N; i++ )
		{
			A	= rand() % N;
			B	= rand() % N;
			while ( r[A][B] != '*' )
			{
				A	= rand() % N;
				B	= rand() % N;
			}
			r[A][B] = '/';
			P[i][0] = A + 1; P[i][1] = B + 1;
		}//随机生成n个'/' 


		for ( x = 0; x < N; x++ )//显示 
		{
			for ( y = 0; y < N; y++ )
			{
				printf( "%c ", r[x][y] );
				if ( y == N - 1 )
					printf( "\n" );
			}
		}
		ans = -(n * n + n);

		for ( i = 1; i <= n; i++ )//利用4个for循环对四种情况进行计算与比较 
		{
			for ( j = 1; j <= n; j++ )
				for ( k = 1; k <= n; k++ )
					a[j - 1][k - 1] = -dis( P[j][0] - i, P[j][1] - k );
			pan = work();
			if ( pan == true )
			{
				wei = i;
			}
		}
		for ( i = 1; i <= n; i++ )
		{
			for ( j = 1; j <= n; j++ )
				for ( k = 1; k <= n; k++ )
					a[j - 1][k - 1] = -dis( P[j][0] - k, P[j][1] - i );
			pan = work();
			if ( pan == true )
			{
				wei = -i;
			}
		}
		for ( j = 1; j <= n; j++ )
			for ( k = 1; k <= n; k++ )
				a[j - 1][k - 1] = -dis( P[j][0] - k, P[j][1] - k );
		pan = work();
		if ( pan == true )
		{
			wei = 0;
		}
		for ( j = 1; j <= n; j++ )
			for ( k = 1; k <= n; k++ )
				a[j - 1][k - 1] = -dis( P[j][0] - k, P[j][1] - (n - k + 1) );
		pan = work();
		if ( pan == true )
		{
			wei = 101;
		}
		if ( wei >= 1 && wei <= n )
		{
			for ( i = 0; i < N; i++ )
				xian[wei - 1][i] = '/';
		}
		if ( (-wei) >= 1 && (-wei) <= n )
		{
			for ( i = 0; i < N; i++ )
				xian[i][-wei - 1] = '/';
		}
		if ( wei == 0 )
		{
			for ( i = 0; i < N; i++ )
				xian[i][i] = '/';
		}
		if ( wei == 101 )
		{
			for ( i = 0; i < N; i++ )
				xian[i][N - i - 1] = '/';
		}//生成答案方阵 
		start =time(NULL);
		retry:
		printf( "输入你的答案" );
		for(ssa=0;;){scanf("%c",&strrr[ssa]);
	        if(strrr[ssa]=='\n') break;
	        ssa++;
	}
	s=(strrr[0]-'0');
	if (strrr[1]!='\n'){
		printf("非法输入，请重输。\n");goto retry;
	} 
		if ( s == -ans )
		{	printf( "                              _       _ \n\
                             (_)     | |\n\
 _   _  ___  _   _  __      ___ _ __ | |\n\
| | | |/ _ \\| | | | \\ \\ /\\ / / | '_ \\| |\n\
| |_| | (_) | |_| |  \\ V  V /| | | | |_|\n\
  \__, |\\___/ \\__,_|   \\_/\\_/ |_|_| |_(_)\n\
  __/ |                                 \n\
 |___/   \n" );   end =time(NULL);
        printf("用时%d秒\n",(int)difftime(end,start)) ;                           
         if(score(((int)guanka)-1)<((n+cishu)*10+1000/(int)difftime(end,start))) 
		 score(((int)guanka)-1)=((n+cishu)*10+1000/(int)difftime(end,start)); 
        if(xuan<(int)guanka) xuan=(int)guanka;
        printf("本局得分：%d\n",((n+cishu)*10+1000/(int)difftime(end,start))) ;
        Data[id].taskid = Data[id].taskid > 5 ? Data[id].taskid : 5; //更新用户的最高关卡记录
        MaxPoints = Max(MaxPoints, Data[id].data[5][3] + Data[id].data[5][4] + Data[id].data[5][5]);
		 } 
		else{
			printf( "                     _ \n\                
                    | |                 \n\
 _   _  ___  _   _  | | ___  ___  ___   \n\
| | | |/ _ \\| | | | | |/ _ \\/ __|/ _ \\  \n\
| |_| | (_) | |_| | | | (_) \\__ \\  __/_ \n\
 \\__, |\\___/ \\__,_| |_|\\___/|___/\\___(_)\n\
  __/ |  \n\                               
 |___/ \n" );
 while(cishu>0){printf("总共3次答题机会，还有%d次机会\n",cishu);cishu--;goto retry;}
 printf("你已用完所有的答题机会，是否查看答案(y/n)\n");
			scanf( "\n%c", &m );
		}
		if ( m == 'y' )
		{
			printf( "正确答案是%d\n", -ans );
			for ( x = 0; x < N; x++ )
			{
				for ( y = 0; y < N; y++ )
				{
					printf( "%c ", xian[x][y] );
					if ( y == N - 1 )
						printf( "\n" );
				}//显示答案方阵 
			}
		}
		tail:
			fflush(stdin);
		printf( "（1.x）继续游戏\n" );
		printf( "（2.x）显示分数\n" );
		printf( "（大于等于3或字母或负数） 退出游戏\n" );
		printf("请输入你的选择\n");
		scanf( "\n%d", &h );
		if ( h == 1 )
			goto done;
			else if(h==2)
			{
			//printf("总分\t第一关分数\t第二关分数\t第三关分数\n%d \t%d       \t%d       \t%d\n",score(0)+score(1)+score(2),score(0),score(1),score(2)); 
			print(); 
			goto tail;}
			else 
			return;
	Switchtask(); //切换关卡, 可在退出时调用
}

