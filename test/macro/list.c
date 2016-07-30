/*
 *******************************************************************
 * File Name:    list.c
 * Declaration:  支持列表操作的函数
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2013/12/6 10:22:59
 *******************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* 局部函数原型 */
static void CopyToNode(const Item *pitem, Node *pnode);

/* 接口函数 */
/* 把列表设置为空列表 */
void InitializeList(List *plist)
{
        *plist = NULL;
}

/* 如果列表为空则返回真 */
bool ListIsEmpty(const List *plist)
{
        if (*plist == NULL)
                return true;
        else
                return false;
}

/* 如果列表已满则返回真 */
bool ListIsFull(const List *plist)
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

/* 返回节点数 */
unsigned int ListItemCount(const List *plist)
{
        unsigned int count = 0;
        Node *pnode = *plist;           /* 设置到列表的开始处 */

        while (pnode != NULL) {
                ++count;
                pnode = pnode->next;    /* 下一个节点 */
        }

        return count;
}

/* 
 * 创建存放项目的节点
 * 并把它添加到由plist 指向的列表（较慢的实现方法）尾部
 */
bool AddItem(const Item *pitem, List *plist)
{
        Node *pnew;
        Node *scan = *plist;

        pnew = (Node *)malloc(sizeof(Node));
        if (pnew == NULL)
                return false;           /* 失败时退出函数 */

        CopyToNode(pitem, pnew);
        pnew->next = NULL;
        if (scan == NULL)       /* 空列表，因此把 pnew 放在列头 */
                *plist = pnew;
        else {
                while (scan->next != NULL)
                        scan = scan->next;      /* 找到列表结尾 */
                scan->next = pnew;      /* 把 Pnew添加到结尾处 */
        }

        return true;
}

/* 访问每个节点并对他们分别执行由 pfun 指向的函数 */
void Traverse(const List *plist, void (*pfun)(const Item *pitem))
{
        Node *pnode = *plist;            /* 设置到列表的开始处 */
        while (pnode != NULL) {
                (*pfun)(&pnode->item);   /* 把函数作用于列表中的项目 */
                pnode = pnode->next;    /* 前进到下一项           */
        }
}

/* 释放由malloc()分配的内存， 把列表指针设置为 NULL */
void EmptyTheList(List *plist)
{
        Node *psave;
        while (*plist != NULL) {
                psave = (*plist)->next; /* 保存下一个节点的地址 */
                free(*plist);           /* 释放当前节点 */
                *plist = psave;         /* 前进到下一个节点 */
        }
}

/* 局部函数定义 */
/* 把一个项目复制到一个节点中 */
static void CopyToNode(const Item *pitem, Node *pnode)
{
        strcpy(pnode->item.title, pitem->title);     /* 复制结构 */
        pnode->item.rating = pitem->rating;
}

void showsth(void)
{
        printf("lsdkf");
}
