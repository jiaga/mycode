/*
 ***************************************************************
 * File Name:    sort.c
 * Declaration:  
 *      排序函数
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年01月15日 星期四 21时20分36秒
 ***************************************************************
 */

#include <stdlib.h>
#include <stdio.h>
#include "base.h"

/* 冒泡排序 */
void bubble_sort(int *arr, int len)
{
        int i, j;

        for (i = 0; i < len-1; i++) {
                for (j = i+1; j < len; j++) {
                        if (arr[i] > arr[j]) {
                                swap_type_of(int , arr[i], arr[j]);
                        }
                }
        }
}


/* insertion sort */
void insertion_sort(int *arr, int len)
{
        int i;
        int j;
        int key;

        for (j = 1; j < len; j++) {
                key = arr[j];
                i = j - 1;
                while (i >= 0 && arr[i] > key) {
                        arr[i+1] = arr[i];
                        --i;
                }
                arr[i+1] = key;
        }
}

/* 选择排序 */
void select_sort(int *arr, int len)
{
        int i;
        int j;
        int k;

        for (i = 0; i < len-1; i++) {
                k = i;
                for (j = i+1; j < len; j++) {
                        if (arr[k] > arr[j])
                                k = j;
                }
                if (i != k) {
                        swap_type_of(int, arr[i], arr[k]);
                }
        }
}

/* quicksort */
static int partition(int *arr, int p, int r)
{
        int x;
        int i;
        int j;

        x = arr[r];
        i = p-1;

        for (j = p; j <= r-1; j++) {
                if (arr[j] <= x) {
                        ++i;
                        swap_type_of(int, arr[i], arr[j]);
                }
        }
        swap_type_of(int, arr[i+1], arr[j]);

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


/* 归并排序 */
static void merge(int *arr, int start, int middle, int end)
{
        int i = start;
        int j = middle + 1;
        int p = 0;

        int *tmp;

        /* 申请临时空间以存储排序好的左右部分 */
        tmp = (int *)malloc((end - start + 1) * sizeof(int));
        if (tmp != NULL) {

                /* 左或右部分较小的值逐个存入tmp数组中 */
                while (i <= middle && j <= end){
                        if (arr[i] <= arr[j])
                                tmp[p++] = arr[i++];
                        else
                                tmp[p++] = arr[j++];
                }

               /* 剩余部分存入tmp数组尾部 */
                while (i <= middle)
                        tmp[p++] = arr[i++];
                while (j <= end)
                        tmp[p++] = arr[j++];

               /* 已合并好的有序的左右部分存回原数组 */
                for (p = 0, i = start; i <= end; p++, i++)
                        arr[i] = tmp[p];
                free(tmp);
        } else
                printf("malloc() error in merge()!\n");
}

void merge_sort(int *arr, int start, int end)
{
        int middle;

        if (start < end) {
                middle = (start + end) / 2;
                merge_sort(arr, start, middle);
                merge_sort(arr, middle+1, end);
                merge(arr, start, middle, end);
        }
}
/* 归并排序结束 */

/* 堆排序 */
static void HeapAdjust(int *array, int i, int nLength);
void HeapSort(int *array, int len)
{
        int i;
        /* 调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素 */
        /* length/2-1是最后一个非叶节点，此处"/"为整除 */
        for(i = len/2-1; i >= 0; --i)
                HeapAdjust(array, i, len);
        /* 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素 */
        for(i = len-1; i > 0; --i)
        {
                /* 把第一个元素和当前的最后一个元素交换， */
                /* 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的 */
                swap_type_of(int, array[0], array[i]);
                /* 不断缩小调整heap的范围 */
                /* 每一次调整完毕保证第一个元素是当前序列的最大值 */
                HeapAdjust(array, 0, i);
        }
}

static void HeapAdjust(int *array, int i, int nLength)
{
        int nChild;

        for( ; 2*i+1<nLength; i=nChild) {
                /* 子结点的位置=2*（父结点位置）+1 */
                nChild = 2*i+1;
                /* 得到子结点中较大的结点 */
                if(nChild < nLength-1 && array[nChild+1] > array[nChild])
                        ++nChild;
                /* 如果较大的子结点大于父结点那么把较大的子结点往上移动 */
                /* 替换它的父结点 */
                if(array[i] < array[nChild])
                        swap_type_of(int, array[i], array[nChild]);
                else
                        /* 否则退出循环 */
                        break;
        }
}
/* 堆排序结束 */

/* 计数排序 */
int counting_sort(int *A, int len, int max_value)
{
        int i, j;
        int *B, *C;

        /* B数组存储结果 */
        B = (int*)malloc(sizeof(int) * len);
        if (B == NULL) {
                puts("error in counting_sort malloc for B");
                return -1;
        }
        /* C数组大小是假设原数组数据的最大值+1 */
        C = (int *)malloc(sizeof(int) * (max_value+1));
        if (C == NULL) {
                puts("error in counting_sort malloc for C");
                return -1;
        }
        for (i = 0; i <= max_value; i++)
                C[i] = 0;
        for (j = 0; j < len; j++)
                C[A[j]] = C[A[j]] + 1;
        /* C[i] now contains the number of elements equal to i */
        for (i = 0; i <= max_value; i++)
                C[i] = C[i] + C[i-1];
        /* C[i] now contains the number of elements less than or equal to i */
        for (j = len-1; j >= 0; j--) {
                B[C[A[j]]] = A[j];
                C[A[j]] = C[A[j]] - 1;
        }

        /* 将结果转给源数组 */
        for(i = 0; i < len; i++)
                A[i] = B[i];
        free(B);
        free(C);

        return 0;
}

/* 网络上抄的 改下参数就能用…… */
int cnt_sort(int *A, int len, int k)
{
        int i, value, pos;
        int *B, *C;
        
        /* B数组存储结果 */
        B = (int*)malloc(sizeof(int) * len);
        if (B == NULL) {
                puts("error in counting_sort malloc for B");
                return -1;
        }
        /* C数组大小是假设原数组数据的最大值+1 */
        C = (int *)malloc(sizeof(int) * (k+1));
        if (C == NULL) {
                puts("error in counting_sort malloc for C");
                return -1;
        }
        for(i=0; i<=k; i++) {
                C[i] = 0;
        }
        for(i=0; i< len; i++) {
                C[A[i]] ++;
        }
        for(i=1; i<=k; i++) {
                C[i] = C[i] + C[i-1];
        }
        for(i=len-1; i>=0; i--) {
                value = A[i];
                pos = C[value];
                B[pos-1] = value;
                C[value]--;
        }
        /* 将结果转给源数组 */
        for(i = 0; i < len; i++)
                A[i] = B[i];
        free(B);
        free(C);

        return 0;
}
