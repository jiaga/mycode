/*
 ***************************************************************
 * File Name:    dblist.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年03月23日 星期一 17时39分32秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dblist.h"

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

static list_node_t * __insert_head(list_node_t *head, list_node_t *new_node)
{
        new_node->next = head->next;
        head->next->prev = new_node;
        head->next = new_node;
        new_node->prev = head;
}

static list_node_t * __insert_tail(list_node_t *head, list_node_t *new_node)
{
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        new_node->next = head;
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
                printf("Data is not in list!\n");
                return -1;
        } else {
                __delete_node(find);
                if (find->user_data != NULL)
                        free(find->user_data);
                if (find != NULL)
                        free(find);
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
        if (find == list->head) {
                __insert_tail(list->head, new_node);
                return -1;
        }
        __insert_head(find, new_node);
}

extern int list_insert_before(list_t *list, cmp_func_t cmp_func, void *key, void *user_data)
{
        list_node_t *find;
        list_node_t *new_node;

        new_node = __alloc_node(list, user_data);
        if (new_node == NULL)
                return -1;

        find = __search_bwd(list->head, cmp_func, key);
        if (find == list->head) {
                __insert_head(list->head, new_node);
                return -1;
        }
        __insert_tail(find, new_node);
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

extern int list_insert_head(list_t *list, void *user_data)
{
        list_node_t *new_node;

        new_node = __alloc_node(list, user_data);
        if (new_node == NULL)
                return -1;

        __insert_head(list->head, new_node);
        list->cnt++;
}

extern int list_insert_tail(list_t *list, void *user_data)
{
        list_node_t *new_node;

        new_node = __alloc_node(list, user_data);
        if (new_node == NULL)
                return -1;

        __insert_tail(list->head, new_node);
        list->cnt++;
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

extern void list_destroy(list_t *list)
{
        __free_all_node(list);
        if (list->head != NULL)
                free(list->head);
        if (list != NULL)
                free(list);
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
