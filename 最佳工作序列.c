#include <stdlib.h>
#include <stdio.h>

#define N 4
int time = 0, worth = 0;
int maxworth = 0;

void doing(int (*work)[3])
{
    int i;
 
    for (i = 0; i < N; i++)
    {
        
        worth += work[i][2];
        time += work[i][0];
        if (time < work[i][1])
        {
            doing(work);
        }
        else {
            if (maxworth < worth)
            {
                maxworth = worth;
            }
        }
       
        worth -= work[i][2];
        time -= work[i][0];
    }
}



void main()
{
    int work[N][3] =          //原数组
    {
        3, 8, 3,  // 1 
        4, 10, 2, // 2
        2, 4, 3,  // 3
        1, 2, 6   // 4
    };
    int sortwork[N][3] =
    {
        3, 8, 3,  // 1 
        4, 10, 2, // 2
        2, 4, 3,  // 3
        1, 2, 6   // 4
    };
    int i, j, k, temp;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (sortwork[j][1] > sortwork[j + 1][1])
            {
                for (k = 0; k < 3; k++)
                {
                    temp = sortwork[j][k];
                    sortwork[j][k] = sortwork[j + 1][k];
                    sortwork[j + 1][k] = temp;
                }
            }
        }
    }

    doing(sortwork);
    printf("最高总价值为：%d\n", maxworth);

    system("pause");
}

