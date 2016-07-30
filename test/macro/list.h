/*
 *******************************************************************
 * File Name:    list.h
 * Declaration:  ���б����͵�ͷ�ļ�
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2013/12/6 9:53:26
 *******************************************************************
 */

#ifndef LIST_H_
#define LISH_H_
#include <stdbool.h>

/* �ض��ڳ�������� */
#define TSIZE 45        /* ���Ƭ���������С */

struct film {
        char title[TSIZE];
        int rating;
};

/* һ�����Ͷ��� */
typedef struct film Item;

typedef struct node {
        Item item;
        struct node * next;
}Node;

typedef Node * List;

/*
 * ����ԭ��
 * ������       ��ʼ��һ���б�
 * ����ǰ��     plist ָ��һ���б�
 * ������:      ���б���ʼ��Ϊ���б�
 */
void InitializeList(List * plist);

/*
 * ������       ȷ���б��Ƿ�Ϊ���б�
 * ����ǰ��     plist ָ��һ���ѳ�ʼ�����б�
 * ������     ������б�Ϊ���򷵻�true; ���򷵻� false
 */
bool ListIsEmpty(const List * plist);

/*
 * ������       ȷ���б��Ƿ�����
 * ����ǰ��     plist ָ��һ���ѳ�ʼ�����б�
 * ������     ������б������򷵻� true; ���򷵻� false
 */
bool ListIsFull(const List *plist);

/*
 * ������       ȷ���б�����Ŀ�ĸ���
 * ����ǰ��     plist ָ��һ���ѳ�ʼ�����б�
 * ������     ���ظ��б�����Ŀ�ĸ���
 */
unsigned int ListItemCount(const List *plist);

/*
 * ������       ���б�β�����һ����Ŀ
 * ����ǰ��     item ��Ҫ�����ӵ��б����Ŀ
 *              plist ��ָ��һ���ѳ�ʼ��������Ŀ
 * ������     ������ܵĻ��������β�����һ������Ŀ��
 *              �������� true; ���򷵻� false
 */
bool AddItem(const Item *pitem, List *plist);

/*
 * ������       ��һ�������������б��е�ÿ����Ŀ
 * ����ǰ��     plist ָ��һ���ѳ�ʼ�����б�
 *              pfun ָ��һ���������ú�������һ�� Item ���������޷���ֵ
 * ������     pfun ָ��ĺ��������õ��б��е�ÿ����Ŀһ��
 */
void Traverse(const List *plist, void (*pfun)(const Item *pitem));

/*
 * ������       �ͷ��ѷ�����ڴ棨����У�
 * ����ǰ��     plist ָ��һ���ѳ�ʼ�����б�
 * ������     Ϊ���б������ڴ��ѱ��ͷţ����Ҹ��б���Ϊ���б�
 */
void EmptyTheList(List *plist);

void showsth(void);

#endif
