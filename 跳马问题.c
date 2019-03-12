#include<stdio.h>
#include<stdlib.h>
#define M 4
#define N 4
#define x 3
#define y 2

int map[M][N] = {0};
int count = 0; //记录马共跳的步数
int countnum = 0; //用于统计走法种数
int direction[8][2] = { {1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2} };//马可能前进的8个方向

void print_map(); //打印出马跳的路径
void go(int i, int j); //马向(i,j)点跳

void main()
{
    go(x, y);
    printf("共有%ld种路线\n", countnum);
    system("pause");
}

void go(int i, int j)
{
    int m, n;
    count++;
    map[i][j] = count;


    for (int k = 0; k < 8; k++)
    {
        m = i + direction[k][0];
        n = j + direction[k][1];
        if (m >= 0 && m < M && n >= 0 && n < N)
        {
            if (map[m][n] == 0)
            {
                go(m, n);
            }
            else if (map[m][n] == 1&&count>2)
            {
                print_map();
            }

        }
        
    }
    count--;
    map[i][j] = 0;
}


void print_map()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%4d", map[i][j]);
        printf("\n");
    };
    countnum = countnum + 1;
    printf("Count:%d\n\n", countnum);
}


