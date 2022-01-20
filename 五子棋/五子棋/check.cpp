int b[10]; //临时存放棋子

const int dx[][] = {
    {-4, -3, -2, -1, 0, 1, 2, 3, 4} //竖列
    { 0,  0,  0,  0, 0, 0, 0, 0, 0} //横排
    {-4, -3, -2, -1, 0, 1, 2, 3, 4} //主对角线
    {-4, -3, -2, -1, 0, 1, 2, 3, 4} //副对角线
}
const int dy[][] = {
    { 0,  0,  0,  0, 0, 0, 0, 0, 0} //竖列
    {-4, -3, -2, -1, 0, 1, 2, 3, 4} //横排
    {-4, -3, -2, -1, 0, 1, 2, 3, 4} //主对角线
    { 4,  3,  2,  1, 0,-1,-2,-3,-4} //副对角线
}

int check(int *a[], int x, int y){ //(x, y)是刚放下的棋子
    for(int i = 0; i < 4; ++i){
        int cnt = 0;
        for(int j = 0; j < 9; ++j){
            int nx = x + dx[i][j], ny = y + dy[i][j];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            b[++cnt] = a[nx][ny];
        }
        int length = 1;
        for(int j = 2; j <= cnt; ++j){
            if(b[j] == b[j - 1]) ++length;
            else length = 1;
            if(length >= 5) return 1; //五子连珠
        }
    }
    return 0;
}