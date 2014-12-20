/*
 ***************************************************************
 * File Name:    insertion_sort.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014/7/12 1:25:22
 ***************************************************************
 */

#include <stdio.h>

#define LEN 9

int find_ele_index(int *arr, int len, int value)
{
        int i;

        for (i = 0; i < len; i++) {
                if (value == arr[i])
                        return i;
        }

        return -1;
}

void add_n_bit_arr(int *a, int *b, int *c, int len)
{
        int i;
        int cf  = 0;
        int sum = 0;

        for (i = len-1; i >= 0; i--) {
                sum = a[i] + b[i] + cf;
                c[i+1] = sum % 2;
                if (sum > 1)
                        cf = 1;
                else
                        cf = 0;
        }
        c[i+1] = cf;
}

void insertion_sort(int *arr, int len)
{
        int i;
        int j;
        int key;

        for (j = 1; j <len; j++) {
                key = arr[j];
                i = j - 1;
                while (i >= 0 && arr[i] < key) {
                        arr[i+1] = arr[i];
                        --i;
                }
                arr[i+1] = key;
        }
}

void print_int_arr(int *arr, int len)
{
        int i = 0;

        while (i < len)
                printf("%d ", arr[i++]);
        putchar('\n');
}

void print_int_arr2(int *arr, int len)
{
        int i = 0;

        printf("  ");
        while (i < len)
                printf("%d ", arr[i++]);
        putchar('\n');
}

int main(void)
{
        int arr[LEN]            = {7, 8, 1, 6, 9, 3, 2, 5, 4};
        int a[LEN]              = {1, 0, 1, 1, 0, 0, 1, 0, 1};
        int b[LEN]              = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        int c[LEN+1]            = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int i;

        print_int_arr(arr, LEN);
        insertion_sort(arr, LEN);
        print_int_arr(arr, LEN);

        print_int_arr2(a, LEN);
        print_int_arr2(b, LEN);
        add_n_bit_arr(a, b, c, LEN);
        print_int_arr(c, LEN+1);

        return 0;
}
