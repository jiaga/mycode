/*
 ***************************************************************
 * File Name:    list.c
 * Declaration:  
 *                                                          
 *       +-- --- --- --- --- --- --- --- --- --- --- --- --+
 *       |    sentinel          data            data       |
 *       +->> +-------+  -->> +-------+  -->> +-------+  --+
 * list --->  | head  |       | node1 |       | node2 | 
 *       +--  +-------+ <<--  +-------+ <<--  +-------+ <<-+
 *       |                                                 |
 *       +-- --- --- --- --- --- --- --- --- --- --- --- --+
 *                                                          
 * Author:       jiaga
 * Mail:         jiaga@sina.com
 * Created Time: 2015年03月23日 星期一 17时39分32秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

static list_node_t * __alloc_node(list_t *list, void *user_data);
static list_node_t * __search_bwd(list_node_t *head, cmp_func_t cmp_func, void *key);
static list_node_t * __search_fwd(list_node_t *head, cmp_func_t cmp_func, void *key);
static list_node_t * __delete_node(list_node_t *node);
static void __insert_after(list_node_t *position, list_node_t *new_node);
static void __free_one_node(list_node_t *node);
static void __free_all_node(list_t *list);

static list_node_t * __alloc_node(list_t *list, void *user_data)
{
        list_node_t *new_node;

        new_node = (list_node_t *)malloc(sizeof(list_node_t));
        if (new_node == NULL)
                return NULL;
        new_node->user_data = list->alloc_func();
        if (new_node->user_data == NULL) {
                free(new_node);
                new_node = NULL;
                return NULL;
        }
        memcpy(new_node->user_data, user_data, list->data_len);

        return new_node;
}

/* 两个内存空间分别申请 list   head  */
extern list_t * new_list(data_alloc_func_t alloc_func, size_t data_len)
{
        list_t *list;

        list = (list_t *)malloc(sizeof(list_t));
        if (list == NULL)
                return NULL;
        list->head = (list_node_t *)malloc(sizeof(list_node_t));
        if (list->head == NULL) {
                free(list);
                return NULL;
        }
        list->head->next = list->head;
        list->head->prev = list->head;
        list->data_len = data_len;
        list->cnt = 0;
        list->alloc_func = alloc_func;

        return list;
}

extern int list_is_empty(list_t *list)
{
        if (list->head->next == list->head)
                return 1;
        else
                return 0;
}

static void __insert_after(list_node_t *position, list_node_t *new_node)
{
        new_node->next = position->next;
        position->next->prev = new_node;
        position->next = new_node;
        new_node->prev = position;
}

extern int list_insert_head(list_t *list, void *user_data)
{
        list_node_t *new_node;

        new_node = __alloc_node(list, user_data);
        if (new_node == NULL)
                return -1;

        __insert_after(list->head, new_node);
        list->cnt++;

        return 0;
}

extern int list_insert_tail(list_t *list, void *user_data)
{
        list_node_t *new_node;

        new_node = __alloc_node(list, user_data);
        if (new_node == NULL)
                return -1;

        __insert_after(list->head->prev, new_node);
        list->cnt++;

        return 0;
}

/* 如果找到 返回该节点 否则返回head */
static list_node_t * __search_bwd(list_node_t *head, cmp_func_t cmp_func, void *key)
{
        list_node_t * node;

        node = head->next;
        while (node != head && (cmp_func(key, node->user_data) != 0)) {
                node = node->next;
        }

        return node;
}

static list_node_t * __search_fwd(list_node_t *head, cmp_func_t cmp_func, void *key)
{
        list_node_t * node;

        node = head->prev;
        while (node != head && (cmp_func(key, node->user_data) != 0)) {
                node = node->prev;
        }

        return node;
}

extern int list_search_bwd(list_t *list, cmp_func_t cmp_func, void *key)
{
        list_node_t *find;

        find = __search_bwd(list->head, cmp_func, key);
        if (find == list->head)
                return 0;
        else
                return 1;
}

extern int list_search_fwd(list_t *list, cmp_func_t cmp_func, void *key)
{
        list_node_t *find;

        find = __search_fwd(list->head, cmp_func, key);
        if (find == list->head)
                return 0;
        else
                return 1;
}

static list_node_t * __delete_node(list_node_t *node)
{
        node->prev->next = node->next;
        node->next->prev = node->prev;
}

extern int list_remove_specified(list_t *list, cmp_func_t cmp_func, void *key)
{
        list_node_t *find;

        find = __search_bwd(list->head, cmp_func, key);
        if (find == list->head) {
                printf("Key data is not in list!\n");
                return -1;
        } else {
                __delete_node(find);
                __free_one_node(find);
                list->cnt--;
                return 0;
        }
}

extern int list_modify(list_t *list, cmp_func_t cmp_func, void *key, void *user_data)
{
        list_node_t *find;

        find = __search_bwd(list->head, cmp_func, key);
        if (find == list->head)
                return -1;
        memcpy(find->user_data, user_data, list->data_len);

        return 0;
}

extern int list_insert_after(list_t *list, cmp_func_t cmp_func, void *key, void *user_data)
{
        list_node_t *find;
        list_node_t *new_node;

        new_node = __alloc_node(list, user_data);
        if (new_node == NULL)
                return -1;

        find = __search_bwd(list->head, cmp_func, key);
        if (find == list->head)
                printf("key data is not in list. add data to head.\n");
        __insert_after(find, new_node);
        list->cnt++;

        return 0;
}

extern int list_insert_before(list_t *list, cmp_func_t cmp_func, void *key, void *user_data)
{
        list_node_t *find;
        list_node_t *new_node;

        new_node = __alloc_node(list, user_data);
        if (new_node == NULL)
                return -1;

        find = __search_bwd(list->head, cmp_func, key);
        if (find == list->head)
                printf("key data is not in list. add data to tail.\n");
        __insert_after(find->prev, new_node);
        list->cnt++;

        return 0;
}

extern void list_traversal(list_t *list, traversal_func_t traversal_func)
{
        list_node_t *node;

        node = list->head->next;
        while (node != list->head) {
                traversal_func(node->user_data);
                node = node->next;
        }
}



static void __free_one_node(list_node_t *node)
{
        if (node->user_data != NULL)
                free(node->user_data);
        if (node != NULL)
                free(node);
}

static void __free_all_node(list_t *list)
{
        list_node_t *node;
        list_node_t *tmp;

        node = list->head->next;
        while (node != list->head) {
                tmp = node->next;
                __free_one_node(node);
                node = tmp;
        }
}

extern void list_destroy(list_t **list)
{
        __free_all_node(*list);
        if ((*list)->head != NULL)
                free((*list)->head);
        if (list != NULL)
                free((*list));
        *list = NULL;
}

extern void list_remove_first_node(list_t *list, void *user_data)
{
        list_node_t *node;

        node = list->head->next;
        __delete_node(node);
        memcpy(user_data, node->user_data, list->data_len);
        __free_one_node(node);
}

extern void list_remove_last_node(list_t *list, void *user_data)
{
        list_node_t *node;

        node = list->head->prev;
        __delete_node(node);
        memcpy(user_data, node->user_data, list->data_len);
        __free_one_node(node);
}
