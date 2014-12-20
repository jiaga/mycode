/*
 ***************************************************************
 * File Name:    quicksort.h
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年07月13日 星期日 23时27分44秒
 ***************************************************************
 */
#ifndef __quicksort
#define __quicksort

void swap(int *a, int *b);
int partition(int *arr, int p, int r);
void quicksort(int *arr, int p, int r);

#endif

