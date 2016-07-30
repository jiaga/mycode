/*
 ***************************************************************
 * File Name:    list.h
 * Declaration:  
 * Author:       jiaga
 * Created Time: 2014年07月27日 星期日 11时02分11秒
 ***************************************************************
 */

#ifndef __LIST_H
#define __LIST_H

typedef struct list_node{
        void * vp_item;
        struct list_node * next;
}List_node;

typedef List_node * List;

void init_list(List *list_head);

List_node * add_to_list(List *list_head, void *(*new_item)(void));

void show_list(List *list_head, void (*traverse)(void *vp_item));

/* 释放链表所用存储空间 */
void del_list(List *list_head);

#endif
