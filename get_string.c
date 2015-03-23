/*
 ***************************************************************
 * File Name:    get_s.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年03月23日 星期一 20时10分32秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dblist.h"

#define STRLEN 100

void *alloc_str(void)
{
        return malloc(STRLEN);
}

void print_str(void *str)
{
        printf("%s\n", (char *)str);
}

/* 
 * 获取不定长度输入，遇到‘\n' 或 EOF 结束输入 
 * 返回字符串得指针
 * */
char * get_string()
{
        char s[STRLEN];
        char *str;
        char ch;
        int cnt = 0;
        int len;
        list_t *list;

        list = new_list(alloc_str, STRLEN);
        while ((ch = getchar()) != '\n' && ch != EOF) {
                s[cnt++] = ch;
                if (cnt == STRLEN-1) {
                        s[cnt] = '\0';
                        list_insert_tail(list, s);
                        cnt = 0;
                }
        }
        s[cnt] = '\0';
        len = (list->cnt) * STRLEN;
        len += strlen(s) + 1;
        list_insert_tail(list, s);

        //list_traversal(list, print_str);

        str = (char *)malloc(len);
        if (str == NULL)
                return NULL;
        str[0] = '\0';
        while(!list_is_empty(list)) {
                list_remove_first_node(list, s);
                strcat(str, s);
        }

        list_destroy(list);

        return str;
}

int main(void)
{
        char *str;

        str = get_string();
        printf("%s   len:%d\n", str, (int)strlen(str));

        if (str != NULL)
                free(str);

        return 0;
}
