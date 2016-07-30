/*
 ***************************************************************
 * File Name:    test/get_str.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年03月24日 星期二 13时32分15秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "mystring.h"

int main(void)
{
        char *str;

        str = get_string();
        printf("%s\n", str);

        if (str != NULL)
                free(str);

        return 0;
}
