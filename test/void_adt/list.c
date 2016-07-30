/*
 ***************************************************************
 * File Name:    list.c
 * Declaration:  链表ADT函数
 * Author:       jiaga
 * Created Time: 2014年07月27日 星期日 11时05分16秒
 ***************************************************************
 */

#include <stdlib.h>
#include "list.h"

void init_list(List *list_head)
{
        *list_head = NULL;
}

static void * add_node(List *list_head, void * vp_item)
{
        void *new_item = NULL;
        List_node *new_node;
        List_node *current_node = *list_head;
        new_item = vp_item;
        if (new_item == NULL)
                return NULL;
        new_node = (List_node *)malloc(sizeof(List_node));
        if (new_node == NULL) {
                free(new_item); /* del user data */
                return NULL;
        }
        new_node->vp_item = new_item;
        new_node->next = NULL;
        if (*list_head == NULL) {
                *list_head = new_node;
        } else {
                while (current_node->next != NULL)
                        current_node = current_node->next;
                current_node->next = new_node;
        }

        return new_node;
}

int add_to_list_with_addr(List *list_head, void *vp_item)
{
        if (vp_item == NULL) 
                return -1;
        if (add_node(list_head, vp_item) == NULL)
                return -1;
        else 
                return 0;
}

int add_to_list_from_fun(List *list_head, void *(*new_item_fun)(void))
{
        void *new_item = NULL;
        List_node *new_node;
        List_node *current_node = *list_head;

        new_item = new_item_fun();
        if (new_item == NULL) 
                return -1;
        if (add_node(list_head, new_item) == NULL)
                return -1;
        else 
                return 0;
}

static void __traversal(List *list_head, void (*fun)(void *vp_item))
{
        List_node *current_node = *list_head;

        while (current_node != NULL) {
                fun(current_node->vp_item);
                current_node = current_node->next;
        }
}

void traversal(List *list_head, void (*fun)(void *vp_item))
{
        __traversal(list_head, fun);
}

/*
void *find_node(List *list_head, 
                void *vp_key, 
                int (*cmp)(void *vp_item_in_list, void *vp_key))
{
        List_node * current_node = *list_head;

        while (current_node != NULL) {
                if (cmp(current_node->vp_item, vp_key) != NULL)
                        return current_node->vp_item;
        }

        return NULL;
}
*/

/*
void * del_list_node(List *list_head, int (*cmp)(void *vp_item, void *vp_item))
{

}
*/

static void __del_list(List *list_head)
{
        List_node * current_node = *list_head;
        List_node * tmp;

        while (current_node != NULL) {
                tmp = current_node->next;
                free(current_node->vp_item);    /* 释放用户的数据 */
                free(current_node);             /* 释放当前节点   */
                current_node = tmp;
        }
}

void del_list(List *list_head)
{
        __del_list(list_head);
}
