/*
 ***************************************************************
 * File Name:    list.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年02月03日 星期二 17时06分47秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void copy_to_node(Item item, Node *pnode);

void initialize_list(List *plist)
{
        *plist = NULL;
}

bool list_is_empty(const List *plist)
{
        if (*plist == NULL)
                return true;
        else
                return false;
}

bool list_is_full(const List *plist)
{
        Node *pt = NULL;
        bool full;

        pt = (Node *)malloc(sizeof(Node));
        if (pt == NULL)
                full = true;
        else {
                full = false;
                free(pt);
        }

        return full;
}

unsigned int list_item_count(const List *plist)
{
        unsigned int count = 0;
        Node *pnode = *plist;           /* 设置到列表的开始处 */

        while (pnode != NULL) {
                ++count;
                pnode = pnode->next;    /* 下一个节点 */
        }

        return count;
}

bool add_item(Item item, List *plist)
{
        Node *pnew;
        Node *scan = *plist;

        pnew = (Node *)malloc(sizeof(Node));
        if (pnew == NULL)
                return false;           /* 失败时退出函数 */

        copy_to_node(item, pnew);
        pnew->next = NULL;
        pnew->prev = NULL;

        if (scan == NULL)               /* 空列表，因此把 pnew 放在列头 */
                *plist = pnew;
        else {
                while (scan->next != NULL)
                        scan = scan->next;      /* 找到列表结尾 */
                scan->next = pnew;      /* 把 Pnew添加到结尾处 */
        }

        return true;
}

void traverse(const List *plist, void (*pfun)(Item item))
{
        Node *pnode = *plist;            /* 设置到列表的开始处 */
        while (pnode != NULL) {
                (*pfun)(pnode->item);   /* 把函数作用于列表中的项目 */
                pnode = pnode->next;    /* 前进到下一项           */
        }
}

void empty_the_list(List *plist)
{
        Node *psave;
        while (*plist != NULL) {
                psave = (*plist)->next; /* 保存下一个节点的地址 */
                free(*plist);           /* 释放当前节点 */
                *plist = psave;         /* 前进到下一个节点 */
        }
}

static void copy_to_node(Item item, Node *pnode)
{
        pnode->item = item;             /* 复制结构 */
}

