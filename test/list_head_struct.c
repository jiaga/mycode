/*
 ***************************************************************
 * File Name:    list_head_struct.c
 * Declaration:  
 *      linux 内核中的链表操作
 *      struct lish_head 双向链表结构
 *      链表结构中不包含用户数据结构，而是用户数据结构包含链表结构
 *      可以在一个链表中有不同的数据类型
 *      也可以不同的数据类型链表中用同一套链表操作函数
 *      而不需要根据不同类型做多一套链表函数
 *      主要由宏实现
 *      list_entry() 宏返回节点的宿主结构指针
 *
 *      c学习理解：
 *      value = ({代码段});
 *      value = 代码段中最后一个语句的值???
 *      windows系统下不能编译……
 *      相当于汇编里 ax eax rax 寄存器传值???
 *
 *      这个程序用同一套宏或函数操作两个不同的用户自定义结构
 *      Point 坐标X Y
 *      Pet   宠物名及类型
 *
 *      1: 输入3个坐标加入坐标链表
 *      2: 输入3个宠物加入宠物链表
 *      3: 输出两个链表内容
 *      4: 释放所用内存空间
 *
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年09月21日 星期日 11时09分14秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 20

/* linux 中不使用的内存地址？？？ 用于初始化？？？ */
#define POISON_POINTER_DELTA 0
#define LIST_POISON1  ((void *) 0x00100100 + POISON_POINTER_DELTA)
#define LIST_POISON2  ((void *) 0x00200200 + POISON_POINTER_DELTA)

/** 
 * 声明并初始化循环链表头，前后都指向自己
 * 亚节点，实际表起始位置 head->next
 */
#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
        struct list_head name = LIST_HEAD_INIT(name)

/* 用于从链表节点指针取得宿主结构类型的指针 */
#define offsetof(type, member) ((size_t)&((type *)0)->member)

#define container_of(ptr, type, member) ({                              \
                const __typeof( ((type*)0)->member ) *__mptr = (ptr);   \
                (type *)( (char *)__mptr - offsetof(type, member) );})  \

#define list_entry(ptr, type, member) \
        container_of(ptr, type, member)

/* 遍历链表 */
#define list_for_each(pos, head) \
        for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_for_each_safe(pos, n, head) \
        for (pos = (head)->next, n = pos->next; \
                        pos != (head);          \
                        pos = n, n = pos->next)

struct list_head {
        struct list_head *next, *prev;
};

/* 用户数据结构 将list_head 嵌入其中 */
/* 坐标 */
typedef struct point {
        struct list_head point_node;
        float x;
        float y;
}Point;

/* 宠物名及类型 */
typedef struct pet {
        struct list_head pet_node;
        char name[LEN];
        char kind[LEN];
}Pet;

void INIT_LIST_HEAD(struct list_head *list)
{
        list->next = list;
        list->prev = list;
}

static void __list_add(struct list_head *new,
                struct list_head *prev,
                struct list_head *next)
{
        next->prev = new;
        new->next = next;
        new->prev = prev;
        prev->next = new;
}

void list_add(struct list_head *new,
              struct list_head *head)
{
        __list_add(new, head, head->next);
}

static void __list_del(struct list_head *prev,
                       struct list_head *next)
{
        next->prev = prev;
        prev->next = next;
}

void list_del(struct list_head *entry)
{
        __list_del(entry->prev, entry->next);
        entry->next = NULL;
        entry->prev = NULL;
        /* 
        entry->next = LIST_POISON2;
        entry->prev = LIST_POISON2;
        */
}

/* user for debug, print addr msg */
void print_node_addr(struct list_head *head)
{
        printf("curr: %p  next: %p  prev: %p\n", 
                        head, 
                        head->next, 
                        head->prev);
}

Point* new_point()
{
        Point *point;

        point = (Point *)malloc(sizeof(Point));
        printf("Please input x and y: ");
        scanf(" %f %f", &point->x, &point->y);

        INIT_LIST_HEAD(&point->point_node);

        return point;
}

Pet* new_pet()
{
        Pet *pet;

        pet = (Pet *)malloc(sizeof(Pet));
        printf("Please input pet name: ");
        scanf("%s", pet->name);
        printf("Please input pet kind: ");
        scanf("%s", pet->kind);

        INIT_LIST_HEAD(&pet->pet_node);

        return pet;
}

int main(void)
{
        LIST_HEAD(points);              /* 声明链表头结点            */
        LIST_HEAD(pets);                /* 声明链表头结点            */

        /* 这两个可以通用,相当于for循环中的i, 为了看得明白多声明一个 */
        struct list_head *point;        /* 遍历索引                  */
        struct list_head *pet;          /* 遍历索引                  */

        struct list_head *tmp; /* 用于释放节点时临时保存下一节点的指针 */

        Point *c_point;                 /* 用于操作用户数据类型      */
        Pet *c_pet;                     /* 用于操作用户数据类型      */

        int i;
        
        /* 创建新结点并获取输入 */
        for (i = 0; i < 3; i++) {
                c_point = new_point();                   /* 获取输入 */
                list_add(&c_point->point_node, &points); /* 加入链表 */
        }
        for (i = 0; i < 3; i++) {
                c_pet = new_pet();                       /* 获取输入 */
                list_add(&c_pet->pet_node, &pets);       /* 加入链表 */
        }
        
        list_for_each(point, &points) {
                c_point = list_entry(point, Point, point_node);
                printf("x = %.2f  y = %.2f\n", c_point->x, c_point->y);
        }

        list_for_each(pet, &pets) {
                c_pet = list_entry(pet, Pet, pet_node);
                printf("name: %-10s  kind: %-10s\n", 
                                c_pet->name, c_pet->kind);
        }

        /* 从points链表中删除节点并释放内存空间 */
        list_for_each_safe(point, tmp, &points) {
                c_point = list_entry(point, Point, point_node);
                list_del(point);
                free(c_point);
        }

        /*
         * 不用list_for_each_safe宏的删除操作
        point = points.next;
        while (point != &points) {
                tmp = point->next;
                c_point = list_entry(point, Point, point_node);
                list_del(point);
                point = tmp;
                free(c_point);
        }
        */

        /* 删除 pets 链表节点 */
        pet = pets.next;
        while (pet!= &pets) {
                tmp = pet->next;
                c_pet = list_entry(pet, Pet, pet_node);
                list_del(pet);
                pet = tmp;
                free(c_pet);
        }

        return 0;
}
