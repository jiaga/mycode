/*
 ***************************************************************
 * File Name:    test/test_macro.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年01月15日 星期四 21时29分08秒
 ***************************************************************
 */

#include <stdio.h>

/* 交换变量宏 */
#define swap_type_of(type, a, b)({      \
                type tmp;               \
                tmp = (a);              \
                (a) = (b);              \
                (b) = tmp;})


int main(void)
{
        int x, y;
        float f1, f2;

        x = 1;
        y = 2;
        f1 = 12.34;
        f2 = 56.78;

        printf("x=%d  y=%d\n", x, y);
        swap_type_of(int, x, y);
        printf("x=%d  y=%d\n", x, y);
        
        printf("f1=%f  f2=%f\n", f1, f2);
        swap_type_of(float, f1, f2);
        printf("f1=%f  f2=%f\n", f1, f2);

        return 0;
}
