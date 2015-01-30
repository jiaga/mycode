/*
 ***************************************************************
 * File Name:    triangle.c
 * Declaration:  
 *          有n根棍子，棍子i的长度为a[i]。想要从中选出3根棍子组成
 *      周长尽可能长的三角形。请输出最大得周长。若无法组成三角形则
 *      输出0.
 *
 *      最长棍子的长度 < 其余两根棍子的长度之和
 *
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年01月28日 星期三 22时22分46秒
 ***************************************************************
 */

#include <stdio.h>
#include "base.h"
#include "io.h"

#define MAX_N 100

int main(void)
{
        int n = 0;
        int a[MAX_N];
        int ans = 0;
        int i, j, k;
        int max;
        int total_len;
        int short_len;
        int ckg[3] = {0};

        while (n > MAX_N || n < 3)
                n = get_interger();
        for (i = 0; i < n; i++)
                a[i] = get_interger();
        for (i = 0; i < n; i++) {
                for (j = i+1; j < n; j++) {
                        for (k = j+1; k < n; k++) {
                                total_len = a[i] + a[j] + a[k];
                                max = max_value_between(a[i], max_value_between(a[j], a[k]));
                                short_len = total_len - max;

                                if (max < short_len) {
                                        ans = max_value_between(ans, total_len);
                                        ckg[0] = i;
                                        ckg[1] = j;
                                        ckg[2] = k;

                                }
                        }
                }
        }

        printf("Max: %d %d %d  len: %d\n", ckg[0], ckg[1], ckg[2], ans);

        return 0;
}
