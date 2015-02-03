/*
 ***************************************************************
 * File Name:    heap_sort.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年11月01日 星期六 23时06分10秒
 ***************************************************************
 */

#include "base.h"

static int parent(int i)
{
        return i / 2;
}

static int left(int i)
{
        return i * 2;
}

static int right(int i)
{
        return i * 2 + 1;
}

static void max_heapify(int *A, int i, const int heap_size)
{
        int l, r;
        int largest;

        l = left(i);
        r = right(i);

        if (l < heap_size && A[l] > A[i])
                largest = l;
        else
                largest = i;
        if (r < heap_size && A[r] > A[largest])
                largest = r;
        if (largest != i) {
                swap_type_of(int, A[i], A[largest]);
                max_heapify(A, largest, heap_size);
        }
}

static void build_max_heap(int *A, int n)
{
        int i;

        for (i = n/2; i >= 0; i--)
                max_heapify(A, i, n);
}

/***************************/
void heap_sort(int *A, int n)
{
        int i;
        int heap_size = n;;

        build_max_heap(A, n);
        for (i = n-1; i > 0; i--) {
                swap_type_of(int, A[0], A[i]);
                heap_size--;
                max_heapify(A, 0, heap_size);
        }
}

static int heap_maxmum(int *A, int n)
{
        return A[0];
}

static int heap_extract_max(int *A, int n, int heap_size)
{
        int max;

        if (heap_size < 0) {
                puts("Error: Underflow in heap_extract_max()");
                return -1;
        }
        max = A[0];
        A[0] = A[heap_size];
        --heap_size;
        max_heapify(A, 0, heap_size);
        return max;
}

/* 更新关键字 在下标i之后*/
static void heap_increase_key(int *A, int i, int key)
{
        if (key < A[i]) {
                puts("Error: new key is smaler than current key");
        } else {
                A[i] = key;
                while (i > 0 && A[parent(i)] < A[i]) {
                        swap_type_of(int, A[i], A[parent(i)]);
                        i = parent(i);
                }
        }
}

/*
static void max_heap_insert(int *A, int heap_size, int key)
{
        heap_size++;
        A[heap_size] = -oo;
        heap_increase_key(A, heap_size, key);
}
*/
