/*
 ***************************************************************
 * File Name:    quicksort.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年07月0LEN日 星期二 23时1LEN分57秒
 ***************************************************************
 */

#include <stdio.h>

#define LEN 16

#define __swap(type, a, b)      \
                type tmp;       \
                tmp = (a);      \
                (a) = (b);      \
                (b) = tmp; 

void swap(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

int partition(int *arr, int p, int r)
{
        int x;
        int i;
        int j;

        x = arr[r];
        i = p-1;

        for (j = p; j <= r-1; j++) {
                if (arr[j] <= x) {
                        ++i;
                        swap(&arr[i], &arr[j]);
                }
        }
        swap(&arr[i+1], &arr[j]);

        return i+1;
}

void quicksort(int *arr, int p, int r)
{
        int q;

        if (p < r) {
                q = partition(arr, p, r);
                quicksort(arr, p, q-1);
                quicksort(arr, q+1, r);
        }
}

int main(void)
{
        // int arr[LEN] = {2, 8, 7, 1, 3, 5, 6, 4};
        int arr[LEN] = {13, 19, 9, 5, 1, 22, 16, 12, 10, 7, 4, 21, 2, 6, 11, 8};
        int i;

        putchar('\n');
        print_arr(arr, LEN, -1, -1);
        putchar('\n');

        quicksort(arr, 0, LEN-1);

        putchar('\n');
        print_arr(arr, LEN, -1, -1);
        putchar('\n');

        return 0;
}

/*
13  19   9   5  12   8   7   4  21   2   6  11

13  19   9   5  12   8   7   4  21   2   6  11
13  19   9   5  12   8   7   4  21   2   6  11
 9  19  13   5  12   8   7   4  21   2   6  11
 9   5  13  19  12   8   7   4  21   2   6  11
 9   5  13  19  12   8   7   4  21   2   6  11
 9   5   8  19  12  13   7   4  21   2   6  11
 9   5   8   7  12  13  19   4  21   2   6  11
 9   5   8   7   4  13  19  12  21   2   6  11
 9   5   8   7   4  13  19  12  21   2   6  11
 9   5   8   7   4   2  19  12  21  13   6  11
 9   5   8   7   4   2   6  12  21  13  19  11
 9   5   8   7   4   2   6  11  21  13  19  12     s1: partition() == 7
 */
