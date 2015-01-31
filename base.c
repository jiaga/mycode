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

int printf_arr(int *arr, int start, int end)
{
        int i;

        for (i = start; i <= end; i++)
                printf("%d ", arr[i]);
        putchar('\n');
}
