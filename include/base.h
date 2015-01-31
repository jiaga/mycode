/*
 ***************************************************************
 * File Name:    include/base.h
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年01月15日 星期四 21时58分08秒
 ***************************************************************
 */

#ifndef _BASE_H_
#define _BASE_H_

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

/* 交换变量宏 */
#define swap_type_of(type, a, b)({      \
                type tmp;               \
                tmp = (a);              \
                (a) = (b);              \
                (b) = tmp;})


#define max_value_between(a, b) ((a) > (b) ? (a) : (b))

int printf_arr(int *arr, int start, int end);

#endif
