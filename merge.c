/*
 ***************************************************************
 * File Name:    text.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年07月12日 星期六 23时04分37秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 20

void print_int_arr(int *arr, int start, int end);
void merge_sort(int *arr, int p, int r);
void merge(int *arr, int p, int q, int r);

int ct= 0;

int main(void)
{
        int arr[LEN] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

        print_int_arr(arr, 0, LEN-1);
        merge_sort(arr, 0, LEN-1);
        print_int_arr(arr, 0, LEN-1);

        return 0;
}

void merge_sort(int *arr, int p, int r)
{
        int q;
        int myct;

        myct = ct++;

        if (p < r) {
                q = (p + r) / 2;
                merge_sort(arr, p, q);
                merge_sort(arr, q+1, r);

                printf("left: %d  ", myct);
                print_int_arr(arr, p, q);
                printf("right:%d  ", myct);
                print_int_arr(arr, q+1, r);

                merge(arr, p, q, r);
        }
}

void merge(int *arr, int p, int q, int r)
{
        int n1, n2;
        int i, j, k;
        int *left = NULL;
        int *right = NULL;

        n1 = q - p + 1;             // n1 = q - p + 1;
        n2 = r - q;
        left = (int *)malloc(sizeof(int) * (n1+1));
        right = (int *)malloc(sizeof(int) * (n2+1));
        if (left != NULL && right != NULL) {
                for (i = 0; i <= n1; i++)
                        left[i] = arr[p + i - 1];
                for (j = 0; j <= n2; j++)
                        right[j] = arr[q + j];
                for (i = 0, j = 0, k = p; k <= r; k++) {
                        if (left[i] <= right[j])
                                arr[k] = left[i++];
                        else
                                arr[k] = right[j++];
                }
                free(left);
                free(right);
        }
}

void print_int_arr(int *arr, int start, int end)
{
        int i;

        for (i = start; i <= end; i++)
                printf(" %2d ", arr[i]);
        putchar('\n');
}
