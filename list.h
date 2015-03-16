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
#define TSIZE 45        /* 存放片名的数组大小 */

typedef struct item {
	void * addr;
	size_t len;
}Item;

/* 一般类型定义 */
/* typedef struct film Item; */

typedef struct node {
	Item item;
	struct node * next;
	struct node * prev;
}Node;

typedef Node * List;

/*
 * 函数原型
 * 操作：       初始化一个列表
 * 操作前：     plist 指向一个列表
 * 操作后:      该列表被初始化为空列表
 */
void initialize_list(List * plist);

/*
 * 操作：       确定列表是否为空列表
 * 操作前：     plist 指向一个已初始化的列表
 * 操作后：     如果该列表为空则返回true; 否则返回 false
 */
bool list_is_empty(const List * plist);

/*
 * 操作：       确定列表是否已满
 * 操作前：     plist 指向一个已初始化的列表
 * 操作后：     如果该列表已满则返回 true; 否则返回 false
 */
bool list_is_full(const List *plist);

/*
 * 操作：       确定列表中项目的个数
 * 操作前：     plist 指向一个已初始化的列表
 * 操作后：     返回该列表中项目的个数
 */
unsigned int list_item_count(const List *plist);

/*
 * 操作：       在列表尾部添加一个项目
 * 操作前：     item 是要被增加到列表的项目
 *              plist 是指向一个已初始化的新项目
 * 操作后：     如果可能的话，在类表尾部添加一个新项目，
 *              函数返回 true; 否则返回 false
 */
bool add_item(Item item, List *plist);

/*
 * 操作：       把一个函数作用域列表中的每个项目
 * 操作前：     plist 指向一个已初始化得列表
 *              pfun 指向一个函数，该函数接受一个 Item 参数并且无返回值
 * 操作后：     pfun 指向的函数被作用到列表中的每个项目一次
 */
void traverse(const List *plist, void (*pfun)(Item item));

/*
 * 操作：       释放已分配的内存（如果有）
 * 操作前：     plist 指向一个已初始化的列表
 * 操作后：     为该列表分配的内存已被释放，并且该列表被置为空列表
 */
void empty_the_list(List *plist);

#endif

