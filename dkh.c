/*
 ***************************************************************
 * File Name:    dkh.c
 * Declaration:  
 *      大括号中 变量作用域只能在有效，
 *      大括号外边再加上括号则：
 *      整个大括号之间的代码块的返回值为最后一条语句的值？？？
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年10月03日 星期五 09时20分01秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

#define get_num(x) ({                     \
                        int e;          \
                        e = (x);        \
                        (int)abs(e);       \
                  })

int main(void)
{
        int a;
        int b;
        int c;

        a = 1;
        b = 2;
        c = ( {
                int c;
                c = ({
                        int d;
                        d = 4;
                        printf("d: %d\n", d);   /* 函数返回值 5 */
                });
                printf("c: %d %p\n", c, &c);           /* 5 */
        } );

        printf("a: %d   b: %d  c: %d %p\n", a, b, c, &c);
        a = get_num(b);
        printf("a: %d   b: %d  c: %d %p\n", a, b, c, &c);

        return 0;
}
