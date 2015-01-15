/*
 ***************************************************************
 * File Name:    ts.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年01月16日 星期五 01时29分30秒
 ***************************************************************
 */

#include <stdio.h>
#include "sort.h"

void p(int *arr, int len)
{
        int i = 0;

        while (i < len)
                printf(" %d", arr[i++]);
        putchar('\n');
}

int main(void)
{
        int arr[10] = {3, 6, 7, 5, 2, 9, 8, 1, 4, 0};
        int i;
        
        p(arr, 10);
        cnt_sort(arr, 10, 9);
        //counting_sort(arr, 10, 9);
        p(arr, 10);

        return 0;
}
