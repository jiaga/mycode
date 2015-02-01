/*
 ***************************************************************
 * File Name:    base.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年01月31日 星期六 18时31分57秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define INIT_TYPE_RAND 0
#define INIT_TYPE_WORST_CASE 1

int printf_arr(int *arr, int start, int end)
{
        int i;

        for (i = start; i <= end; i++)
                printf("%d ", arr[i]);
        putchar('\n');
}

void init_data(int* arr, int n, int init_type)
{
        int i = 0;
        int num = n;

        if (init_type == INIT_TYPE_RAND) {                /* 用随机数据初始化 */
                srand(time(0));
                while (i < n)
                        arr[i++] = rand() % n;
        } else if (init_type == INIT_TYPE_WORST_CASE) {   /* 用逆序初始化     */

                while (i < n)
                        arr[i++] = num--;
        } else {
                /* 无变化 */
        }
}

