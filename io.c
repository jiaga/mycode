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

int getline(void)
{
        int cnt = 0;

        while (getchar() != '\n') {
                
        }
}

#define STR_NODE_LEN 1024
typedef struct string{
        char *str;
        struct string *next;
}String;

String * get_str_node(String *s_node)
{
        s_node->str = (char *)malloc(STR_NODE_LEN);
        if (str == NULL)
                return NULL;
        while (get_string(str_node.str, STR_NODE_LEN) != NULL)
                add_to_list();
        return s_node;
}

char * get_cs(void)
{
        char *str;
        chr ch;


        while ((ch = getchar()) != EOF) {
                
        }
}
