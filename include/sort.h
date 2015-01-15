/*
 ***************************************************************
 * File Name:    include/sort.h
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年01月15日 星期四 22时23分12秒
 ***************************************************************
 */

void bubble_sort(int *arr, int len);
void insertion_sort(int *arr, int len);
void quicksort(int *arr, int p, int r);
void merge_sort(int *arr, int start, int end);
void HeapSort(int *array, int start, int end);
int counting_sort(int *arr, int len, int max_value);
int cnt_sort(int *A, int len, int k);
