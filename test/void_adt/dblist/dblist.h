/*
 ***************************************************************
 * File Name:    dblist.h
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年03月23日 星期一 19时36分37秒
 ***************************************************************
 */

#ifndef __DBLIST_H_
#define __DBLIST_H_

typedef void * (*data_alloc_func_t)(void);
typedef void * (*data_free_func_t)(void *user_data);
typedef int (*cmp_func_t)(void * data1, void *data2);
typedef void (*traversal_func_t)(void * vpdata);

typedef void * element_t;

typedef struct list_node {
        struct list_node *prev;
        struct list_node *next;
        element_t user_data;
}list_node_t;

typedef struct list {
        list_node_t * head;
        size_t data_len;
        size_t cnt;
        data_alloc_func_t alloc_func;
}list_t;

extern list_t * new_list(data_alloc_func_t alloc_func, size_t data_len);
extern int list_is_empty(list_t *list);
extern int list_search_bwd(list_t *list, cmp_func_t cmp_func, void *key);
extern int list_search_fwd(list_t *list, cmp_func_t cmp_func, void *key);
extern int list_remove_specified(list_t *list, cmp_func_t cmp_func, void *key);
extern int list_modify(list_t *list, cmp_func_t cmp_func, void *key, void *user_data);
extern int list_insert_after(list_t *list, cmp_func_t cmp_func, void *key, void *user_data);
extern int list_insert_before(list_t *list, cmp_func_t cmp_func, void *key, void *user_data);
extern void list_traversal(list_t *list, traversal_func_t traversal_func);
extern int list_insert_head(list_t *list, void *user_data);
extern int list_insert_tail(list_t *list, void *user_data);
extern void list_destroy(list_t *list);
extern void list_remove_first_node(list_t *list, void *user_data);
extern void list_remove_last_node(list_t *list, void *user_data);

#endif
