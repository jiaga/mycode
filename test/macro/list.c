/*
 *******************************************************************
 * File Name:    list.c
 * Declaration:  ֧���б�����ĺ���
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2013/12/6 10:22:59
 *******************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* �ֲ�����ԭ�� */
static void CopyToNode(const Item *pitem, Node *pnode);

/* �ӿں��� */
/* ���б�����Ϊ���б� */
void InitializeList(List *plist)
{
        *plist = NULL;
}

/* ����б�Ϊ���򷵻��� */
bool ListIsEmpty(const List *plist)
{
        if (*plist == NULL)
                return true;
        else
                return false;
}

/* ����б������򷵻��� */
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

/* ���ؽڵ��� */
unsigned int ListItemCount(const List *plist)
{
        unsigned int count = 0;
        Node *pnode = *plist;           /* ���õ��б�Ŀ�ʼ�� */

        while (pnode != NULL) {
                ++count;
                pnode = pnode->next;    /* ��һ���ڵ� */
        }

        return count;
}

/* 
 * ���������Ŀ�Ľڵ�
 * ��������ӵ���plist ָ����б�������ʵ�ַ�����β��
 */
bool AddItem(const Item *pitem, List *plist)
{
        Node *pnew;
        Node *scan = *plist;

        pnew = (Node *)malloc(sizeof(Node));
        if (pnew == NULL)
                return false;           /* ʧ��ʱ�˳����� */

        CopyToNode(pitem, pnew);
        pnew->next = NULL;
        if (scan == NULL)       /* ���б���˰� pnew ������ͷ */
                *plist = pnew;
        else {
                while (scan->next != NULL)
                        scan = scan->next;      /* �ҵ��б��β */
                scan->next = pnew;      /* �� Pnew��ӵ���β�� */
        }

        return true;
}

/* ����ÿ���ڵ㲢�����Ƿֱ�ִ���� pfun ָ��ĺ��� */
void Traverse(const List *plist, void (*pfun)(const Item *pitem))
{
        Node *pnode = *plist;            /* ���õ��б�Ŀ�ʼ�� */
        while (pnode != NULL) {
                (*pfun)(&pnode->item);   /* �Ѻ����������б��е���Ŀ */
                pnode = pnode->next;    /* ǰ������һ��           */
        }
}

/* �ͷ���malloc()������ڴ棬 ���б�ָ������Ϊ NULL */
void EmptyTheList(List *plist)
{
        Node *psave;
        while (*plist != NULL) {
                psave = (*plist)->next; /* ������һ���ڵ�ĵ�ַ */
                free(*plist);           /* �ͷŵ�ǰ�ڵ� */
                *plist = psave;         /* ǰ������һ���ڵ� */
        }
}

/* �ֲ��������� */
/* ��һ����Ŀ���Ƶ�һ���ڵ��� */
static void CopyToNode(const Item *pitem, Node *pnode)
{
        strcpy(pnode->item.title, pitem->title);     /* ���ƽṹ */
        pnode->item.rating = pitem->rating;
}

void showsth(void)
{
        printf("lsdkf");
}
