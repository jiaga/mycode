/*
 ***************************************************************
 * File Name:    string.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: Mon 16 Feb 2015 09:03:00 AM CST
 ***************************************************************
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"

int main(void)
{
        char *str;

        str = get_str();
        printf("%s\n", str);
        printf("strlen(str): %d\n", strlen(str));

        free(str);
}
