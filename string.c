/*
 ***************************************************************
 * File Name:    string.c
 * Declaration:  
 *      获取不定长字符串输入，返回字符串指针。
 *      起始设置一个定长的空间，若输入满了还没遇见换行符则继续申请
 *      空间继续读取输入,并将已读取的内容加入链表。最后将链表中所有
 *      字符串链接起来。
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年02月03日 星期二 14时18分00秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRIOBUF 10

typedef struct mystring {
        char str[STRIOBUF];
        struct mystring * next;
}Str_node;
typedef Str_node *Str_list;

static int add_to_list(Str_list *s_list, char *new_str)
{
        Str_node *new_node;
        Str_node *tmp = *s_list;

        new_node = (Str_node *)malloc(sizeof(Str_node));
        if (new_node == NULL)
                return -1;
        strcpy(new_node->str, new_str);
        new_node->next = NULL;
        if (*s_list == NULL)
                *s_list = new_node;
        else {
                while (tmp->next != NULL) {
                        tmp = tmp->next;
                }
                tmp->next = new_node;
        }

        return 0;
}

static void get_str_input(Str_list *s_list)
{
        int i = 0;
        char str[STRIOBUF];
        char ch;

        while ((ch = getchar()) != '\n') {
                str[i++] = ch;
                if (i == STRIOBUF-1) {
                        str[i] = '\0';
                        add_to_list(s_list, str);
                        i = 0;
                } else
                        continue;
        }
        str[i] = '\0';
        add_to_list(s_list, str);
}

static void free_list(Str_list *s_list)
{
        Str_node *tmp, *c_node;

        c_node = *s_list;
        while (c_node != NULL) {
                tmp = c_node->next;
                free(c_node);
                c_node = tmp;
        }
        *s_list = NULL;
}

static void merge_str(Str_list *s_list, char *str)
{
        Str_node *c_node;

        c_node = *s_list;
        while (c_node != NULL) {
                strcat(str, c_node->str);
                c_node = c_node->next;
        }
}

static void InitializeList(Str_list *s_list)
{
        *s_list = NULL;
}
char * get_str(void)
{
        char *str;
        int len = 0;

        Str_list s_list;
        Str_node *c_node;

        InitializeList(&s_list);

        get_str_input(&s_list);
        c_node= s_list;
        while (c_node != NULL) {
                len += strlen(c_node->str);
                c_node = c_node->next;
        }

        /* 最终的字符串存储空间 */
        str = (char *)malloc(len+1);
        if (str == NULL) {
                free_list(&s_list);
                return NULL;
        }
        merge_str(&s_list, str);       
        free_list(&s_list);
        str[len] = '\0';

        return str;
}
