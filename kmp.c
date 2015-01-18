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

static void next(char *p, int *r, int len)
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
