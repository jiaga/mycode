/*
 ***************************************************************
 * File Name:    test_sort.c
 * Declaration:  
 *      测试各种排序算法的用时
 *      用法 ./test_sort 100000
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年07月13日 星期日 00时07分13秒
 ***************************************************************
 */

/* new test */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define RAND 0
#define WORST_CASE 1

int get_argv(char** argv, int argc);
int get_input_integer(void);

void init_data          (int* arr,      int n,          int init_type);
void print_int_arr      (int *arr,      int low,        int high);
void test_sort          (int* arr,      int low,        int high);
unsigned long get_sort_time (int* arr, int low, int high, 
                             void (*sort)(int*, int, int));

void swap_int           (int*, int*);

/* 为方便测试 所以将所有排序函数的参数类型及个数统一定义 */
void bubble_sort        (int *arr,      int low,        int high);
void select_sort        (int *arr,      int low,        int high);
void insertion_sort     (int *arr,      int low,        int high);

void merge_sort         (int *arr,      int low,        int high);
void merge              (int *arr,      int low,        
                         int middle,    int high);

int  partition          (int* arr,      int low,        int high);
void quicksort          (int* arr,      int low,        int high);

void HeapAdjust         (int *array,    int i,          int nLength);
void HeapSort           (int *array,    int start,      int end);

/* 计数排序没改成统一的参数样式  单独测试 */
int counting_sort(int *A, int *B, int len, int k);
int cnt_sort(int *A, int *B, int len, int k);

int main(int argc, char **argv)
{
        int* test_data, *B;
        int len;

        struct timeval start;
        struct timeval end;
        unsigned long run_time;


        len = get_argv(argv, argc);
        test_data = (int*)malloc(sizeof(int) * len);
        if (test_data == NULL) {
                printf("malloc() error in main()!\n");
                return -1;
        }

        /*
        init_data(test_data, len, RAND);
        print_int_arr(test_data, 0, len-1);
        init_data(test_data, len, WORST_CASE);
        print_int_arr(test_data, 0, len-1);
        */

        test_sort(test_data, 0, len-1);

        /* test counting sort */
        /* 计数排序不改动原数组，用B数组存储排序好的数据 */
        B = (int*)malloc(sizeof(int) * len);
        if (B == NULL) {
                printf("malloc() error in main()!\n");
                return -1;
        }

        init_data(test_data, len, RAND);
        init_data(B, len, WORST_CASE);
        if (len > 9) {
                print_int_arr(test_data, 0, 9);
                print_int_arr(B, 0, 9);
        }
        gettimeofday(&start, NULL);     /* 获取开始时间 */
        // counting_sort(test_data, B, len, len);
        cnt_sort(test_data, B, len, len);
        gettimeofday(&end, NULL);       /* 获取结束时间 */
        /* 计算时间差(排序函数所用时间) */
        run_time = 1000000 * (end.tv_sec - start.tv_sec) + 
                             (end.tv_usec - start.tv_usec);
        printf("Counting_sort R used: %lu microsecond.\n", run_time);
        if (len > 9) {
                print_int_arr(test_data, 0, 9);
                print_int_arr(B, 0, 9);
        }

        init_data(test_data, len, WORST_CASE);
        init_data(B, len, WORST_CASE);
        if (len >9) {
                print_int_arr(test_data, 0, 9);
                print_int_arr(B, 0, 9);
        }
        gettimeofday(&start, NULL);     /* 获取开始时间 */
        // counting_sort(test_data, B, len, len);
        cnt_sort(test_data, B, len, len);
        gettimeofday(&end, NULL);       /* 获取结束时间 */
        /* 计算时间差(排序函数所用时间) */
        run_time = 1000000 * (end.tv_sec - start.tv_sec) + 
                             (end.tv_usec - start.tv_usec);
        printf("Counting_sort W used: %lu microsecond.\n", run_time);
        if (len > 9) {
                print_int_arr(test_data, 0, 9);
                print_int_arr(B, 0, 9);
        }
        free(B);
        /* 计数排序测试结束 */
        
        free(test_data);

        return 0;
}

int get_input_integer(void)
{
        int n;

        printf("Please input n (n>0): ");
        while (scanf(" %d", &n) != 1 || n <= 0) {
                while (getchar() != '\n')
                        continue;
                printf("Please input n (n>0): ");
        }
        
        return n;
}

int get_argv(char** argv, int argc)
{
        int len;

        if (argc == 2) {
                len = atoi(argv[1]);
                if (len == 0)
                        len = get_input_integer();
        } else if (argc != 2) {
                len = get_input_integer();
        }

        return len;
}

void test_sort(int* arr, int low, int high)
{
        int i;
        unsigned long run_time;

        /* 此数组用于存储各排序函数的指针 */
        void (*sort_func[])(int*, int, int) = {bubble_sort, 
                                              select_sort,
                                              insertion_sort,
                                              merge_sort,
                                              quicksort,
                                              HeapSort
                                              };
        char func_name[][20] = {"Bubble sort", "Select sort",
                                "Insertion sort", "Merge sort", 
                                "Quicksort", "HeapSort"
                                };

        printf("n = %d\n", high+1);
        for (i = 3; i < 6; i++) {       /* i=3 跳过前面时间长的算法 */
                printf("%s\n", func_name[i]);
                init_data(arr, high+1, RAND);         /* 随机数据 */
                printf("Random data: ");
                if (high >=9)
                        print_int_arr(arr, low, 9);
                run_time = get_sort_time(arr, low, high, sort_func[i]);
                if (high >=9)
                        print_int_arr(arr, low, 9);
                printf("%lu microsecond.\n", run_time);

                if (i == 4 )    /* 跳过快排的最坏情况 时间太久了 */
                        continue;
                init_data(arr, high+1, WORST_CASE);   /* 逆序     */
                printf("Worst case : ");
                if (high >=9)
                        print_int_arr(arr, low, 9);
                run_time = get_sort_time(arr, low, high, sort_func[i]);
                if (high >=9)
                        print_int_arr(arr, low, 9);
                printf("%lu microsecond.\n", run_time);
                putchar('\n');
        }
}

unsigned long get_sort_time(int* arr, int low, int high, 
                void (*sort)(int*, int, int))
{
        struct timeval start;
        struct timeval end;
        unsigned long run_time;

        gettimeofday(&start, NULL);     /* 获取开始时间 */
        (*sort)(arr, low, high);        /* 开始排序     */
        gettimeofday(&end, NULL);       /* 获取结束时间 */

        /* 计算时间差(排序函数所用时间) */
        run_time = 1000000 * (end.tv_sec - start.tv_sec) + 
                             (end.tv_usec - start.tv_usec);
        return run_time;
}

void init_data(int* arr, int n, int init_type)
{
        int i = 0;
        int num = n;

        if (init_type == RAND) {                /* 用随机数据初始化 */
                while (i < n)
                        arr[i++] = rand() % n;
        } else if (init_type == WORST_CASE) {   /* 用逆序初始化     */

                while (i < n)
                        arr[i++] = num--;
        } else {
                /* 无变化 */
        }
}

void print_int_arr(int *arr, int start, int end)
{
        int i;

        for (i = start; i <= end; i++)
                printf(" %2d ", arr[i]);
        putchar('\n');
}

void swap_int(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

/* 冒泡排序 */
void bubble_sort(int *arr, int low, int high)
{
        int i;
        int j;

        for (i = low; i < high; i++) {
                for (j = i+1; j <= high; j++) {
                        if (arr[i] > arr[j]) {
                                swap_int(&arr[i], &arr[j]);
                        }
                }
        }
}

/* 选择排序 */
void select_sort(int *arr, int low, int high)
{
        int i;
        int j;
        int k;

        for (i = low; i < high; i++) {
                k = i;
                for (j = i+1; j <= high; j++) {
                        if (arr[k] > arr[j])
                                k = j;
                }
                if (i != k) {
                        swap_int(&arr[i], &arr[k]);
                }
        }
}

/* 插入排序 */
void insertion_sort(int *arr, int low, int high)
{
        int i;
        int j;
        int key;

        for (j = 1; j <= high; j++){
                key = arr[j];
                i = j - 1;
                while (i >= 0 && arr[i] > key) {
                        arr[i+1] = arr[i];
                        --i;
                }
                arr[i+1] = key;
        }
}

/* 归并排序 */
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

void merge(int *arr, int start, int middle, int end)
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
/* 归并排序结束 */

/* 快速排序 */
void quicksort(int *arr, int p, int r)
{
        int q;

        if (p < r) {
                q = partition(arr, p, r);
                quicksort(arr, p, q-1);
                quicksort(arr, q+1, r);
        }
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
                        swap_int(&arr[i], &arr[j]);
                }
        }
        swap_int(&arr[i+1], &arr[j]);

        return i+1;
}
/* 快速排序结束 */

/* 堆排序 */
void HeapAdjust(int *array, int i, int nLength)
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
                        swap_int(&array[i], &array[nChild]);
                else
                        /* 否则退出循环 */
                        break;
        }
}

void HeapSort(int *array, int start, int end)
{
        int i;
        /* 调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素 */
        /* length/2-1是最后一个非叶节点，此处"/"为整除 */
        for(i = (end+1)/2-1; i >= start; --i)
                HeapAdjust(array, i, end+1);
        /* 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素 */
        for(i = end; i > 0; --i)
        {
                /* 把第一个元素和当前的最后一个元素交换， */
                /* 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的 */
                swap_int(&array[0], &array[i]);
                /* 不断缩小调整heap的范围 */
                /* 每一次调整完毕保证第一个元素是当前序列的最大值 */
                HeapAdjust(array, 0, i);
        }
}
/* 堆排序结束 */

/* 计数排序  抄书上的 还没改好 */
int counting_sort(int *A, int *B, int len, int k)
{
        int i, j;
        int *C;

        /* C数组大小是假设原数组数据的最大值+1 */
        C = (int *)malloc(sizeof(int) * (k+1));
        if (C == NULL) {
                puts("error in counting_sort malloc for C");
                return -1;
        }
        for (i = 0; i <= k; i++)
                C[i] = 0;
        for (j = 0; j < len; j++)
                C[A[j]] = C[A[j]] + 1;
        /* C[i] now contains the number of elements equal to i */
        for (i = 0; i <= k; i++)
                C[i] = C[i] + C[i-1];
        /* C[i] now contains the number of elements less than or equal to i */
        for (j = len-1; j > 0; j--) {
                B[C[A[j]]] = A[j];
                C[A[j]] = C[A[j]] - 1;
        }
        free(C);

        return 0;
}
/* 网络上抄的 改下参数就能用…… */
int cnt_sort(int *A, int *B, int len, int k)
{
        int i, value, pos;
        int *C;
        
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
        free(C);

        return 0;
}
