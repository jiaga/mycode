/*
 ***************************************************************
 * File Name:    test_hs.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年01月31日 星期六 18时26分48秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"
#include "base.h"

#define LEN 10

int main(void)
{
        int arr[LEN];
        int i;

        srand(time(0));
        for (i = 0; i < LEN; i++) {
                arr[i] = rand() % LEN;
        }

        printf_arr(arr, 0, LEN-1);
        heap_sort(arr, LEN);
        printf_arr(arr, 0, LEN-1);

        return 0;
}
