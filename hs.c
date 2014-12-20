/*
 ***************************************************************
 * File Name:    hs.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年11月01日 星期六 23时43分33秒
 ***************************************************************
 */

#include <stdio.h>
#define LEN 10

void maxHeapify(int A[], int lens, int i)
{
        if (A == NULL || i >= lens)
                return;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;
        if (l < lens || A[i] > A[largest])
                largest = l;
        if (r < lens && A[r] > A[largest])
                largest = r;
        if (largest != i)
        {
                int tmp = A[largest];
                A[largest] = A[i];
                A[i] = tmp;
                maxHeapify(A, lens, largest);
        }
}
void buildHeap(int A[], int lens)
{
        int i;

        if (A == NULL || lens <= 0)
                return;
        int mid = (lens-2) / 2;
        for (i = mid; i >= 0; --i)
                maxHeapify(A, lens, i);
}
void heapSort(int A[], int lens)
{
        buildHeap(A, lens);
        while (lens > 1)
        {
                int tmp = A[lens-1];
                A[lens-1] = A[0];
                A[0] = tmp;
                --lens;
                maxHeapify(A, lens, 0);
        }
}
void tranverse(int A[], int lens)
{
        int i;

        if (A == NULL || lens <= 0)
                return;
        for (i = 0; i < lens; ++i)
                printf("%2d ", A[i]);
        putchar('\n');
}

int main()
{
        int A[] = {3, 2, 8, 7, 0, 11};
        int lens = sizeof(A) / sizeof(*A);
        tranverse(A, lens);
        buildHeap(A, lens);
        tranverse(A, lens);
        heapSort(A, lens);
        tranverse(A, lens);
}
