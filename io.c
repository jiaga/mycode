/*
 ***************************************************************
 * File Name:    io.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年01月09日 星期五 23时28分18秒
 ***************************************************************
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 获取INT类型整数输入 */
int get_interger(void)
{
        int i;

        while (scanf(" %d", &i) != 1) {
                while(getchar() != '\n')
                        continue;
                printf("\nPlease reenter: ");
        }

        return i;
}

/* 获取INT类型整数输入 */
double get_float(void)
{
        double df;

        while (scanf(" %f", &df) != 1) {
                while(getchar() != '\n')
                        continue;
                printf("\nPlease reenter: ");
        }

        return df;
}

/* 从标准输入获取 len-1 数量的字符输入存储于str,结尾为'\0' */
char *get_string(char *str, int len)
{
        char *tmp;
        char *find_end = NULL;

        tmp = (char *)malloc(len);
        if (tmp == NULL)
                return NULL;
        if ( fgets(tmp, len, stdin) != NULL) {
                find_end = strchr(tmp, '\n');
                if (find_end != NULL) {
                        *find_end = '\0';
                }
                strncpy(str, tmp, len);
                free(tmp);
                return str;
        } else {
                free(tmp);
                return NULL;
        }
}
<<<<<<< HEAD

int getline(char * str, int len)
{
        int i = 0;
        char ch;

        while (--len > 0 && (ch = getchar()) != 'EOF' && ch != '\n')
                str[i++] = ch;
        if (ch == '\n')
                str[i++] = ch;
        str[i] = '\0';

        return i;
}
=======
>>>>>>> a14ae4ad73146e8dad19bfb3cb56337dc1d72541
