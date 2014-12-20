/*
 ***************************************************************
 * File Name:    heap_sort.h
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年11月01日 星期六 23时06分33秒
 ***************************************************************
 */

void swap(int *a, int *b);

int parent(int i);
int left(int i);
int right(int i);

void max_heapify(int *A, int i, const int heap_size);
void build_max_heap(int *A, int n);
void heap_sort(int *A, int n);

int heap_maxmum(int *A, int n);
int heap_extract_max(int *A, int n, int heap_size);
