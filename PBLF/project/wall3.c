#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define MaxN 100
time_t start,end;
int	N, n, ans;
int	a[MaxN + 1][MaxN + 1], Lx[MaxN + 1], Ly[MaxN + 1], matchY[MaxN + 1];
bool	usedX[MaxN + 1], usedY[MaxN + 1];
bool path( int r )//�ж��Ƿ�������· 
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


bool work()//����KM�㷨�����ƥ�䣬����� 
{
	int i, j, k, res = 0;
	for ( i = 0; i < n; ++i )
	{
		Lx[i] = -2147483647;
		for ( j = 0; j < n; ++j )
			if ( a[i][j] > Lx[i] )
				Lx[i] = a[i][j];
	}
	memset( Ly, 0, sizeof(Ly) );//��ʼ������Lx,Ly��ʹ�����㶥��֮�ʹ��ڵ��ڱ�Ȩ 
	memset( matchY, -1, sizeof(matchY) );
	for ( i = 0; i < n; ++i )
		for (;; )//Ѱ������· 
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
					Ly[j] += delta;//�任�����������ͼ�еı��� 
		}
	for ( i = 0; i < n; ++i )
		if ( matchY[i] >= 0 )
			res += a[matchY[i]][i]; //��� 
	if ( res > ans )
	{
		ans = res; return(true);//�Ƚϣ������ѽ� 
	}else return(false);
}


int dis( int x, int y )//�������ľ��� 
{
	if ( x * y >= 0 )
		x += y;
	else x -= y;
	if ( x > 0 )
		return(x);
	else return(-x);
}


int main()
{
	printf( "��ӭ����zcw�ĳ�����Ϸ\n��Ϸ����:�ƶ�����ڷŵ�n��/��ʹ����n*n�ķ������γ�һ�����Ե������˵�ֱ�߳��ǡ�����������ƶ�/�Ĳ���֮�͵���Сֵ��\n" );
	int score[3]={0},xuan=0,cishu=2;
	float ze,guanka;
	done:
	printf( "1.ѡ��ؿ�\n2.�鿴��ʷ����\n3.�˳���Ϸ\n" ); 
	scanf( "%f", &ze );
	
		if (ze==1){
		printf("�ܹ����أ����Ѵ�ͨ%d�أ����������ѡ����ǰ%d�ء�\n���������ѡ��1��2��3��\n",xuan,xuan==3?3:xuan+1);
	           scanf("\n%f",&guanka);
			    while(guanka>(xuan==3?3:xuan+1)||guanka<=0||guanka!=(int)guanka){printf("����Ƿ������������롣\n");scanf("\n%f",&guanka);}
	           N=guanka*2+1;}
	    else if (ze==2){printf("�ܷ�\t��һ�ط���\t�ڶ��ط���\t�����ط���\n%d \t%d       \t%d       \t%d\n",score[0]+score[1]+score[2],score[0],score[1],score[2]); 
			 getchar();goto done;}
		else if (ze==3){return;} 
		else {
		printf("�Ƿ����룬�����䡣\n");goto done;} 
 	            
		n = N;
		int	X, Y, x, y, i, j, k, s, wei;
		bool	pan;
		char	r[N][N], xian[N][N];
		for ( X = 0; X < N; X++ )
			for ( Y = 0; Y < N; Y++ )
			{
				xian[X][Y]	= '*';
				r[X][Y]		= '*';
			}//��ʼ������ 

		int	A, B;
		char	m;
		int h;
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
		}//�������n��'/' 


		for ( x = 0; x < N; x++ )//��ʾ 
		{
			for ( y = 0; y < N; y++ )
			{
				printf( "%c ", r[x][y] );
				if ( y == N - 1 )
					printf( "\n" );
			}
		}
		ans = -(n * n + n);

		for ( i = 1; i <= n; i++ )//����4��forѭ��������������м�����Ƚ� 
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
		}//���ɴ𰸷��� 
		retry:
		printf( "������Ĵ�" );start =time(NULL);
		scanf( "%d", &s );end =time(NULL); 
		if ( s == -ans )
		{	printf( "                              _       _ \n\
                             (_)     | |\n\
 _   _  ___  _   _  __      ___ _ __ | |\n\
| | | |/ _ \\| | | | \\ \\ /\\ / / | '_ \\| |\n\
| |_| | (_) | |_| |  \\ V  V /| | | | |_|\n\
  \__, |\\___/ \\__,_|   \\_/\\_/ |_|_| |_(_)\n\
  __/ |                                 \n\
 |___/   \n" );                               
         score[((int)guanka)-1]+=(n+cishu+1000/difftime(end,start)); 
         xuan=guanka;
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
 while(cishu>0){printf("�ܹ�3�δ�����ᣬ����%d�λ���\n",cishu);cishu--;goto retry;}
 printf("�����������еĴ�����ᣬ�Ƿ�鿴��(y/n)\n");
			scanf( "\n%c", &m );
		}
		if ( m == 'y' )
		{
			printf( "��ȷ����%d\n", -ans );
			for ( x = 0; x < N; x++ )
			{
				for ( y = 0; y < N; y++ )
				{
					printf( "%c ", xian[x][y] );
					if ( y == N - 1 )
						printf( "\n" );
				}//��ʾ�𰸷��� 
			}
		}
		tail:
		printf( "1.������Ϸ\n" );
		printf( "2.��ʾ����\n" );
		printf( "3.�˳���Ϸ\n" );
		printf("���������ѡ��\n");
		scanf( "\n%d", &h );
		if ( h == 1 )
			goto done;
			else if(h==2)
			{
			printf("�ܷ�\t��һ�ط���\t�ڶ��ط���\t�����ط���\n%d \t%d       \t%d       \t%d\n",score[0]+score[1]+score[2],score[0],score[1],score[2]); 
			goto tail;}
			else if(h==3)
			return;
	
}
