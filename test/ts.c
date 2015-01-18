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
#include <stdlib.h>
#include "sort.h"

#define LEN 10

void p(int *arr, int len)
{
        int i = 0;

        while (i < len)
                printf(" %d", arr[i++]);
        putchar('\n');
}

void rand_data(int *arr, int len)
{
        int i;
        
        for (i = 0; i < len; i++) {
                arr[i] = rand() % len;
        }
}

int find_max_value(int *arr, int len)
{
        int i, max;

        max = arr[0];
        for (i = 1; i < len; i++) {
                if (max < arr[i])
                        max = arr[i];
        }

        return max;
}

int main(void)
{
        int arr[LEN];
        int i;
        
        puts("counting sort:");
        rand_data(arr, LEN);
        p(arr, LEN);
        cnt_sort(arr, LEN, find_max_value(arr, LEN));
        //counting_sort(arr, LEN, 9);
        p(arr, LEN);

        puts("\nbubble sort:");
        rand_data(arr, LEN);
        p(arr, LEN);
        bubble_sort(arr, LEN);
        p(arr, LEN);

        puts("\ninsertion sort:");
        rand_data(arr, LEN);
        p(arr, LEN);
        insertion_sort(arr, LEN);
        p(arr, LEN);

        puts("\nselect sort:");
        rand_data(arr, LEN);
        p(arr, LEN);
        select_sort(arr, LEN);
        p(arr, LEN);

        puts("\nquicksort:");
        rand_data(arr, LEN);
        p(arr, LEN);
        quicksort(arr, 0, LEN-1);
        p(arr, LEN);

        puts("\nmerge sort:");
        rand_data(arr, LEN);
        p(arr, LEN);
        merge_sort(arr, 0, LEN-1);
        p(arr, LEN);

        puts("\nheapsort:");
        rand_data(arr, LEN);
        p(arr, LEN);
        HeapSort(arr, LEN);
        p(arr, LEN);

        return 0;
}
