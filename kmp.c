/*
 ***************************************************************
 * File Name:    kmp.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年09月22日 星期一 18时55分56秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

void next(char *p, int *r, int len)
{
        int m = strlen(p);
        int k = 0;
        int q;

        r[0] = 0;

        for (q = 1; q < m; q++) {
                while (k > 0 && p[k] != p[q])
                        k = r[k-1];
                if (p[k] == p[q])
                        ++k;
                r[q] = k;
        }
}

char * kmp(char *t, char *p)
{
        int n = strlen(t);
        int m = strlen(p);
        int q = 0;
        int i;
        int *r;

        r = (int *)malloc(sizeof(int) * m);
        if (r == NULL)
                return NULL;

        next(p, r, m);

        for (i = 0; i < n; i++) {
                while (q > 0 && p[q] != t[i])
                        /* 获取右移位数 */
                        q = r[q-1];
                if (p[q] == t[i]) {
                        ++q;
                        if (q == m) {
                                free(r);
                                return &t[i-m+1];
                        }
                        else 
                                continue;
                }
                q = r[q];
        }
        free(r);

        return NULL;
}

char* get_str(char* str, int len)
{
        char* find;
        
        if (fgets(str, len, stdin) == NULL) {
                return NULL;
        }
        find = strchr(str, '\n');
        if (find)
                *find = '\0';
        return str;
}

void test_data()
{
        char t[LEN];
        char p[LEN];
        char *find;
        int i;

        printf("Input T: ");
        get_str(t, LEN);
        printf("Input P: ");
        get_str(p, LEN);

        find = kmp(t, p);
        if (find) {
                printf("T: %s\nP: ", t);
                for (i = 0; i < find - t; i++)
                        putchar(' ');
                printf("%s\n", p);
        } else {
                printf("Not found!\n");
        }

        puts("\n\n");
}

int main(void)
{
        while (1)
                test_data();

        return 0;
}
