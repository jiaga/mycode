/*
 ***************************************************************
 * File Name:    include/base.h
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年01月15日 星期四 21时58分08秒
 ***************************************************************
 */

/* 交换变量宏 */
#define swap_type_of(type, a, b)({      \
                type tmp;               \
                tmp = (a);              \
                (a) = (b);              \
                (b) = tmp;})

