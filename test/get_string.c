/*
 ***************************************************************
 * File Name:    get_string.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: Wed 04 Feb 2015 04:56:20 PM CST
 ***************************************************************
 */

#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
        char *str1;
        char *str2;
        char *str3;

        printf("input str1: ");
        str1 = get_str();
        printf("input str2: ");
        str2 = get_str();
        printf("input str3: ");
        str3 = get_str();

        printf("\"%s\" len: %d\n", str1, (int)strlen(str1));
        printf("\"%s\" len: %d\n", str2, (int)strlen(str2));
        printf("\"%s\" len: %d\n", str3, (int)strlen(str3));

        free(str1);
        free(str2);
        free(str3);

        return 0;
}
