/*
 ***************************************************************
 * File Name:    list.h
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年02月03日 星期二 17时07分13秒
 ***************************************************************
 */

#ifndef _LIST_H_
#define _LISH_H_
#include <stdbool.h>

/* 特定于程序的声明 */
typedef struct item {
	void * addr;
	size_t len;
}Item;

typedef struct node {
	Item item;
	struct node * next;
	struct node * prev;
}Node;

typedef Node * List;

void initialize_list(List * plist);
bool list_is_empty(const List * plist);
bool list_is_full(const List *plist);
unsigned int list_item_count(const List *plist);
bool add_item(Item item, List *plist);
void traverse(const List *plist, void (*pfun)(Item item));
void empty_the_list(List *plist);

#endif

