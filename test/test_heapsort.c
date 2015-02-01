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
#include "heap.h"
#include "base.h"

#define LEN 10

int main(void)
{
        int arr[LEN];
        int i;

        init_data(arr, LEN, 0);

        printf_arr(arr, 0, LEN-1);
        heap_sort(arr, LEN);
        printf_arr(arr, 0, LEN-1);

        return 0;
}
