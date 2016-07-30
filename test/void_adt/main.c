/*
 ***************************************************************
 * File Name:    main.c
 * Declaration:  链表ADT
 *      看书上介绍的ADT好像都只能使用一个固定的类型
 *      如果需要两个不同的类型上都使用链表
 *      需要复制一套ADT并且重命名函数和类型名
 *      感觉很麻烦
 *
 *      一套ADT用在不同的类型上。
 *      试验两种不同的结构类型使用同一个链表ADT部分操作
 *      List pets;              宠物名及种类名 
 *      List points;        坐标X Y 值
 *
 *      链表只管理(void *)指针
 *      用户需要的时候就从链表中取得自己数据的void指针！！！
 *      数据的大小和基本操作是他们自己定义的
 *      用户得到指针后自己决定怎么强制转换取数据来操作
 *      这个方法有用么？？？
 *
 * Author:       jiaga
 * Created Time: 2014年07月26日 星期六 23时07分17秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "pet.h"
#include "point.h"

int main(void)
{
        List pets;
        List points;
        char pet_name[LEN];
        Pet *find;

        init_list(&pets);
        init_list(&points);

        add_to_list_from_fun(&pets, new_pet);
        add_to_list_from_fun(&pets, new_pet);
        add_to_list_from_fun(&points, new_point);
        add_to_list_from_fun(&points, new_point);

        printf("\nList: pets\n");
        traversal(&pets, show_pet);

        printf("\nList: points\n");
        traversal(&points, show_point);

        /*
        printf("Please input pet name to search: ");
        get_string(pet_name);
        find = find_pet(pet_name);
        if (find != NULL)
                printf("pet %s is in the list.\n");
        else
                printf("pet %s is'not in the list.\n");
        */

        del_list(&pets);
        del_list(&points);
        
        return 0;
}
