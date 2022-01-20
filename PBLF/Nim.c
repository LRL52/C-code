#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define n 5
#define m 25
int a[n+5];

void print(){
    printf("现有的%d堆石子数量依次为：\n", n);
    for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
    putchar('\n'); putchar('\n');
}

int checkend(){
    for(int i = 1; i <= n; ++i) if(a[i] > 0) return 0;
    return 1;
}

void NimGame(){
    printf("\n-------------------初始化游戏---------------------\n");
    Sleep(1000);
    printf("请每次输入用空格分隔的2个数x y\n表示将第x堆石子拿走y个\n\n");
    srand((unsigned)time(NULL)); int x = 0, y = 0;
    for(int i = 1; i <= n - 1; ++i) a[i] = rand() * rand() % m + 1, x ^= a[i];
    if(x > 0 && rand() % 5) a[n] = x;
    else a[n] = rand() * rand() % m + 1;
    while(1){
        print();
        if(checkend()){
            puts("You loss the game! ! !");
            return;
        }
        while(1){
            printf("请输入你的操作x y:");
            scanf("%d%d", &x, &y);
            if(x > n || x < 1 || y <= 0 || a[x] < y){
                puts("不合法的操作！！！");
                continue;
            }
            a[x] -= y;
            break;
        }
        print();
        if(checkend()){
            puts("Congratulations, You win!");
            return;
        }
        Sleep(2000); x = 0;
        for(int i = 1; i <= n; ++i) x ^= a[i];
        if(x){
            for(int i = 1; i <= n; ++i)
                if((a[i] ^ x) < a[i]){
                    y = a[i] - (a[i]^x);
                    printf("LRL52决定将第%d堆石子拿走%d颗\n", i, y);
                    a[i] -= y;
                    break;
                }
        } else{
            for(int i = 1; i <= n; ++i)
                if(a[i] > 0){
                    y = rand() * rand() % a[i] + 1;
                    printf("LRL52决定将第%d堆石子拿走%d颗\n", i, y);
                    a[i] -= y;
                    break;
                }
        }
    }
}

int main(){ //下面将是你的游戏入口, 确保return后将taskid更改为合适的值, 1~Gamecnt表示对应关卡, -1表示退出游戏
    system("chcp 936 >nul");
    system("cls"); Sleep(1000);
    printf("╭===================○●○●==================╮\n");
	printf("│  ★ ☆欢迎来到Subtask3: LRL52的博弈☆ ★    │\n");
	printf("╰=======○●○●==============================╯\n");
    printf("游戏规则：你有%d堆石子，每一堆石子的个数不超过%d个\n", n, m);
    printf("你和LRL52每次可从任意一堆石子里取出任意多枚石子扔掉，可以取完，不能不取\n");
    printf("每次只能从一堆里取。最后没石子可取的一方就输了\n");
    int op;
	while(1){
		printf("1.开始游戏\n2.退出游戏\n");
		printf("请输入你的选择:"); 
		scanf("%d", &op); fflush(stdin);
		if(op == 1) NimGame();
		else return 0;
	}
}
